class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            groups[s].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto it = groups.begin(); it != groups.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};
    

