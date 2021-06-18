/* Problem Link:https://leetcode.com/problems/maximum-subarray/

Approach 1: Traverse through the array and add arr[i] to current sum if sum+arr[i] > arr[i] 
            We will do the above step because if sum+arr[i]<arr[i] we know that arr[i] is very large and sum+arr[i]< arr[i] because of some negative elements in sum
            Time Complexity  : O(n)
            Space Complexity : O(1)


*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxans=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(nums[i],ans+nums[i]);
            maxans=max(maxans,ans);
        }
        return maxans;
    }
};
