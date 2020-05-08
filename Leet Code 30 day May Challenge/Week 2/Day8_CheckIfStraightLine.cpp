You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.


Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

/***************** Solution CPP *********************/
/*  Brute Force approch *****/
class Solution {
public:
    void getSlope(int x1,int y1,int x2,int y2,int *num, int *den)
    {
        *num = (y2-y1);
        *den = (x2-x1);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        set<float> slope;
        int num,den;
        for(int i=0;i<coordinates.size()-1;i++)
        {
            getSlope(coordinates[i][0],coordinates[i][1],coordinates[i+1][0],coordinates[i+1][1], &num,&den);
            if(num != 0)slope.insert(num*1.0/den);
        }
        if(slope.size()>1)return false;
        return true;
    }
};

/**** Efficient Approch  **/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(coordinates.size()==2)
            return true;
        else if(coordinates[0][0]==coordinates[1][0])
        {
            int x = coordinates[1][0];
            for(int i=0;i<coordinates.size();i++)
            {
                if(coordinates[i][0]!=x)
                    return false;
            }
        }
        else if(coordinates[0][1]==coordinates[1][1])
        {
            int x = coordinates[1][1];
            for(int i=0;i<coordinates.size();i++)
            {
                if(coordinates[i][1]!=x)
                    return false;
            }
        }
        else
        {
            int x1 = coordinates[0][0];
            int y1 = coordinates[0][1];
            float m = (coordinates[1][1] - y1)/(coordinates[1][0] - x1);
            for(int i=2;i<coordinates.size();i++)
            {
                float m2 = (float)(coordinates[i][1] - y1)/(coordinates[i][0] - x1);
                //cout<<m2<<" ";
                if(m2!= m)
                    return false;
            }
        }
        return true;
    }
};