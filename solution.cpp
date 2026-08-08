#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> num_map;

    // 性能优化点：预分配内存，防止频繁重哈希（Rehash）
    num_map.reserve(nums.size());

    for(int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];

        // 1. 安全查找：使用 find() 检查数值是否存在
        auto it = num_map.find(complement);
        if(it != num_map.end()){
            return {it->second, i};
        }

        // 2. 写入数据：将当前数值与对应索引记录入映射表
        num_map[nums[i]] = i;
        // 也可以写成：num_map.emplace(nums[i], i); // 使用 emplace() 直接构造键值对，避免不必要的拷贝
    }
    return {};
}

int main(){
    vector<int> nums = {1, 10, 2, 5, 8};
    int target = 18;

    vector<int> result = twoSum(nums, target);

    if(!result.empty()){
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}