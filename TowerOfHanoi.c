#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg)
{
	if(n==1)
	{
		cout<<"Move the disk from "<<fromPeg<<" to "<<toPeg<<endl;
		return ;
	}
	towerOfHanoi(n-1,fromPeg,auxPeg,toPeg);
	cout<<"Move the disk from "<<fromPeg<<" to "<<toPeg<<endl;
	towerOfHanoi(n-1,auxPeg,toPeg,fromPeg);
}
int main()
{
	towerOfHanoi(3,'A','B','C');
	return 0;
}
