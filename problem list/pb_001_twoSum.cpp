#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                };
            };
        };
        return result;
    };
};

int main() {
    cout << "Hello World" << endl;
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << "nums:";
    for (int num : nums) {
        cout << " " << num;
    }
    cout << endl;
    cout << "target:" << target << endl;

    return 0;
}