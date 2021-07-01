/* Problem Link: https://leetcode.com/problems/two-sum/

Approach 1: Brute force (Using two loops)
            Time Complexity: O(n²)
            Space Complexity:O(1)
            
Approach 2: Two Pointer(sort the array and maintain one pointer at start and one at end)
            Time Complexity: O(nlogn)
            Space Complexity:O(1)
            
Approach 3: Using map (number,index) (or) we can directly use a set.
            Time Complexity: O(n)
            Space Complexity:O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int> um;
        vector<int> idx;
        for(int i=0;i<n;i++){
            if(um.find(target-nums[i]) != um.end()){
                idx.push_back(um[target-nums[i]]);
                idx.push_back(i);
                break;
            }
            um[nums[i]] = i;
        }
        return idx;
    }
};
