#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;

void func1()
{
	for (int i = 0; i > -100; i--)
	{
		//mu.lock(); 
		//lock_guard - bezpieczniejszy sposob na korzystanie z mutexow
		
		lock_guard<mutex> lock(mu);  // RAII -> Resource Aquisition Is Initialization
		
		cout << "Thread 1 is counting: " << i << " ,ID: " << this_thread::get_id() << endl;
		
		//mu.unlock();
	}
}

void func2()
{
	for (int i = 0; i < 100; ++i)
	{
		lock_guard<mutex> lock(mu);
		cout << "Thread 2 is counting: " << i << " ,ID: "<< this_thread::get_id() << endl;
		
	}
}

int main()
{
	cout << "Cores: " << thread::hardware_concurrency() << endl; // ile rdzeni ma procesor


	thread t1(func1);
	thread t2(func2);

	t1.join();
	t2.join();

	cout << "Main is running!" << " ,ID: " << this_thread::get_id() << endl;


	return 0;
}