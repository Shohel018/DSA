/*
Problem:
Squares of a Sorted Array

Difficulty:
Easy

Link:
https://leetcode.com/problems/squares-of-a-sorted-array/

Approach:
Two Pointers

Time:
O(n)

Space:
O(n)

Tags:
Array, Two Pointers

Pattern:
Opposite Direction Two Pointers

Explanation:
Since the array is sorted, the largest square can come from either
the most negative number (left side) or the largest positive number
(right side).

Use two pointers:
- left at the beginning
- right at the end

Compare the squares of nums[left] and nums[right].
Place the larger square at the end of the result array and move the
corresponding pointer inward.

Repeat until all elements are processed.

This avoids sorting after squaring and achieves O(n) time complexity.
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> res(n);

        int i = 0;
        int j = n - 1;
        int k = n - 1;

        while (i <= j)
        {

            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];

            if (left > right)
            {
                res[k] = left;
                i++;
            }
            else
            {
                res[k] = right;
                j--;
            }

            k--;
        }

        return res;
    }
};