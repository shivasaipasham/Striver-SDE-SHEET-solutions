/* problem link : https://leetcode.com/problems/sort-colors/
   Time Complexity  : O(n)
   Space Complexity : O(1)
   
   Idea : Sweep all the 0's to the left and 2's to the right so that 1's stay in the middle  */



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=n-1;
         while(mid<=high){
             //if the current element is 0 we push it to the left 
             if(nums[mid] == 0){
                 swap(nums[low++] , nums[mid++]);
             }
             //if the current element is 2 we push it to the right and we dont increment mid because the element which we swapped from high maybe 0 which we need to push left
             else if(a[mid] == 2){
                 swap(nums[mid] , nums[high--]);
             }
             //if current element is 1 we just increment mid as it is already in sorted position
             else{
                 mid++;
             }
         }
    }
};
