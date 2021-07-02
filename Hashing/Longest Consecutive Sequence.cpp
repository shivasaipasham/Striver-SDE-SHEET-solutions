/*Problem link:https://leetcode.com/problems/longest-consecutive-sequence/

Approach 1:Brute force(three loops)
           Time Complexity: O(n^3)
           Space Complexity:O(1)
           
Approach 2:Sorting and linear traversing
           Time Complexity: O(nlogn)
           Space Complexity:O(1)
           
Approach 3:Hashset (or) Hashmap (2nd code)
           Time Complexity: O(n)
           Space Complexity:O(n)
*/

//Using Hashset

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

//Using Hashmap

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,bool> umap;
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i]-1)==umap.end()){ //if nums[i]-1 is not present in map then current element will be the start of a new sequence
                umap[nums[i]]=true;
            }
            else{                                 
                umap[nums[i]]=false;              //if nums[i]-1 is present in map then current element will be the part of sequence which is started with previous element
            }
            if(umap.find(nums[i]+1)!=umap.end()){ //if nums[i]+1 is present in the map then it will not become the start of sequence as nums[i] will be start of sequence. 
                umap[nums[i]+1]=false;
            }
        }
        int ans=1,c=1;
        for(auto it:umap){
            if(it.second==true){             //if the current element's value is true in the map then it is start of the sequence so we will find its length 
                int start=it.first;
                while(umap.find(start+c)!=umap.end()){ 
                    c++;
                }
                ans=max(ans,c);
                c=1;
            }
        }
        return ans;
    }
};
