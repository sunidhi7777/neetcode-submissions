class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        
        int i , area=0 , n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,n-1);
        stack<int> s ;
        for(i=0;i<n;i++){
            if(s.empty()){
                left[i] = -1;
            }
            else{
                while(!s.empty() && height[s.top()] >= height[i]){
                    s.pop();
                }
            }
            if(s.empty())
            left[i]=-1 ;
            else 
            left[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(i=n-1;i>=0;i--){
            if(s.empty()){
                right[i] = n;
            }
            else{
                while(!s.empty() && height[s.top()] >= height[i]){
                    s.pop();
                }
            }
            if(s.empty())
            right[i]=n ;
            else 
            right[i]=s.top();
            s.push(i);
        }
        for(i=0;i<n;i++){
            area = max(area , height[i]*(right[i]-left[i]-1) );
        }
        return area ;
    }
};
