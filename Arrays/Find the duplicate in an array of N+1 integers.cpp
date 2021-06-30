/* problem link : https://leetcode.com/problems/find-the-duplicate-number/

   Approach 1 : Sort the given array. After sorting the two adjacent elements which are equal becomes the answer.
                Time Complexity  : O(nlogn)
                Space Complexity : O(1)
                
   Approach 2 : Using set. Traverse over the array and check if the current element already exists in the set, if not insert it. If the element is already present 
                then it is the answer.
                Time Complexity  : O(n)
                Space Complexity : O(n)
                
   Approach 3 : Using linkedlist cycle detection. Explained below
                Time Complexity  : O(n)
                Space Complexity : O(1)
                
                 
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      
        int slow = nums[0];
        int fast = nums[0];
      
        do{ //finding the intersection point.
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
      
        while(slow!=fast){ //now finding the cycle 
            slow = nums[slow];
            fast = nums[fast];
        }
      
        return fast;
    }
};
