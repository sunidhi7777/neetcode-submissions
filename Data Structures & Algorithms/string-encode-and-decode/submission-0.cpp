class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for(string s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while(i < s.size()) {

            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++;

            result.push_back(s.substr(j, len));

            i = j + len;
        }

        return result;
    }
};