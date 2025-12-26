#include <stdio.h>
#include <string.h>
size_t mycmp(const char* s1, const char* s2) {
	while (*s1 == *s2 && *s1!='\0' &&*s2!='\0') {
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
int main(int argc,char*argv[]) {
	char s1[] =  "abc" ;
	char s2[] =  "Abc" ;

	printf("%d\n", strcmp(s1, s2));
	printf("%zd\n", mycmp(s1, s2));
	printf("%d\n", 'a' - 'A');
	return 0;
}