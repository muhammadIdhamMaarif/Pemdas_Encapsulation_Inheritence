#include <iostream>
#include <string>

class Person {
public:
	std::string name;
	int age;

	void displayInfo() {
		std::cout << "Nama        : " << name << '\n'
				  << "Umur        : " << age  << '\n';				  
	}
};

class Student : public Person {
public:
	std::string studentID;
	float grade;

	void displayStudentInfo() {
		displayInfo();
		std::cout << "Student ID  : " << studentID << '\n'
				  << "Grade       : " << grade << "\n\n\n";
	}
};

int main() {
	Student Idham;
	Student Rafi;

	Idham.name = "Muhammad Idham Ma'arif";
	Idham.age = 18;
	Idham.studentID = "245150300111024";
	Idham.grade = 3.99;

	Rafi.name = "Rafi Ibnushaleh";
	Rafi.age = 19;
	Rafi.studentID = "245150301111012";
	Rafi.grade = 3.98;

	Idham.displayStudentInfo();
	Rafi.displayStudentInfo();

	return 0;
}
