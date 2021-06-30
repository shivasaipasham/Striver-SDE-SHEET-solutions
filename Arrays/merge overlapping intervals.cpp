/* Problem Link: https://leetcode.com/problems/merge-intervals/

Approach 1: First we will sort the array and linearly traverse over it. For each pair we will check if it is overlapping with the previous one. We will merge if it overlaps 
            else we will not merge.
            Time Complexity  : O(nlogn)
            Space Complexity : O(1)
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
      
        if(intervals.size()==0) return ans;
      
        sort(intervals.begin(),intervals.end());
      
        vector<int> temp=intervals[0];
      
        for(vector<int> ci : intervals){
            if(ci[0]<=temp[1]){   //checking if the current pair overlaps with the previous pair.
              
                temp[1] = max(ci[1],temp[1]); //merge the current pair into previous one
              
            }
            else{  // if the previous pair does not overlap with the current pair
              
                ans.push_back(temp); //pushing the current pair into ans vector as it cannot overlap with any other pair
                temp=ci;
              
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
