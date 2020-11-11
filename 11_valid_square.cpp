/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
 

Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/




class Solution {
private:
    int findlen(vector<int> p1, vector<int> p2) {
        return (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[0]-p1[0])*(p2[0]-p1[0]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2) return false;
        const double eps = 1e-5;
        vector<vector<int>> pts = {p1, p2, p3, p4};
        vector<double> sides;
        /*
        [p1, p2], [p1, p3], [p1, p4], [p2, p3], [p2, p4], [p3, p4]
        */
        for (int i=0; i<3; ++i) {
            for (int j=i+1; j<4; ++j)
                sides.push_back(findlen(pts[i], pts[j]));
        }
        sort(sides.begin(), sides.end());
        for (double& side : sides)
            side = sqrt(side);
        // for (double i : sides)
        //     cout << i << " ";
        // cout << "\n";
        for (int i=0; i<3; ++i)
            if (sides[i] != sides[i+1]) return false;
        if (sides[4] != sides[5]) return false;
        if (abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[5]*sides[5]) > eps) return false;
        return true;
    }
};
