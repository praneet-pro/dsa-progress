class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;

        for(string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            
            if(m.contains(key)) ans[m[key]].push_back(s);
            else {
                m[key] = ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};