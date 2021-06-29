/* Problem Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Approach 1: Brute force (Using two  loops)
            Time Complexity: O(n²)
            Space Complexity:O(1)
            
Approach 2: Keep track of minimum element on left and update profit value 
            Time Complexity: O(n)
            Space Complexity:O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),mini = INT_MAX,ans=0;
        for(int i=0;i<n;i++){
            //updating the minimum element everytime
            mini = min(prices[i],mini);
            //updating the answer with the current minimum element 
            ans = max(ans,prices[i]-mini);
        }
        return ans;
    }
};
