#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution solution;
    
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;
    int test4 = 12321;
    
    cout << "Input: " << test1 << ", Output: " << solution.isPalindrome(test1) << endl;
    cout << "Input: " << test2 << ", Output: " << solution.isPalindrome(test2) << endl;
    cout << "Input: " << test3 << ", Output: " << solution.isPalindrome(test3) << endl;
    cout << "Input: " << test4 << ", Output: " << solution.isPalindrome(test4) << endl;
    
    return 0;
}