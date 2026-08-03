class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0 , down = n-1;
        int left = 0 , right = m-1 ;
        int mid , center;
        int row = 0;
        while(top <= down){

    mid = top + (down-top)/2;

    if(target < matrix[mid][0])
        down = mid - 1;

    else if(target > matrix[mid][m-1])
        top = mid + 1;

    else{
        row = mid;
        break;
    }
}

        if(row == -1)
         return false;
        while(left<=right){
            center = left + (right - left)/2;
            if(target>matrix[row][center])
            left = center+1 ;
            else if(target<matrix[row][center]) 
            right = center-1 ;
            else if(matrix[row][center]==target)
            return true ;
        }
        return false;
    }
};
