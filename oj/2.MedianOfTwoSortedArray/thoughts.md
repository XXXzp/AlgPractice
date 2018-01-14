#  Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

## Ideas and Thoughts

Using Binary Partition to reduce the array to a small size, then use std::sort to get the median. Easy to understand and fair speed. But I think the standard solution in LeetCode did a better job in speed, though it is tough to understand.