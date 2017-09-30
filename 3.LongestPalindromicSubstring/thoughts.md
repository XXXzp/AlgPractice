# Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

## Ideas and Thoughts

We started from searching repeat words of the first letter and them expand it to both side. For each word in string, we do the same and break it if it is impossible to find a longer palindromic substring. So basically, this is solved in O(n).