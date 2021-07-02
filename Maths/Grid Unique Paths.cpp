/*  Problem Link: https://leetcode.com/problems/unique-paths/

Approach 1: Using Recursion
            Time Complexity  : O(2ᵐ) where m = a*b with a being number of rows and b being number of columns
            Space Complexity : O(1)
            
Approach 2: Using Dynamic Programming
            Time Complexity  : O(m) where m = a*b with a being number of rows and b being number of columns
            Space Complexity : O(m) where m = a*b with a being number of rows and b being number of columns
            
Approach 3: Using Combinatorics.
            In a matrix of size axb in order to reach (a-1,b-1) cell we should take a-1 steps down and b-1 steps right. So in total we should take a+b-2 steps in order to reach
            the last cell. We can take these steps in any order. Out of a+b-2 steps we should choose a-1 steps or we should choose b-1 steps and the remaining steps will definitely
            be the vice-versa of what we have choosen. So the choosing can either be ᵃ⁺ᵇ⁻²Cₐ₋₁ (or) ᵃ⁺ᵇ⁻²C₆₋₁ (superscript = a+b-2 , subscript = a-1 (or) b-1)
            Time Complexity  : O(a-1) or O(b-1)
            Space Complexity : O(1)
            
*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int r = m-1;
        double res = 1;
        for(int i=1 ; i<=r;i++){
          res = res * (N-r+i)/i;
        }
        return (int) res;
    }
};
