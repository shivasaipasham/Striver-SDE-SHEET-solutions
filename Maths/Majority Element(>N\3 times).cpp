 /*  Problem Link: https://leetcode.com/problems/majority-element-ii/

Approach 1: Sorting
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
            
Approach 2: Hashmap
            Time Complexity  : O(n)
            Space Complexity : O(n)           
            
Approach 3: Moore's Voting Algorithm. At max we can only get 2 elements whose count is greater than n/3 times
            So we take two variables num1 and num2 and approach the problem in the same way we did it in the previous problem.
            Time Complexity  : O(n)
            Space Complexity : O(1)
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,c1=0,c2=0;   // declare num1 and num2 as any integer
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){           // if current element is equal to num1 we increase count of c1
                c1++;
            }
            else if(nums[i]==num2){      // if current element is equal to num2 we increase count of c2
                c2++;
            }
            else if(c1==0){             // if c1 is zero then we will get a new num1 as previous one is cancelled out
                num1 = nums[i];
                c1=1;
            }
            else if(c2==0){             // if c2 is zero then we will get a new num2 as previous one is cancelled out
                num2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        int num1_count=0,num2_count=0;
        for(int x:nums){                 // we need to check in the array again if the count of num1 and num2 is greater then n/3 and return the answer
            if(x==num1) 
              num1_count++;
            else if(x==num2) 
              num2_count++;
        }
        vector<int> ans;
        if(num1_count>nums.size()/3)
            ans.push_back(num1);
        if(num2_count>nums.size()/3)
            ans.push_back(num2);
        return ans;
    }
};
