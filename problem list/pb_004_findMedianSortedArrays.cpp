#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
        
        while (i < leftArr.size()) {
            arr[k++] = leftArr[i++];
        }
        
        while (j < rightArr.size()) {
            arr[k++] = rightArr[j++];
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }   

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr = nums1;
        mergedArr.insert(mergedArr.end(), nums2.begin(), nums2.end());
        
        if (mergedArr.size() == 0) {
            return 0.0;
        }
        
        mergeSort(mergedArr, 0, mergedArr.size() - 1);
        
        cout << "Merged array: ";
        for (int x: mergedArr) {
            cout << x << " ";
        }
        cout << endl;
        
        int n = mergedArr.size();
        if (n % 2 == 1) {
            return mergedArr[n / 2];
        } else {
            return (mergedArr[n / 2 - 1] + mergedArr[n / 2]) / 2.0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << result << endl;

    return 0;
}