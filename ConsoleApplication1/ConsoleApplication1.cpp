#include<iostream>
using namespace std;

class Student {
	char* name;
	int age;
public:
	Student();
	Student(const char* name, int age);
	~Student();
	Student(const Student& obj2);
	void Print();
	void Input();
	int getAge();
	int setAge();
	void setName();
	void getName();
	Student& operator=(const Student&b);
};

Student::Student()
{
	name = nullptr;
	age = 0;
}

Student::Student(const char* _name, int _age)
{
	age = _age;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

Student::~Student()
{
	cout << "DESTRUCTOR" << endl;
	delete[] name;
}

Student::Student(const Student& obj2)
{
	age = obj2.age;
	if (name != nullptr) {
		delete[]name;
	}
	name = new char[strlen(obj2.name) + 1];
	strcpy_s(name, strlen(obj2.name) + 1, obj2.name);
	cout << "Copy const" << endl;
}

Student& Student::operator=(const Student& b) {
	if(this==&b) {
		return *this;
	}
	if (name != nullptr) {
		delete[]name;
	}
	age = b.age;
	name = new char[strlen(b.name) + 1];
	strcpy_s(name, strlen(b.name) + 1, b.name);
	cout << "Copy const" << endl;
}

void Student::Print()
{
	cout << "Name: " << name << endl << "Age: " << age << endl;
}

void Student::Input()
{
	char buff[100];
	cout << "Enter ur name: ";
	cin >> buff;
	cout << "Enter ur age: ";
	cin >> age;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
}

int Student::getAge()
{
	return age;
}

int Student::setAge()
{
	cout << "Enter ur age: ";
	cin >> age;
	return 0;
}

void Student::setName()
{
	char buff[100];
	cout << "Enter ur name: ";
	cin >> buff;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
}

void Student::getName()
{
	cout << "Name: " << name;
}

int main()
{
	Student a("Ivan", 16);
	Student b=a;
	b.Print();
}