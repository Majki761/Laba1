#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <fstream>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mu;
shared_mutex smu;

int Counter = 0;

void Writer()
{
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));
		
		unique_lock<shared_mutex> ulock(smu); //smu.lock(); // exclusive lock - Writer
		
		Counter++;
	}
}

void Reader()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(100));

		shared_lock<shared_mutex> slock(smu); // Reader, smu.shared_lock()

		cout << Counter << endl;
	}
}

int main()
{
	thread task1(Writer);
	thread task2(Reader);
	thread task3(Reader);
	thread task4(Reader);
	thread task5(Reader);

	task1.join();
	task2.join();
	task3.join();
	task4.join();
	task5.join();

	return 0;
}