/* problem link : https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

   Approach 1 : Negation
                Traverse the array and make arr[arr[i]] = -1*arr[arr[i]]
                After completing the above step the elements which  remain positive are the answer.
                Time Complexity  : O(n)
                Space Complexity : O(1)

   Approach 2 : Math
                x-y = (sum from 1 to n) - sum(arr)
                x² - y² = (sum of squares from 1 to n) - sum(squares of array elements)
                x = missing number y = repeated number
                solve both equations to get the answer
                Time Complexity  : O(n)
                Space Complexity : O(1)

   Approach 3 : Bit manipulation
                explained below
                 
*/

#include<bits/stdc++.h>
using namespace std;
#define en "\n"

int findLSB(int n){
    int bit_no = 0;
    while(n>0){
        if(n&1) return bit_no;
        n=n>>1;
        bit_no++;
    }
    return 0;
}
    
int set_Bit(int num,int bit_no){
    return (num>>bit_no)&1?1:0;
}

void missandRepeat(int arr[], int n) {

    int xor_1ton=0;
    // find xor of numbers from 1 to n
    for(int i=0;i<n;i++){
        xor_1ton = xor_1ton ^ (arr[i]);
    }
    // find xor of the elements of the array
    int xor_arr=0;
    for(int i=1;i<=n;i++){
        xor_arr = xor_arr ^ i;
    }
    // find xor of both above
    int total_xor = xor_arr ^ xor_1ton;   
    // find the rightmost set bit in total_xor
    int LSB = findLSB(total_xor);
    // The numbers in which whose LSB(consider above variable not least siginificant bit) is not set, xor them in first_bucket and rest of them in second _bucket 
    int first_bucket=0,second_bucket=0;

    for(int i=1;i<=n;i++){
        if(set_Bit(i,LSB)){
            first_bucket = first_bucket^i;
        }
        else{
            second_bucket = second_bucket^i;
        }
    }

    for(int i=0;i<n;i++){
        if(set_Bit(arr[i],LSB)){
            first_bucket = first_bucket^(arr[i]);
        }
        else{
            second_bucket = second_bucket^(arr[i]);
        }
    }

    cout<<first_bucket<<" "<<second_bucket;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[] = {5,2,7,4,6,1,5};
    missandRepeat(arr,7);

}
