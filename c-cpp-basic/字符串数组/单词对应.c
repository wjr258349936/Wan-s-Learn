#include <stdio.h>
int main()
{
	int month;
	while(1){
		printf("请输入月份数字:");
		scanf_s("%d", &month);
		char* block[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
		printf("%s\n", block[month - 1]);
		char op;
		op = _getch();
		if (op == 27) {
			break;
		}
		else {
			continue;
		}
	}
	return 0;
}