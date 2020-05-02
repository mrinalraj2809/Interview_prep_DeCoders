/*****************************************************
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*******************************************************/



/*************  Solution CPP **************/
/********* Brute Force approch ******/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int countt =0;
        for(unsigned long long int i=0; i< J.length();i++)
        {
            auto itr = find(S.begin(),S.end(),J[i]);
            if(itr != S.end())
            {
                // *itr = '*';
                countt += std::count(S.begin(),S.end(),J[i]);
            }
        }
        return countt;
        
        
    }
};

/********  Efficient approch using set ***********/ 
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::set<char> jewels;
        for (char j : J) {
            jewels.insert(j);
        }
        
        int numJewels = 0;
        for (char s : S) {
            if (jewels.find(s) != jewels.end()) {
                numJewels++;
            }
        }
        
        return numJewels;
    }
};