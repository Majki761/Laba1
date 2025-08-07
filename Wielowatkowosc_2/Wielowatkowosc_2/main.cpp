#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile // RAII
{
public:
	LogFile()
	{
		lock_guard<mutex> lock(m_mu);
		m_fs.open("LogFile.txt");
	}

	LogFile(const string& fileName)
	{
		m_fs.open(fileName);
	}

	~LogFile()
	{
		lock_guard<mutex> lock(m_mu);
		m_fs.close();
	}

	void PrintLog(const string& msg, int id)
	{
		unique_lock<mutex> ulock(m_mu);

		int j = 100;
		m_fs << msg << ", ID" << id << endl;
		ulock.unlock();
		
		
		int k = 10 * j;
		k = pow(k, 2);

		ulock.lock();
	}

	void PrintLog2(const string& msg, int id)
	{
		lock(m_mu, m_mu2);
		
		lock_guard<mutex> lock(m_mu, adopt_lock);
		lock_guard<mutex> lock2(m_mu2, adopt_lock);
		
		m_fs << msg << ", ID" << id << endl;
	}

private:
	ofstream m_fs;
	mutex m_mu;
	mutex m_mu2;

};

LogFile g_LogFile;

void Func1()
{
	for (int i = 0; i < 100; ++i)
	{
		g_LogFile.PrintLog("Thred 1 logging", i);
	}


}

void Func2()
{
	for (int i = 0; i < 100; ++i)
	{
		g_LogFile.PrintLog2("Thred 2 logging", -i);
	}


}

int main()
{
	thread task1(Func1);
	thread task2(Func2);

	task1.join();
	task2.join();

	return 0;
}