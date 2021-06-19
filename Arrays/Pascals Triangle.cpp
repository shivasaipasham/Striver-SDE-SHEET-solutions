/* Problem Link: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
 
Approach 1: Find ⁿc₀ t0 ⁿcₓ (x=col-1) for given row number n
            Time Complexity : O(n²)
            Space Complexity: O(1)
Approach 2: using simple math multiply every previous element 
            with (n-i)/(i+1) where is the given row index.
            Time Complexity : O(n)
            Space Complexity: O(1)

*/

vector<int> Solution::getRow(int A) {
    vector<int> v;
    int firstnum = 1;
    for(int i=0;i<=A;i++){ //A+1 element are there in Ath row
         v.push_back(firstnum);
         firstnum = firstnum * (A-i)/(i+1);
    }
    return v;
}
