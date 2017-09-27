# AlgPractice

## Something About this repo

I create this repo in order to backup my code practice. And of course, I will save solutions for problems in seperate folder.

## Problems Menu

#### 1. Substring without repeating

Given a string, find the length of the longest substring without repeating characters.

#### 2. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#### 3.Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

#### 4.ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#### 5.atoi

Implement atoi to convert a string to an integer.

## Ideas for Problems

#### 1.Substring without repeating

Make use of the ascii value of char. Use a vector to record the position, and then get the substring length by subtracting the index value.

#### 2.Median of Two Sorted Arrays

Using Binary Partition to reduce the array to a small size, then use std::sort to get the median. Easy to understand and fair speed. But I think the standard solution in LeetCode did a better job in speed, though it is tough to understand.

#### 3.Longest Palindromic Substring

We started from searching repeat words of the first letter and them expand it to both side. For each word in string, we do the same and break it if it is impossible to find a longer palindromic substring. So basically, this is solved in O(n).

#### 4.ZigZag Conversion

It is simply a index calculating work. I calculate the index in the order of the result. But it turns out that my algorithm is pretty slow. I think it is because I have to calculate every element's index, but I think the run time is acceptable.

#### 5. atoi

This should be the most boring problem that I had work on by now. Consider all possible weird input is the main challenge.