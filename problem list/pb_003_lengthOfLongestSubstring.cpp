#include <iostream>
#include <unordered_set>  // More efficient than set for lookups
#include <string>
#include <algorithm>  // For max function
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }   
};

int main() {
    Solution solution;
    string input = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(input);
    cout << "result: " << result << endl;
    return 0;
}