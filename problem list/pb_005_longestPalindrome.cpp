#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.length() == 1) return s;
        
        int start = 0, maxLength = 1;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes
            expandAroundCenter(i, i);
            // Even length palindromes
            expandAroundCenter(i, i + 1);
        }
        
        return s.substr(start, maxLength);
    }
};

int main() {
    cout << "Hello World" << endl;
    Solution solution;
    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "a";
    
    cout << "Longest palindrome in \"" << s1 << "\": " << solution.longestPalindrome(s1) << endl;
    cout << "Longest palindrome in \"" << s2 << "\": " << solution.longestPalindrome(s2) << endl;
    cout << "Longest palindrome in \"" << s3 << "\": " << solution.longestPalindrome(s3) << endl;

    return 0;
}