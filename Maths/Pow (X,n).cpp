/* Problem Link: https://leetcode.com/problems/powx-n/

The general approach if n is negative is find for positive n and return 1/ans

Approach 1: Using bit manipulation. Any number can be expressed as the sum of powers of 2, we use this property to find the power in the first code.
            Time Complexity  : O(logn)
            Space Complexity : O(1)
            
Approach 2: Using recursion. we can express xⁿ as xⁿ/² * xⁿ/². We will call this function recursively until n/2 becomes 0.
            Time Complexity  : O(logn)
            Space Complexity : O(1)  
            
 */

int ans = 1,x = a;
while(n>0){  
    if(n&1){
        ans = ans*x; //if the current LSB is 1 we have the value of that bit in our number , so we multiply it by x.
    }
   x = x*x;         // we compute the value of next bit before hand to reduce time complexity.
   n = n>>1;
}
return ans;


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        double temp = myPow(x,n/2);
        if(n<0)
            x=1/x;
        if(n&1)
            return temp*x*temp; // if n is odd we need to multiply an additional x as we can divide n into two equal parts.
        else
            return temp*temp; // if n is even we directly return
    }
};
