# 35. Search Insert Position
## Problem
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

## Idea
Binary Search.
Because the array is sorted, we can reduce the search range by half each time.

## Complexity
Time: O(log n)
Space: O(1)
