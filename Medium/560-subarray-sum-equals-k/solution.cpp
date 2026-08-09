#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    unordered_map<int, int> prefix_counts;

    prefix_counts.reserve(nums.size() + 1);

    prefix_counts[0] = 1;

    int current_sum = 0;
    int count = 0;

    for(int num : nums){
        current_sum += num;

        int target = current_sum - k;
        auto it = prefix_counts.find(target);
        if(it != prefix_counts.end()){
            count += it->second;
        }

        prefix_counts[current_sum]++;
    }

    return count;
}

int main(){
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
