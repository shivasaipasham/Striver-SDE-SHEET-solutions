/*Problem Link:https://leetcode.com/problems/rotate-image/

Approach 1: Brute Force(Use another matrix and copy rows to columns)
            Time Complexity:  O(n²)
            Space Complexity: O(n²)
           
Approach 2: Transpose the matrix and reverse every row
            Time Complexity: O(n²)
            Space Complexity:O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<i;j++)
                // as the given matrix will be of size NxN we can directly swap but if the given matrix is of size MxN we need extra space
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<r;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
