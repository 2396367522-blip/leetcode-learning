#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if(first == -1) return {-1, -1};
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst){
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                bound = mid;
                if(isFirst){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else if(nums[mid] < target){
                left = mid + 1; 
            }else{
                right = mid - 1;
            }
        }

        return bound;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    
    cout << "First and Last Position of Target: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}