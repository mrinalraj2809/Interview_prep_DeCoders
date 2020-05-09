#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg)
{
	/*if(n==1)
	{
		cout<<"Move the disk from "<<fromPeg<<" to "<<toPeg<<endl;
		return ;
	}*/
	if(n>0){
	// Move n-1 discs to auxilliary peg
	towerOfHanoi(n-1,fromPeg,auxPeg,toPeg);
	//Move the remaining nth disc to the destination disc
	cout<<"Move the disk from "<<fromPeg<<" to "<<toPeg<<endl;
	//Move the n-1 discs to destination peg
	towerOfHanoi(n-1,auxPeg,toPeg,fromPeg);}
}
int main()
{
	towerOfHanoi(3,'A','B','C');
	return 0;
}
