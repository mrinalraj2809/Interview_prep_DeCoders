#include <stdio.h>
#include <stdlib.h>
#define MAX 10
char* A;
void binary(int n)
{
	if(n<1) printf("%s",A);
	else{
		A[n-1]=0;
		binary(n-1);
		A[n-1]=1;
		binary(n-1);
	}
}
void main()
{
	binary(15);
	}
