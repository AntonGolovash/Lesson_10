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
	Log::Append("Success", path);
	door.unlock();
}

int main()
{
	cout << "Thread count:\t" << thread::hardware_concurrency() << endl;

	system("pause");
	return 0;

}