#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Map to store numbers and their indices
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement
        
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return the indices
        }
        
        numMap[nums[i]] = i; // Store the number and its index
    }
    
    return {}; // This should never be reached as per problem constraints
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
