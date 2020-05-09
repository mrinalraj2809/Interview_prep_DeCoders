/*You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.Each student can have multiple answer sheets.So the teacher has  queries:

 1:Add the marks  to the student whose name is .

 2: Erase the marks of the students whose name is .

 3: Print the marks of the students whose name is . (If  didn't get any marks print .)

Input Format

The first line of the input contains  where  is the number of queries. The next  lines contain  query each.The first integer,  of each query is the type of the query.If query is of type , it consists of one string and an integer  and  where  is the name of the student and  is the marks of the student.If query is of type  or ,it consists of a single string  where  is the name of the student.



Output Format

For queries of type  print the marks of the given student.

Sample Input

7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
Sample Output

30
20
0


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,qType;
    cin>>n;
    map<string, int> m;int mark;
    string name;
    for(int i=0;i<n;i++)
    {
        cin>>qType;
        switch(qType)
        {
            case 1: cin>>name>>mark;
                    if(m.find(name) != m.end())
                        (m.find(name)->second) += mark;
                    else
                        m.insert(pair<string,int>(name,mark));
                    break;
            case 2: cin>>name;
                    if(m.find(name) != m.end())
                        m.find(name)->second = 0;
                    break;
            case 3: cin>>name;
                    if(m.find(name) != m.end())
                        cout<<m.find(name)->second<<endl;
                    else cout<<"0\n";
                    break;
        }
    }  
    return 0;
}



