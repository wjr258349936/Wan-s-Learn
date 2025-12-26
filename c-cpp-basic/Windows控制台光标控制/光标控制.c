#include <stdio.h>
#include <Windows.h>
void setXY(int x, int y) {
	COORD pos;
	HANDLE obj;
	
	pos.X = x;
	pos.Y = y;
	obj = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(obj, pos);
}

COORD getXY() {
	HANDLE obj;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	COORD res;

	obj = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(obj,&buf);
	res = buf.dwCursorPosition;

	return res;
}

void setColor(int X,int Y) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),16 * X + Y);
}

void test01() {
	COORD temp;

	setXY(10, 10);
	setColor(7,6);
	printf("*****************");
	setXY(10, 11);
	setColor(15,0);
	printf("1.字母打字游戏");
	setXY(10, 12);
	printf("2.单词记忆游戏");
	setXY(10, 13);
	setColor(7,6);
	printf("*****************");
	setXY(10, 14);
	setColor(7,9);
	printf("请选择游戏类型：");
	temp = getXY();

	setXY(10, 20);
	setColor(15,4);
	printf("当前系统状态，生命值 20");
	setXY(temp.X, temp.Y);
	setColor(0,7);
}

int main() {
	test01();
	_getch();
	return 0;
}