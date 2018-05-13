class Solution(object):
    def rotateString(self, A, B):
        """
        :type A:str
        :type B:str
        :rtype:bool
        """
        if A == B:
            return True
        if len(A) != len(B):
            return False
        for i in range(len(B)):
            if A == B[i:]+B[:i]:
                return True
        return False

