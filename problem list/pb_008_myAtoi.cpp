#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution solution;
    
    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    string test5 = "-91283472332";
    string test6 = "16gundam-6";
    
    cout << "Input: \"" << test1 << "\", Output: " << solution.myAtoi(test1) << endl;
    cout << "Input: \"" << test2 << "\", Output: " << solution.myAtoi(test2) << endl;
    cout << "Input: \"" << test3 << "\", Output: " << solution.myAtoi(test3) << endl;
    cout << "Input: \"" << test4 << "\", Output: " << solution.myAtoi(test4) << endl;
    cout << "Input: \"" << test5 << "\", Output: " << solution.myAtoi(test5) << endl;
    cout << "Input: \"" << test6 << "\", Output: " << solution.myAtoi(test6) << endl;
    
    return 0;
}