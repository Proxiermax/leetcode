#include <iostream>
#include <vector>
#include <algorithm> // Required for std::copy (though not strictly necessary for push_back approach)

int main() {
    // Our two initial arrays (represented as std::vector)
    std::vector<int> arr1 = {1, 2, 4};
    std::vector<int> arr2 = {3, 5, 7};

    // Method 1a: Create a new vector and use push_back()
    std::vector<int> mergedArr1;
    // Add elements from arr1
    for (int x : arr1) {
        mergedArr1.push_back(x);
    }
    // Add elements from arr2
    for (int x : arr2) {
        mergedArr1.push_back(x);
    }

    std::cout << "Merged Array (using push_back): ";
    for (int x : mergedArr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Method 1b: Create a new vector and use insert() for efficiency
    // Clear mergedArr1 to reuse, or declare a new vector
    std::vector<int> mergedArr2;
    mergedArr2.reserve(arr1.size() + arr2.size()); // Optional: pre-allocate memory for efficiency

    // Insert all elements from arr1
    mergedArr2.insert(mergedArr2.end(), arr1.begin(), arr1.end());
    // Insert all elements from arr2
    mergedArr2.insert(mergedArr2.end(), arr2.begin(), arr2.end());

    std::cout << "Merged Array (using insert): ";
    for (int x : mergedArr2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Method 1c: Using a new vector and the copy constructor of vector (most concise if you want to extend one)
    std::vector<int> mergedArr3 = arr1; // mergedArr3 now contains {1, 2, 4}
    mergedArr3.insert(mergedArr3.end(), arr2.begin(), arr2.end());

    std::cout << "Merged Array (extending arr1): ";
    for (int x : mergedArr3) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}