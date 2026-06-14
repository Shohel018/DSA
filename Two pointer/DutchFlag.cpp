/*
Problem:
Sort Colors (Dutch National Flag Problem)

Difficulty:
Medium

Link:
https://leetcode.com/problems/sort-colors/

Approach:
Dutch National Flag Algorithm (Three Pointers)

Time:
O(n)

Space:
O(1)

Explanation:
Use three pointers:

- l (low): points to the position where the next 0 should be placed.
- mid: traverses the array and examines elements.
- r (high): points to the position where the next 2 should be placed.

Maintain the following regions:

0 ... l-1      => all 0s
l ... mid-1    => all 1s
mid ... r      => unknown elements
r+1 ... n-1    => all 2s

Rules:
1. If nums[mid] == 0:
   - Swap nums[l] and nums[mid]
   - Increment both l and mid

2. If nums[mid] == 1:
   - It is already in the correct region
   - Increment mid

3. If nums[mid] == 2:
   - Swap nums[mid] and nums[r]
   - Decrement r
   - Do NOT increment mid because the swapped element
     from the right side has not been processed yet

Continue until the unknown region becomes empty (mid > r).
*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0;
        int mid = 0;
        int r = nums.size() - 1;

        while (mid <= r)
        {
            if (nums[mid] == 0)
            {
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[r]);
                r--;
            }
            else
            {
                mid++;
            }
        }
    }
};