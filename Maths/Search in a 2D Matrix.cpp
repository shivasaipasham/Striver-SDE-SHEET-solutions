  
/* This Problem is having two versions, the 2nd version is below the first version in this file.

Problem Link:https://leetcode.com/problems/search-a-2d-matrix/

Approach 1: Binary Search on every row and return true if the element is found else return false
            Time Complexity  : O(nlogm)
            Space Complexity : O(1)
            
Approach 2: Start from the top right corner and if the current element is == key return true else if current element is < key move to the left 
            else move to the right and if at any point if the indices go out of bounds return false
            Time Complexity  : O(n+m)
            Space Complexity : O(1)           
            
Approach 3: Traverse through the rows and and check if row[0] <= target and row[n] >= target,if it holds true perform a binary search on that row and
            return true if the element is found.
            Time Complexity  : O(n+log₂(m))
            Space Complexity : O(1)
            
Approach 4: Instead of comparing with every row from the start we perform a binary search on the rows itself and if in the row we get as mid if the first element is 
            greater than target and last element is less than target perform a binary search on that row.
            Time Complexity  : O(log₂(n)+log₂(m))
            Space Complexity : O(1)
            
Approach 5: The idea here is if we place all the elements of the matrix into an array the array will be sorted according to the problem statement and we can perform binary search
            But we need to do it inplace so we will be manipulating the indices in the matrix to get the desired result as explained in the below code.
            Time Complexity  : O(log₂(n*m))
            Space Complexity : O(1)
            
            
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0, high=(matrix.size()*matrix[0].size())-1, m=matrix[0].size(); // high is total number of elements in matrix - 1
        while(low<=high){
            int mid=low+(high-low)/2;
            int key = matrix[mid/m][mid%m]; // if the given matrix is of 4x5 size and mid=10, key gives us the 10th element of matrix. 
            if(key==target)
                return true;
            else if(key<target) //if the key is less than target we search on the right side else to the left
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};


/* Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

Approach 1: Binary Search on every row and return true if the element is found else return false
            Time Complexity  : O(nlogm)
            Space Complexity : O(1)
            
Approach 2: Start from the top right corner and if the current element is == key return true else if current element is < key move to the left 
            else move to the right and if at any point if the indices go out of bounds return false
            Time Complexity  : O(n+m)
            Space Complexity : O(1)  
            
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target) 
                return true;
            else if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
};
