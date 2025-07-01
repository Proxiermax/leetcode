#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman = "";

        string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        roman += thousands[num / 1000];
        num %= 1000;
        roman += hundreds[num / 100];
        num %= 100;
        roman += tens[num / 10];
        num %= 10;
        roman += units[num];
        num = 0;

        return roman;
    } 
};

int main() {
    Solution solution;
    int num1 = 3; // "III"
    int num2 = 4; // "IV"
    int num3 = 9; // "IX"
    int num4 = 58; // "LVIII"
    int num5 = 1994; // "MCMXCIV"
    int num6 = 3999; // "MMMCMXCIX"

    cout << solution.intToRoman(num1) << endl; // III
    cout << solution.intToRoman(num2) << endl; // IV
    cout << solution.intToRoman(num3) << endl; // IX
    cout << solution.intToRoman(num4) << endl; // LVIII
    cout << solution.intToRoman(num5) << endl; // MCMXCIV
    cout << solution.intToRoman(num6) << endl; // MMMCMXCIX

    return 0;
}