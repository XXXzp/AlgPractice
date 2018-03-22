# 3Sum Closest

Given two strings which consist of 'a' and 'b' only, we can calculate the number of different character between them. For example, we have 'aab' and 'abb' then the distance between them is 1 because of the difference in the second digit. 
The main goal is to compute the distance between one source string and template. Whereas the source string is always longer than the template string, you should compute the sum of the distances between |s|-|t|+1 substring of source string  and template string.

Note that 0<|t|<=|s|<=10^5

``` 
    For example, given source string 'abba', and template string 'ab'.

    The result is 0 + 1 + 2 = 3.
```

## Ideas and Thoughts
the basic idea is quite simple. Just compute the distance between every substring and template. However, if you get the string and compare them directly the cost of time is huge. Given that there are only two possible character in the string, we should convert the string into bitset, and accelerate the computation with XOR operation.