#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mu;
condition_variable pizzaReadyVariable;

void Chef()
{
	while (true)
	{

		this_thread::sleep_for(chrono::seconds(3));

		unique_lock<mutex> ulock(mu);
		cout << "Pizza is ready!" << endl;

		ulock.unlock();
		pizzaReadyVariable.notify_one();
	}


}

void Waiter()
{
	while (true)
	{
		//czeka na pizze
		unique_lock<mutex> ulock(mu);
		pizzaReadyVariable.wait(ulock);

		this_thread::sleep_for(chrono::seconds(1));
		cout << "Deliver pizza to customer by waiter number: " << this_thread::get_id() << endl;

	}
}

int main()
{
	thread task1(Chef);
	thread task2(Waiter);
	thread task3(Waiter);
	thread task4(Waiter);
	thread task5(Waiter);

	task1.join();
	task2.join();
	task3.join();
	task4.join();
	task5.join();


	return 0;
}