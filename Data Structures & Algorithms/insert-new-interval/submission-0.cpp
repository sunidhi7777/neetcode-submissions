/*class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& nu) {
        int n = inter.size();
        int i ;
        for(i=0;i<n;i++){
            if(inter[i][0]< nu[0]){
                if(inter[i][1] < nu[0])
                continue ;
                int start = inter[i][0] ;
                while(inter[i][1]<nu[1]){
                    inter.erase(inter.begin() + i); 
                }
                inter[i][0] = start ;

            }else{
                if(inter[i][0] > nu[1]){
                    inter.insert(inter.begin() + i, nu); 
                    return inter ;
                }
                int start = nu[0] ;
                while(inter[i][1]<nu[1]){
                    inter.erase(inter.begin() + i); 
                }
                inter[i][0] = start ;
            }
        }
        return inter ;
    }
};*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& nu) {

        int i = 0;

        while (i < inter.size()) {

            // Current interval is completely before new interval
            if (inter[i][1] < nu[0]) {
                i++;
            }

            // Current interval is completely after new interval
            else if (inter[i][0] > nu[1]) {
                inter.insert(inter.begin() + i, nu);
                return inter;
            }

            // Overlap
            else {
                nu[0] = min(nu[0], inter[i][0]);
                nu[1] = max(nu[1], inter[i][1]);

                inter.erase(inter.begin() + i);
                // Don't increment i because a new interval has shifted into index i
            }
        }

        // New interval belongs at the end
        inter.push_back(nu);

        return inter;
    }
};