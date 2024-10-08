class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        std::string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) 
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};