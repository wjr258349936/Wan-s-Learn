//#include <easyx.h>
//#include <iostream>
//using namespace std;
//
//int main(){
//	//创建一个图形窗口 宽度 * 高度
//	initgraph(640, 480,EX_SHOWCONSOLE);
//	//设置窗口的背景颜色
//	setbkcolor(0x1E1E1E);
//	//用设置的背景颜色填充整个窗口
//	cleardevice();
//	//防止窗口退出
//	getchar();
//	return 0;
//}

#include <graphics.h>
#include <conio.h>
int main()
{
	// 建立绘制窗口
	initgraph(500, 700);
	// 将程序暂停 接受一个字符输入
	_getch();
	//关闭绘制窗口
	closegraph();
	return 0;
}