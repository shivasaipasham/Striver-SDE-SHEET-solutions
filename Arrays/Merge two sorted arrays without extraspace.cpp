/* Problem link: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

   Approach 1 : Insertion Sort with two pointers
                Traverse through the first array if we find current element of first array > current element of secodn array swap them
                Now sort the second array and repeat the process
                Time Complexity : O(n*m)
                Space Complexity: O(1)

   Approach 2 : Using merge function of merge sort
                Time Complexity : O(n+m)
                Space Complexity: O(n+m)

   Approach 3 : Using Gap method(intutuion behind this method is Shell sort)
                Time Complexity : O((n+m)*log(n+m))
                Space Complexity: O(1)
                This method is implemented below
                 
*/

int nextgap(int gap){
    if(gap<=1) return 0;
    return gap/2 + gap%2;
}

void merge(vector<int> &v1,vector<int> &v2,int n,int m){
    int gap = n+m,i,j;
    gap = nextgap(gap);
    while(gap>0){
        // if both elements to be compared are in first array
        for(i=0; i+gap<n; i++){
            if(v1[i]>v1[i+gap]){
                swap(v1[i] , v1[i+gap]);
            }
        }
        // if one element is in first array and another element is in second array
        for(j = gap>n?gap-n:0 ; i<n && j<m; i++ ,j++){
            if(v1[i]>v2[j]){
                swap(v1[i] , v2[j]);
            }
        }
        // if both the elements to be compared are in second array
        if(j<m){
            for(j=0; j+gap<m; j++){
                if(v2[j]>v2[j + gap]){
                    swap(v2[j], v2[j + gap]);
                }
            }
        }
        gap = nextgap(gap);
    }
}
