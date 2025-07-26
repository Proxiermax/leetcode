#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         int closestSum = nums[0] + nums[1] + nums[2]; 
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < n - 2; i++) {
//             int j = i + 1;
//             int k = n - 1;

//             while (j < k) {
//                 int currentSum = nums[i] + nums[j] + nums[k];

//                 if (abs(currentSum - target) < abs(closestSum - target)) {
//                     closestSum = currentSum;
//                 }

//                 if (currentSum < target) {
//                     j++; 
//                 } else if (currentSum > target) {
//                     k--;
//                 } else {
//                     return target;
//                 }
//             }
//         }

//         return closestSum;
//     }
// };

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int curr = nums[i] + nums[j] + nums[k];
                    if (abs(curr - target) < abs(closest - target)) {
                        closest = curr;
                    }
                }
            }
        }
        return closest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = sol.threeSumClosest(nums, target);
    std::cout << "The sum closest to target is: " << result << std::endl; // Expected output: 2
    return 0;
}