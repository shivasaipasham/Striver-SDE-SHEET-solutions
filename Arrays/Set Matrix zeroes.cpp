/* Problem Link:https://leetcode.com/problems/set-matrix-zeroes/

Approach 1: Use two dummy arrays of size col and row store 0 in
            both the arrays if there is a zero at the respective 
            indices.
            Time Complexity  : O(n*m)
            Space Complexity : O(n+m)

Approach 2: Similar to approach 1 but instead of taking two extra 
            dummy arrays use first row and col as dummy arrays.
            Time Complexity  : O(n*m)
            Space Complexity : O(1)

*/
void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1,row=matrix.size(),col=matrix[0].size();
        //iterating the matrix
        for(int i=0 ;i<row; i++){
            //set the value of col0 to 0 if there is a zero in the first column
            if(matrix[i][0] == 0) col0=0;
            //start from second column because we will set the first col values later
            for(int j=1; j<col; j++){
                if(matrix[i][j] == 0)
                    //set leftmost and topmost element to zero 
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
  
  
        //now iterate the matrix from back to set the elements to zero
        for(int i=row-1; i>=0; i--){
            //iterate from last to second col only
            for(int j=col-1; j>=1; j--){
                //if leftmost or topmost element is zero then set element to zero
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            // if the col0 is 0 it means that we have a zero in the first col 
            // so,we have to set all values in first col to 0
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
