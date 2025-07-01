#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution solution;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"ab", "a"};
    string result1 = solution.longestCommonPrefix(strs1);
    string result2 = solution.longestCommonPrefix(strs2);
    cout << "Longest Common Prefix: " << result1 << endl;
    cout << "Longest Common Prefix: " << result2 << endl;
    return 0;
}