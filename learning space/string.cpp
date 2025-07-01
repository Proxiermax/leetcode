#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "=== C++ STRING LIBRARY EXAMPLES ===" << endl << endl;
    
    // 1. STRING CONSTRUCTION
    cout << "1. STRING CONSTRUCTION:" << endl;
    string s1;                          // Empty string
    string s2("Hello");                 // From C-string
    string s3 = "World";               // Assignment from literal
    string s4(s2);                     // Copy constructor
    string s5(5, 'A');                 // 5 'A' characters: "AAAAA"
    string s6(s2, 1, 3);               // Substring from position 1, length 3: "ell"
    
    cout << "s1: '" << s1 << "'" << endl;
    cout << "s2: '" << s2 << "'" << endl;
    cout << "s3: '" << s3 << "'" << endl;
    cout << "s4: '" << s4 << "'" << endl;
    cout << "s5: '" << s5 << "'" << endl;
    cout << "s6: '" << s6 << "'" << endl << endl;
    
    // 2. STRING PROPERTIES
    cout << "2. STRING PROPERTIES:" << endl;
    string text = "Programming";
    cout << "text: '" << text << "'" << endl;
    cout << "Length: " << text.length() << endl;
    cout << "Size: " << text.size() << endl;
    cout << "Capacity: " << text.capacity() << endl;
    cout << "Empty?: " << text.empty() << endl;
    cout << "Max size: " << text.max_size() << endl << endl;
    
    // 3. CHARACTER ACCESS
    cout << "3. CHARACTER ACCESS:" << endl;
    cout << "text[0]: " << text[0] << endl;
    cout << "text.at(1): " << text.at(1) << endl;
    cout << "text.front(): " << text.front() << endl;
    cout << "text.back(): " << text.back() << endl;
    cout << "text.data(): " << text.data() << endl << endl;
    
    // 4. STRING MODIFICATION
    cout << "4. STRING MODIFICATION:" << endl;
    string modify = "Hello";
    cout << "Original: " << modify << endl;
    
    modify += " World";                 // Append
    cout << "After +=: " << modify << endl;
    
    modify.append("!");                 // Append method
    cout << "After append: " << modify << endl;
    
    modify.insert(5, " Beautiful");     // Insert at position
    cout << "After insert: " << modify << endl;
    
    modify.erase(5, 10);               // Erase from position 5, length 10
    cout << "After erase: " << modify << endl;
    
    modify.replace(6, 5, "C++");       // Replace from pos 6, length 5
    cout << "After replace: " << modify << endl;
    
    modify.clear();                    // Clear all
    cout << "After clear: '" << modify << "'" << endl << endl;
    
    // 5. STRING SEARCH
    cout << "5. STRING SEARCH:" << endl;
    string search = "Hello World Hello";
    cout << "Search string: '" << search << "'" << endl;
    
    size_t pos1 = search.find("Hello");
    cout << "First 'Hello' at: " << pos1 << endl;
    
    size_t pos2 = search.find("Hello", 1);  // Start from position 1
    cout << "Next 'Hello' at: " << pos2 << endl;
    
    size_t pos3 = search.rfind("Hello");    // Find from end
    cout << "Last 'Hello' at: " << pos3 << endl;
    
    size_t pos4 = search.find_first_of("Wor");
    cout << "First 'W', 'o', or 'r' at: " << pos4 << endl;
    
    size_t pos5 = search.find_last_of("o");
    cout << "Last 'o' at: " << pos5 << endl;
    
    size_t pos6 = search.find_first_not_of("Helo ");
    cout << "First char not in 'Helo ' at: " << pos6 << endl << endl;
    
    // 6. SUBSTRING OPERATIONS
    cout << "6. SUBSTRING OPERATIONS:" << endl;
    string original = "Programming in C++";
    cout << "Original: '" << original << "'" << endl;
    
    string sub1 = original.substr(0, 11);    // From 0, length 11
    cout << "substr(0, 11): '" << sub1 << "'" << endl;
    
    string sub2 = original.substr(15);       // From 15 to end
    cout << "substr(15): '" << sub2 << "'" << endl << endl;
    
    // 7. STRING COMPARISON
    cout << "7. STRING COMPARISON:" << endl;
    string str1 = "Apple";
    string str2 = "Banana";
    string str3 = "Apple";
    
    cout << "str1: '" << str1 << "', str2: '" << str2 << "', str3: '" << str3 << "'" << endl;
    cout << "str1 == str3: " << (str1 == str3) << endl;
    cout << "str1 < str2: " << (str1 < str2) << endl;
    cout << "str1.compare(str2): " << str1.compare(str2) << endl;
    cout << "str1.compare(str3): " << str1.compare(str3) << endl << endl;
    
    // 8. STRING CONVERSION
    cout << "8. STRING CONVERSION:" << endl;
    
    // Number to string
    int num = 123;
    double pi = 3.14159;
    string numStr = to_string(num);
    string piStr = to_string(pi);
    cout << "to_string(123): '" << numStr << "'" << endl;
    cout << "to_string(3.14159): '" << piStr << "'" << endl;
    
    // String to number
    string numberStr = "456";
    string floatStr = "7.89";
    int converted = stoi(numberStr);
    double convertedFloat = stod(floatStr);
    cout << "stoi('456'): " << converted << endl;
    cout << "stod('7.89'): " << convertedFloat << endl << endl;
    
    // 9. STRING ITERATORS
    cout << "9. STRING ITERATORS:" << endl;
    string iterate = "HELLO";
    cout << "Forward iteration: ";
    for (auto it = iterate.begin(); it != iterate.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Reverse iteration: ";
    for (auto it = iterate.rbegin(); it != iterate.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Range-based loop: ";
    for (char c : iterate) {
        cout << c << " ";
    }
    cout << endl << endl;
    
    // 10. STRING ALGORITHMS (with <algorithm>)
    cout << "10. STRING ALGORITHMS:" << endl;
    string algo = "hello world";
    cout << "Original: '" << algo << "'" << endl;
    
    // Transform to uppercase
    transform(algo.begin(), algo.end(), algo.begin(), ::toupper);
    cout << "Uppercase: '" << algo << "'" << endl;
    
    // Transform to lowercase
    transform(algo.begin(), algo.end(), algo.begin(), ::tolower);
    cout << "Lowercase: '" << algo << "'" << endl;
    
    // Reverse
    reverse(algo.begin(), algo.end());
    cout << "Reversed: '" << algo << "'" << endl;
    
    // Sort
    sort(algo.begin(), algo.end());
    cout << "Sorted: '" << algo << "'" << endl << endl;
    
    // 11. COMMON LEETCODE STRING OPERATIONS
    cout << "11. COMMON LEETCODE OPERATIONS:" << endl;
    
    // Check if palindrome
    string palindromeCheck = "racecar";
    string reversed = palindromeCheck;
    reverse(reversed.begin(), reversed.end());
    bool isPalindrome = (palindromeCheck == reversed);
    cout << "'" << palindromeCheck << "' is palindrome: " << isPalindrome << endl;
    
    // Count character frequency
    string freq = "programming";
    vector<int> charCount(26, 0);
    for (char c : freq) {
        if (c >= 'a' && c <= 'z') {
            charCount[c - 'a']++;
        }
    }
    cout << "Character frequencies in '" << freq << "':" << endl;
    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0) {
            cout << "  " << char('a' + i) << ": " << charCount[i] << endl;
        }
    }
    
    // Remove duplicates
    string duplicates = "aabbccdd";
    string unique;
    for (char c : duplicates) {
        if (unique.find(c) == string::npos) {
            unique += c;
        }
    }
    cout << "Original: '" << duplicates << "', Unique: '" << unique << "'" << endl;
    
    return 0;
}