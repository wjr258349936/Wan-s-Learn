#include <iostream>
#include <ctime>

#define random(x) rand()%x

using namespace std;

int main() {
	int res = 1;
	while (res != 0) {
		srand((int)time(NULL));
		int a = random(99) + 1;
	}

	return 0;
}