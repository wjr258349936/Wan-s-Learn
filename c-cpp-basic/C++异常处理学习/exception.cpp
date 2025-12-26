#include "exception.h"
#include <iostream>
#include <exception>
#include <string>
class MyException
{
public:
    const char* what() const throw() {
        return "my test exception";
    }
};

double myadd(double v1, double v2)
{
    if (v1 > 0) {
        MyException  myes;
		throw myes;
    }
    return v1+v2;
}

double mydiv(double v1, double v2)
{
    if (v2 == 0) {
        throw std::string("division zero condition!");
    }
    return v1/v2;
}

void exceptiontest()
{
    double num1 = 100, num2 = 0, num3 = 10, addnum,divnum;
    /*addnum = myadd(num1, num2);
    std::cout << addnum << std::endl;*/
    try {
		std::cout << myadd(num1, num2) << std::endl;
    }
    catch (MyException e) {
		std::cout << e.what() << std::endl;
    }
    try {
        divnum = mydiv(num1, num2);
        std::cout << divnum << std::endl;
    }
    catch (std::string msg) {
        std::cout << "³ö´íÁË£¡:" << msg << std::endl;
    }
}
