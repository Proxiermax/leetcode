#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        for (int j = 2; j <= n; j += 2) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    
                    if (matches(s, p, i, j-1)) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    if (matches(s, p, i, j)) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
    
private:
    bool matches(const string& s, const string& p, int i, int j) {
        return p[j-1] == '.' || s[i-1] == p[j-1];
    }
};

int main() {
    Solution solution;
    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";
    string s3 = "ab", p3 = ".*";
    string s4 = "aab", p4 = "c*a*b";
    string s5 = "mississippi", p5 = "mis*is*p*.";
    
    cout << solution.isMatch(s1, p1) << endl; // 0 (false)
    cout << solution.isMatch(s2, p2) << endl; // 1 (true)
    cout << solution.isMatch(s3, p3) << endl; // 1 (true)
    cout << solution.isMatch(s4, p4) << endl; // 1 (true)
    cout << solution.isMatch(s5, p5) << endl; // 0 (false)
    
    return 0;
}