#include <iostream>
#include <bitset>
using namespace std;

int main() {
	string m = "10011";
	bitset<5> b (m,0,5);
	//bitset<5> b(19);
	cout << b <<endl;

	for (int i = 0; i < 5; i++) {
		cout << b[i] << " ";
	}
	cout << endl;

	cout << "是否有1 : " << b.any() <<endl;
	cout << "是否没有1 : " << b.none() <<endl;
	cout << "1的个数为 : " << b.count() <<endl;
	cout << "b中元素的个数 : " << b.size() <<endl;
	cout << "b中第i个元素是不是1 : " << b.test(0) <<endl;

	b.flip(1);
	cout << b << endl;

	unsigned long a = b.to_ulong();
	cout << a << endl;

	return 0;
}