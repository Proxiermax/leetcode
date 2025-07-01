#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        
        while (x != 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
            
            x /= 10;
        }
        
        return static_cast<int>(result);
    }
};

int main() {
    Solution solution;
    
    int test1 = 123;
    int test2 = -123;
    int test3 = 120;
    
    cout << "Original: " << test1 << ", Reversed: " << solution.reverse(test1) << endl;
    cout << "Original: " << test2 << ", Reversed: " << solution.reverse(test2) << endl;
    cout << "Original: " << test3 << ", Reversed: " << solution.reverse(test3) << endl;
    
    return 0;
}