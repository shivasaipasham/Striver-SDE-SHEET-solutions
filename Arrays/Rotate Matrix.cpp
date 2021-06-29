/*Problem Link:https://leetcode.com/problems/rotate-image/
Approach 1:Brute Force(Use another matrix and copy rows to columns)
           Time Complexity: O(n^2)
           Space Complexity:O(n^2)
Approach 2:Transpose the matrix and reverse every row
           Time Complexity: O(n^2)
           Space Complexity:O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<r;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
