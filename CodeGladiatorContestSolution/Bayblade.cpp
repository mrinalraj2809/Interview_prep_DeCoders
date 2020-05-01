/*
Srinu is all prepared for the Beyblade World Championship. The tournament is team-based and each team can have N members. A player can fight against a single player only. Team B-Phase is all excited and pumped up as they have practised a lot to win against team G-Phase(Gold-Phase). Shastri, the mind of team B-Phase, has created a database where he has the data about the power of other teams’ members and his own team members. The tournament is going to start in some time and Shastri moves to the cafeteria to have a snack before the competition.

The team B-Phase is to fight in some time and they are tensed up as someone has kidnapped Shastri from the cafeteria. They have made a police complaint and the police are searching for Shastri. Luckily, they have found his device with all the data. The problem is, the data is present randomly and not in the order they have to fight the opponent. Team B-Phase wants to win at any cost and for that, they need the order in which they have to fight optimally to win the maximum number of battles.

A player can win only when his/her beyblade power is strictly greater than the opponents beyblade power.

Input Format

    The first line of input consists of the number of test cases, T
    The first line of each test case consists of the number of members each team can have, N.
    The second line of each test case consists of N space-separated integers representing the power of beyblades of Team B-Phase members.
    The third line of each test case consists of N space-separated integers representing the power of beyblades of G-Phase members.

Constraints

1<= T <=1000
1<= N <=10^6
0<= Power of Beyblade <= LLONG_MAX

Output Format

For each test case, print the maximum number of fights Team B-Phase can win if they go to fight in an optimal manner.

Sample Input 0

1
3 
20 30 50
60 40 25

Sample Output 0

2

Explanation 0

Here only 50 is greater than 25.So, B-Phase team can have only one win. After rearranging as

20 50 30
60 40 25

50 of B-Phase is greater than 40 of G-Phase and 30 is greater than 25.

They have 2 wins now, which is optimal.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, count = 0;
    ;
    cin >> t;
    while (t--)
    {
        count = 0;
        cin >> n;
        vector<int> arrb(n), arrg(n);
        for (int i = 0; i < n; i++)
            cin >> arrb[i];
        for (int i = 0; i < n; i++)
            cin >> arrg[i];
        sort(arrb.begin(), arrb.end());
        sort(arrg.begin(), arrg.end());
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < n && arrb[j] <= arrg[i])
                j++;
            if (arrb[j] > arrg[i])
                count++, arrb[j] = 0;
            if (j == n - 1)
                break;
        }
        cout << count << endl;
    }
    return 0;
}

