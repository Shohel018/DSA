/*
Problem:
Count Triplets with Sum Smaller than Given Value

Difficulty:
Medium

Link:
https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/

Approach:
Sorting + Two Pointers

Time:
O(n²)

Space:
O(1) (excluding sorting)

Explanation:
The goal is to count the number of triplets such that:

    arr[i] + arr[j] + arr[k] < sum

Brute Force:
- Check every triplet.
- Time Complexity: O(n³)

Optimized Approach:
1. Sort the array.
2. Fix one element arr[i].
3. Use two pointers:
   - l = i + 1
   - r = n - 1
4. Calculate:

      curr = arr[i] + arr[l] + arr[r]

Case 1:
curr < sum

Since the array is sorted:

    arr[i] + arr[l] + arr[r] < sum

then all triplets formed by:
    arr[i], arr[l], arr[l+1...r]

will also satisfy the condition.

Therefore, we can count all of them at once:

    count += (r - l)

Then move l forward.

Case 2:
curr >= sum

The sum is too large, so move r left
to reduce the sum.

Key Insight:
When curr < sum, we don't count only one triplet.
We count (r - l) triplets because every element
between l+1 and r will also form a valid triplet
with arr[i] and arr[l].

Example:

arr = [1, 2, 3, 4, 5]
sum = 10

i = 0, l = 1, r = 4

1 + 2 + 5 = 8 < 10

Valid triplets:
(1,2,3)
(1,2,4)
(1,2,5)

Count = r - l = 4 - 1 = 3
*/

class Solution
{
public:
    int countTriplets(int sum, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int num = 0;
        int n = arr.size();

        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int curr = arr[i] + arr[l] + arr[r];

                if (curr < sum)
                {
                    num += (r - l);
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        return num;
    }
};