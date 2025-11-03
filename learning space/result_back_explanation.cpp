#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "=== Understanding result.back()[2] ===" << endl;
    
    // Create a 2D vector similar to your fourSum result
    vector<vector<int>> result;
    
    // Add some quadruplets (like in fourSum)
    result.push_back({1, 2, 3, 4});    // First quadruplet
    result.push_back({2, 3, 4, 5});    // Second quadruplet
    result.push_back({1, 3, 5, 7});    // Third quadruplet
    
    cout << "Current result contents:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "result[" << i << "]: ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nBreaking down result.back()[2]:" << endl;
    
    // Step 1: result.back() gets the last vector
    vector<int>& lastVector = result.back();
    cout << "1. result.back() returns the last vector: ";
    for (int val : lastVector) cout << val << " ";
    cout << endl;
    
    // Step 2: [2] accesses the element at index 2
    cout << "2. result.back()[2] = " << result.back()[2] << endl;
    cout << "   This is the 3rd element (index 2) of the last vector" << endl;
    
    cout << "\nIndex breakdown of the last vector:" << endl;
    cout << "   Index 0: " << result.back()[0] << endl;
    cout << "   Index 1: " << result.back()[1] << endl;
    cout << "   Index 2: " << result.back()[2] << " <- This is what result.back()[2] returns" << endl;
    cout << "   Index 3: " << result.back()[3] << endl;
    
    // In the context of fourSum
    cout << "\nIn your fourSum context:" << endl;
    cout << "When you add: {nums[i], nums[j], nums[left], nums[right]}" << endl;
    cout << "result.back()[0] = nums[i]     (first element)" << endl;
    cout << "result.back()[1] = nums[j]     (second element)" << endl;
    cout << "result.back()[2] = nums[left]  (third element)  <- This is what you're checking!" << endl;
    cout << "result.back()[3] = nums[right] (fourth element)" << endl;
    
    return 0;
}
