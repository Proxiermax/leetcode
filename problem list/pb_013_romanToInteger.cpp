#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<vector<int>> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int total = 0;
        int prevValue = 0;
        for (char c : s) {
            int currentValue = 0;
            for (const auto& pair : romanValues) {
                if (pair[0] == c) {
                    currentValue = pair[1];
                    break;
                }
            }
            // cout << "currentValue: " << currentValue << endl;
            // cout << "prevValue: " << prevValue << endl;
            if (currentValue > prevValue) {
                // cout << "Subtract: " << currentValue - 2 * prevValue << endl;
                total += currentValue - 2 * prevValue;
            } else {
                total += currentValue;
            }
            // cout << "------------------" << endl;
            prevValue = currentValue;
        }
        return total;
    }
};

int main() {
    Solution solution;
    string s1 = "III"; // 3
    string s2 = "IV"; // 4
    string s3 = "IX"; // 9
    string s4 = "LVIII"; // 58
    string s5 = "MCMXCIV"; // 1994
    string s6 = "MMMCMXCIX"; // 3999
    string s7 = "MMXXIV"; // 2023

    cout << solution.romanToInt(s1) << endl; // 3
    cout << solution.romanToInt(s2) << endl; // 4
    cout << solution.romanToInt(s3) << endl; // 9
    // cout << solution.romanToInt(s4) << endl; // 58
    // cout << solution.romanToInt(s5) << endl; // 1994
    // cout << solution.romanToInt(s6) << endl; // 3999
    // cout << solution.romanToInt(s7) << endl; // 2023

    return 0;
}