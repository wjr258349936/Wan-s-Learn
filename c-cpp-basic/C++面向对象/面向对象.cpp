#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student() {
		cout << "Call Student()" << endl;
	}
	~Student() {
		cout << "Call ~Student()" << endl;
	}
	Student(int age, string name) {
		cout << "Student method" << endl;
	}
	void Student_name(string name) {
		cout << "Student_name is " << name;
	}
};

class Complex
{
public:
	double m_real, m_imag;
	Complex(double real, double imag) {
		m_real = real;
		m_imag = imag;
		cout << "Complex method" << endl;
	}
	Complex(const Complex&c) {
		m_real = c.m_real;
		m_imag = c.m_imag;
		cout << "My complex method" << endl;
	}
};



int main() {
	//Student stu1(18, "Wan");
	Student class3[2] = { {12,"xiaoming"},{ 15 , "xiaogang"} };
	Student* stu = new Student[20];
	delete[] stu;
	/*Complex x1(1, 2);
	Complex x2 = x1;
	cout << x2.m_real << " " << x2.m_imag << endl;*/
	return 0;
}
