/*
Problem:
Remove Duplicates from Sorted Array

Difficulty:
Easy

Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Approach:
Two Pointers

Time:
O(n)

Space:
O(1)

Explanation:
Use two pointers:
- One pointer (i) tracks the position of the last unique element.
- Another pointer (j) traverses the array.
Whenever nums[j] is different from nums[i], increment i and place nums[j] at nums[i].
At the end, the first (i + 1) elements of the array contain all unique elements in sorted order.
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
            {
                j++;
                continue;
            }
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
                j++;
            }
        }
        return i + 1;
    }
};