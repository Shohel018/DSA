/*
Problem:
Remove Duplicates from Sorted Array II

Difficulty:
Medium

Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Approach:
Two Pointers

Time:
O(n)

Space:
O(1)

Explanation:
Use two pointers:
- Pointer k tracks the next position where a valid element should be placed.
- Pointer j traverses the array from left to right.

Since each element is allowed to appear at most twice:
- The first two elements can always be kept.
- For every element nums[j] starting from index 2, compare it with nums[k - 2].
- If nums[j] is different from nums[k - 2], it means adding nums[j] will not create more than two occurrences, so place it at nums[k] and increment k.
- If nums[j] is equal to nums[k - 2], keeping it would result in a third occurrence, so skip it.

At the end, the first k elements of the array contain the modified array where each element appears at most twice.
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int n = nums.size();

        if (n <= 2)
            return n;

        int k = 2;

        for (int j = 2; j < n; j++)
        {

            if (nums[j] != nums[k - 2])
            {
                nums[k] = nums[j];
                k++;
            }
        }

        return k;
    }
};