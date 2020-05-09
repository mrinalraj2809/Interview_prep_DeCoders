#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
int  main()
{
  ofstream fopen ;
  fopen.open("testcase1.txt");
  for(long long int i=0;i<6;i++)
  {
    for(long long int j=0;j<6;j++)
      fopen<<rand()%2<<" ";
      fopen<<'\n';
  }
  fopen.close();
}
// #include <bits/stdc++.h>
// #include <fstream>
// using namespace std;
//
// // function to generate random numbers in range [0-999] :
// int randomize()
// {
//     return (rand() % 2);
// }
//
// int main ()
// {
//   // for different values each time we run the code
//   srand(time(NULL));
//
//   vector<vector<int> > vect(1000000000,std::vector<int>(1000000000) v;); // declaring the vector
//
//   // Fill all elements using randomize()
//   // generate(vect.begin(), vect.end(), randomize);
//   for(long long int j =0;j< 100;k)
//   generate_n(vect.begin(), 100000000, randomize);
//   // displaying the content of vector
//   for (int i=0; i<vect.size(); i++)
//      cout << vect[i] << " " ;
//
//   return 0;
// }
