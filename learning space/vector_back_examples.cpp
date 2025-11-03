#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "=== std::vector::back() Examples ===" << endl;
    
    // Example 1: Basic usage with integers
    cout << "\n1. Basic usage with integers:" << endl;
    vector<int> numbers = {10, 20, 30, 40, 50};
    cout << "Vector: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    cout << "Last element using back(): " << numbers.back() << endl;
    
    // Example 2: Modifying the last element
    cout << "\n2. Modifying the last element:" << endl;
    cout << "Before modification: " << numbers.back() << endl;
    numbers.back() = 99;  // Modify the last element
    cout << "After modification: " << numbers.back() << endl;
    cout << "Updated vector: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    
    // Example 3: Using back() with different data types
    cout << "\n3. Using with strings:" << endl;
    vector<string> words = {"Hello", "World", "C++", "Programming"};
    cout << "Last word: " << words.back() << endl;
    words.back() += "!";  // Append to the last string
    cout << "Modified last word: " << words.back() << endl;
    
    // Example 4: Common pattern - adding and accessing last element
    cout << "\n4. Add element and access with back():" << endl;
    vector<double> scores;
    scores.push_back(85.5);
    scores.push_back(92.3);
    scores.push_back(78.9);
    cout << "Latest score added: " << scores.back() << endl;
    
    // Example 5: Comparison with other access methods
    cout << "\n5. Comparison with other access methods:" << endl;
    vector<int> data = {1, 2, 3, 4, 5};
    cout << "Using back(): " << data.back() << endl;
    cout << "Using [size-1]: " << data[data.size() - 1] << endl;
    cout << "Using at(size-1): " << data.at(data.size() - 1) << endl;
    
    // Example 6: IMPORTANT - Don't use back() on empty vector
    cout << "\n6. Safety check for empty vector:" << endl;
    vector<int> empty_vector;
    if (!empty_vector.empty()) {
        cout << "Last element: " << empty_vector.back() << endl;
    } else {
        cout << "Vector is empty! Cannot use back()." << endl;
    }
    
    // Example 7: Using back() in algorithms/loops
    cout << "\n7. Using back() in practical scenarios:" << endl;
    vector<int> sequence = {1, 3, 6, 10};
    
    // Add next triangular number (pattern: add increasing numbers)
    int next_add = sequence.size() + 1;
    sequence.push_back(sequence.back() + next_add);
    cout << "Triangular sequence: ";
    for (int num : sequence) cout << num << " ";
    cout << endl;
    
    // Example 8: Working with vector of vectors (2D)
    cout << "\n8. With 2D vector:" << endl;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Last row's last element: " << matrix.back().back() << endl;
    
    // Add new element to last row
    matrix.back().push_back(10);
    cout << "After adding to last row: ";
    for (int val : matrix.back()) cout << val << " ";
    cout << endl;
    
    return 0;
}
