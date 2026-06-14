/*
Problem:
3Sum Closest

Difficulty:
Medium

Link:
https://leetcode.com/problems/3sum-closest/

Approach:
Sorting + Two Pointers

Time:
O(n²)

Space:
O(1) (excluding sorting)

Explanation:
The goal is to find three numbers whose sum is closest to the target.

1. Sort the array.
2. Fix one element nums[i].
3. Use two pointers:
   - l = i + 1
   - r = n - 1
4. Calculate:
      curr = nums[i] + nums[l] + nums[r]
5. If curr is closer to target than the best answer found so far,
   update 'closest'.
6. Since the array is sorted:
   - If curr < target, move l right to increase the sum.
   - If curr > target, move r left to decrease the sum.
   - If curr == target, return target immediately because
     no sum can be closer than an exact match.

Key Insight:
Sorting allows us to adjust the sum efficiently using two pointers
instead of checking all possible triplets.

Example:
nums = [-1, 2, 1, -4], target = 1

Sorted:
[-4, -1, 1, 2]

Possible sums:
-4 + -1 + 2 = -3
-4 + 1 + 2 = -1
-1 + 1 + 2 = 2

Closest sum to target (1) is 2.
*/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int curr = nums[i] + nums[l] + nums[r];

                if (abs(curr - target) < abs(closest - target))
                {
                    closest = curr;
                }

                if (curr < target)
                {
                    l++;
                }
                else if (curr > target)
                {
                    r--;
                }
                else
                {
                    return target;
                }
            }
        }

        return closest;
    }
};