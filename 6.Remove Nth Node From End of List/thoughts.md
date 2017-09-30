# Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

## Ideas and Thoughts

This is an interesting one. From this problem, I reviewed the ideas of pointers and the idea of memory saving. At first, I was trying to solve it by using vector to store every ListNode pointer, and then access by index, but after seeing others solution, I found a better solution for this, using an idea of "Racing"(I personally name it this way). The discuss that I learnt this quoted below.

``` text
The difference between the final node and the to_be_delete node is N. And here the assumption is that n is always valid.

fast pointer points to the node which is N step away from the to_be_delete node.

slow pointer points to the to_be_delete node.

The algorithms is described as below:

Firstly, move fast pointer N step forward.

Secondly,move fast and slow pointers simultaneously one step a time forward till the fast pointer reach the end, which will cause the slow pointer points to the previous node of the to_be_delete node.

Finally, slow->next = slow->next->next.
```