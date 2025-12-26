#include <iostream>

using namespace std;

int main() {
	double a = 1.414;

	int b = int(a);
	int c = static_cast <int> (a);

	cout << b << endl << endl << c << endl;
}