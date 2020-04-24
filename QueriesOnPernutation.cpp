class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;vector<int> pos;
        for(int i=0;i<m;i++)
        {
            p.push_back(i+1);
        }
        for(int i=0;i<queries.size(); i++)
        {
            /*int val = p[queries[i]];*/
            pos.push_back(find(p.begin(),p.end(),queries[i])-p.begin());
            p.erase(find(p.begin(),p.end(),queries[i]));
            p.insert(p.begin(),queries[i]);
        }
        return pos;
    }
};