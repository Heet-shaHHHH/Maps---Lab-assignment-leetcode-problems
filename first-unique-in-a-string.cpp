#include <iostream>
#include <string>
#include <map>

using namespace std;

int firstUniqChar(string s) {
    map<char, int> charCount; // Map to store character frequencies
    
    // First pass: Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }
    
    // Second pass: Find the first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }
    
    return -1; // No unique character found
}

int main() {
    string s = "leetcode";
    cout << "First unique character index: " << firstUniqChar(s) << endl;
    return 0;
}
