#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
	int _id{ 0 };
	char _firstname[255];
	char _lastname[255];
};

int main()
{
	const int size = 3;
	Student studentsToFile[size] =
	{
		{1, "studentname1", "studentlastname1"},
		{2, "studentname2", "studentlastname2"},
		{3, "studentname3", "studentlastname3"},
	};

	//int x = 25;
	//[x]
	//{
	//	std::cout << "X = " << x << std::endl;// лямбда выражение
	//};

	for (auto& student : studentsToFile)
		std::cout << student._firstname << std::endl;

	//write
	ofstream fwrite("students.txt", ios_base::binary);
	fwrite.write(reinterpret_cast<char*>(&studentsToFile), sizeof(studentsToFile));
	fwrite.close();
	system("pause");

	return 0;
}