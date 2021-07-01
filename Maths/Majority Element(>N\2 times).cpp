/*  Problem Link: https://leetcode.com/problems/majority-element/

Approach 1: Sorting
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
            
Approach 2: Hashmap
            Time Complexity  : O(n)
            Space Complexity : O(n)           
            
Approach 3: Bit manipulation.
            For every of the 32 bits we iterate over the array and check if current bit is set or not. If more than n/2 elements have the current bit as set then the final answer
            will also have the current bit set else not. In this way we can build the number.
            Time Complexity  : O(32*n)
            Space Complexity : O(1)
            
Approach 4: Moore's Voting Algorithm. The intiution behind this algorithm is that the count of majority element is greater than the total number of remaining minority elements.
            Now when we traverse through the array the majority count will get cancelled with minority until a point, and as majority elements are greater than n/2 we will be 
            remained with the answer.
            Time Complexity  : O(n)
            Space Complexity : O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0],cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){        //if the current majority element count becomes zero we make nums[i] as majority element
                ele = nums[i];
            }
            if(nums[i]==ele){ //if the current element is equal to majority element till now
                cnt++;
            }
            else{             //if the current element is not equal to the majority element till now
                cnt--;
            }
        }
        return ele;
    }
};
