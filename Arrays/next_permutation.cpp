/* Problem Link:https://leetcode.com/problems/next-permutation/

Approach 1: use next_permutation() if you are using c++
            Time Complexity : O(n)
            Space Complexity: O(1)
            
Approach 2: Find the first decreasing element from back and swap it with the smallest element greater than this element in the increasing sequence 
            from back and reverse the remaining array
            (if there is no decreasing element then directly reverse the entire array)
            Time Complexity : O(n)
            Space Complexity: O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),idx1 = -1,idx2 = -1;
        //iterating the array from back to find the index of the first
        //decreasing element
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }
        }
        //if there is no decreasing sequence return sorted array
        if(idx1 == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //if there is decreasing sequence then find the smallest 
        //from the back which is greater than the idx1 element
        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[idx1]){
                idx2 = i;
                break;
            }
        }
        //swap idx1 element and idx2 element
        swap(nums[idx1],nums[idx2]);
        //revese the remaining array
        reverse(nums.begin()+idx1+1,nums.end());
    }
};
