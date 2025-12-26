#include<stdio.h>
#include<stdlib.h>
#include<string.h>
size_t mycpy(char* s1, const char* s2) {

}
int main(int argc, char* argv[]) {
	char s1[] =  "abc" ;
	char* s2 = (char*)malloc(strlen(s1)+1);
	strcpy_s (s2,strlen(s1)+1, s1);
	printf("%s", s2);
	free(s2);
	return 0;
}