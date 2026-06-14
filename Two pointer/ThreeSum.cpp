/*
Problem:
3Sum

Difficulty:
Medium

Link:
https://leetcode.com/problems/3sum/

Approach:
Sorting + Two Pointers

Time:
O(n²)

Space:
O(1) extra space (excluding output vector)

Explanation:
The goal is to find all unique triplets whose sum equals 0.

1. Sort the array.
2. Fix one element nums[i].
3. Find two numbers in the remaining array whose sum equals -nums[i].
4. Use two pointers:
   - l = i + 1
   - r = n - 1
5. Since the array is sorted:
   - If nums[l] + nums[r] > target, move r left.
   - If nums[l] + nums[r] < target, move l right.
   - If equal, store the triplet.

Handling Duplicates:
1. Skip duplicate values of nums[i] to avoid generating
   the same triplet multiple times.
2. After finding a valid triplet:
   - Move l forward past duplicates.
   - Move r backward past duplicates.

Key Insight:
Sorting transforms the problem from checking all O(n³)
triplets into an O(n²) solution using the Two Pointer technique.

Example:
nums = [-1,0,1,2,-1,-4]

Sorted:
[-4,-1,-1,0,1,2]

Valid Triplets:
[-1,-1,2]
[-1,0,1]
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = len - 1;

            int target = -nums[i];

            while (l < r)
            {
                int curr = nums[l] + nums[r];

                if (curr == target)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    // Skip duplicate second elements
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }

                    // Skip duplicate third elements
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                }
                else if (curr > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        return ans;
    }
};