#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int current_area = h * w;

            max_area = max(max_area, current_area);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return max_area;
    }
};

int main () {
    Solution solution;
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};
    vector<int> height3 = {4,3,2,1,4};
    vector<int> height4 = {1,2,1};
    
    cout << solution.maxArea(height1) << endl; // 49
    cout << solution.maxArea(height2) << endl; // 1
    cout << solution.maxArea(height3) << endl; // 16
    cout << solution.maxArea(height4) << endl; // 2
    
    return 0;
}