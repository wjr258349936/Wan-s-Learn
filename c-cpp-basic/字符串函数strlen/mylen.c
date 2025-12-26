#include <stdio.h>
#include <string.h>
size_t mylen(const char*s)
{
	int idx=0;
	while (s[idx] != '\0') {
		idx++;
	}
	return idx;
}
int main(int argc,char const *argv[])
{
	char line[] = "Hello";
	printf("strlen = %zu\n", sizeof(line));
	printf("strlen = %zu\n", strlen(line));
	printf("strlen = %zu\n", mylen(line));
	return 0;
}