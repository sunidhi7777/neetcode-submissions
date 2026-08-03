class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;

        for(char c : tasks)
            mp[c]++;

        priority_queue<int> pq;

        for(auto x : mp)
            pq.push(x.second);

        int time = 0;

        while(!pq.empty()) {

            vector<int> temp;
            int cnt = 0;

            while(cnt <= n && !pq.empty()) {

                int freq = pq.top();
                pq.pop();

                freq--;

                if(freq > 0)
                    temp.push_back(freq);

                cnt++;
            }

            for(int x : temp)
                pq.push(x);

            if(pq.empty())
                time += cnt;
            else
                time += n + 1;
        }

        return time;
    }
};