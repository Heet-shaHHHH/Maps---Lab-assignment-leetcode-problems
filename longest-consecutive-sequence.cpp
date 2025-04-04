#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> numMap; // Stores number as key and its sequence length as value
    int longest = 0;
    
    for (int num : nums) {
        if (numMap.find(num) == numMap.end()) { // Only process unseen numbers
            int left = numMap.count(num - 1) ? numMap[num - 1] : 0;
            int right = numMap.count(num + 1) ? numMap[num + 1] : 0;
            
            int sequenceLength = left + right + 1;
            numMap[num] = sequenceLength;
            
            // Update the boundary values of the sequence
            numMap[num - left] = sequenceLength;
            numMap[num + right] = sequenceLength;
            
            longest = max(longest, sequenceLength);
        }
    }
    
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl;
    return 0;
}
