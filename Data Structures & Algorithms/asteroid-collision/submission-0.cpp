class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s ;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            bool alive = true;
            while (!s.empty() && s.top() > 0 && val < 0) {
                int top = s.top();
                if (abs(top) > abs(val)) {
                    alive = false;
                    break;
                }
                else if (abs(top) == abs(val)) {
                    s.pop();
                    alive = false;
                    break;
                }
                else {
                    s.pop();   // top asteroid explodes
                }
            }

            if (alive)
                s.push(val);
        }
        vector<int> ans ;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};