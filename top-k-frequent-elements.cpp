#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freqMap; // Map to store frequencies of each number
    
    // Count frequency of each number
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Use a min-heap (priority queue) to store top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    for (auto& pair : freqMap) {
        minHeap.push({pair.second, pair.first}); // Push frequency and number
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove least frequent element
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
