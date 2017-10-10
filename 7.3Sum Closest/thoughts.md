# 3Sum Closest

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

## Ideas and Thoughts

Seeing this problem my first thought is that this should be solved by dynamic program. But it is hard to deal with the confict between two transactions timing. Then I check others ideas and I find out that someone made a solution tactfully. 

The code itself is quite straight forward and use the basic idea of dynamic program. It is working with each price in price vector and see if the price should be a buying or selling day for two transaction by calculating the max between previous value and the lately calculated value. The solution's idea is just as natural as normal people making decision and the complexity of time is O(n) with constant space cost.

