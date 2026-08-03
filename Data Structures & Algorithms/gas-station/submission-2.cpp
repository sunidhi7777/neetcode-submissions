class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int gassum = accumulate(gas.begin(), gas.end(), 0);
        int costsum = accumulate(cost.begin(), cost.end(), 0);

        if(costsum > gassum)
            return -1;

        int tank = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){

            tank += gas[i] - cost[i];

            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};
    