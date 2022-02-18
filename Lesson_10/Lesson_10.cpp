#include <iostream>
#include"File.h"
#include"Log.cpp"
#include<string>
#include<thread>// многопоточность
#include<mutex>// потокобезопасность

using namespace std;

void WritedegreeToFile(int numberDegree, string path)
{
	mutex door;
	door.lock();
	// потокобезопасность
	File::Clear(path);
	string data{ "" };
	for (size_t i = 2, number = 0; i < numberDegree; i *= 2, number++)
	{
		cout << path << endl;
		this_thread::sleep_for(2000ms);
		data = to_string(number) + "^2->" + to_string(i);
		File::Append(data, path);
		cout << "Wrote the data:\t" << data << endl;
	}
	Log::Append("Success", File::GetPath("log.txt"));
	door.unlock();
}

int main()
{
	cout << "Thread count:\t" << thread::hardware_concurrency() << endl;
	//cout << File::GetPath("degree2048.txt") << endl;
	thread th(WritedegreeToFile, 2048, File::GetPath("degree2048.txt"));
	thread th1(WritedegreeToFile, 1024, File::GetPath("degree1024.txt"));
	thread th2(WritedegreeToFile, 4096, File::GetPath("degree4096.txt"));


	//cout << this_thread::get_id() << endl;// get id current thread

	th.join();
	th1.join();
	th2.join();

	system("pause");
	return 0;

}