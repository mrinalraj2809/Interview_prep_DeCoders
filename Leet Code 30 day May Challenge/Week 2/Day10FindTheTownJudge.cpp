/****************************************
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N


****************************************/




/************** Solution cpp*************/
/** O(N)  **/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> in(N+1);
        vector<int> out(N+1);
        if (N==1)return 1;
        for(int i=0;i<trust.size();i++)
        {
            in[trust[i][1]]++;
            out[trust[i][0]]++;
        }
        auto itrIN = find(in.begin(),in.end(),N-1);
        if(itrIN != in.end() && out[itrIN-in.begin()] == 0)
        {
            return itrIN-in.begin();
        }
        return -1;
    }
};


/* another approach  */
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        unordered_map<int,pair<int,int>> m;
        for(int i=1;i<=N;i++){
            pair<int,int> p;
            p.first=p.second=0;
            m.insert(make_pair(i,p));
        }
        for(int i=0;i<trust.size();i++){
            auto it = m.find(trust[i][0]);
            it->second.second++;
            it=m.find(trust[i][1]);
            it->second.first++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second.first>=N-1 && i->second.second==0)
                return i->first;
        }
        return -1;
    }
};