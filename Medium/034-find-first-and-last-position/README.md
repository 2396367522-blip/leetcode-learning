# 34. Find First and Last Position
## Difficulty
Medium

## Approach
BInary Search.

## Explanation
传统的二分查找在找到目标值 target 时就直接返回下标了。但这道题中 target 可能重复出现，我们需要分别求出：
第一个等于 target 的位置（左边界）
最后一个等于 target 的位置（右边界）
我们可以拆分为两次二分查找：
1. 查找左边界（第一个 target）
当 nums[mid] == target 时，说明找到了目标值，但左边可能还有相同的元素。因此我们不停止，记录当前位置 first = mid，并将右指针移动到 mid - 1，继续向左半部分寻找。
当 nums[mid] < target 时，说明目标值在右边，令 left = mid + 1。
当 nums[mid] > target 时，说明目标值在左边，令 right = mid - 1。
2. 查找右边界（最后一个 target）
当 nums[mid] == target 时，说明找到了目标值，但右边可能还有相同的元素。因此我们不停止，记录当前位置 last = mid，并将左指针移动到 mid + 1，继续向右半部分寻找。
当 nums[mid] < target 时，令 left = mid + 1。
当 nums[mid] > target 时，令 right = mid - 1。

## Complexity
Time Complexity:
O(log n)
Space Complexity:
O(1)
