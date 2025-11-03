#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == result.back()[2]) left++;
                        while (left < right && nums[right] == result.back()[3]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < n - 2 && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < n - 3 && nums[i + 1] == nums[i]) i++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);
    
    cout << "Found quadruplets:" << endl;
    for (const auto& quad : result) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]" << endl;
    }
    
    return 0;
}