/*Problem link:https://leetcode.com/problems/longest-consecutive-sequence/

Approach 1:Brute force(three loops)
           Time Complexity: O(n^3)
           Space Complexity:O(1)
           
Approach 2:Sorting and linear traversing
           Time Complexity: O(nlogn)
           Space Complexity:O(1)
           
Approach 3:Hashset
           Time Complexity: O(n)
           Space Complexity:O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int largest = 0;
        //store all elemenys in set
        for(int num : nums){
            s.insert(num);
        }
        for(int num : nums){
            //check if just smaller element is present or not
            //if it is not present check for just larger element 
            if(!s.count(num-1)){
                int currlargest = 1;
                int cnum = num;
                while(s.count(cnum+1)){
                    cnum+=1;
                    currlargest+=1;
                }
                largest = max(largest,currlargest);
            }
        }
        return largest;
    }
};
