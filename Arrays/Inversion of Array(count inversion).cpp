/* Problem Link:https://www.spoj.com/problems/INVCNT/

Approach 1: Brute force using two nested for loops
            Time Complexity  : O(n²)
            Space Complexity : O(1)
            
Approach 2: By slightly modyfing the merge function while performing merge sort
            Time Complexity  : O(nlogn)
            Space Complexity : O(n)
*/


#include<bits/stdc++.h>
using namespace std;
#define en "\n"
 
long long result=0;
 
void merge(vector<int> &v,int low,int mid,int high){
    vector<int> temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(v[i]<=v[j]){
            temp.push_back(v[i++]);
        }
        else{
            // if the current element in the low-mid array is greater than the current element in mid-high array than all elements after v[i] will be definitely greater than v[j]
            result+=mid-i+1;
            temp.push_back(v[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(v[i++]);
    }
    while(j<=high){
        temp.push_back(v[j++]);
    }
    for(int k=low;k<=high;k++){
        v[k]=temp[k-low];
    }
    temp.clear();
}
 
void mergesort(vector<int> &v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(v,low,mid);
        mergesort(v,mid+1,high);
        merge(v,low,mid,high);
    }
    
}
 
 
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++){
         cin>>v[i];
      }
      mergesort(v,0,v.size()-1);
      cout<<result<<en;
      result=0;
   }
    
}
