class Solution(object):
    def reverseWords(self, s):
        """

        :type s:str
        :rtype: str
        """
        s_list = s.split(' ')
        result = ''
        for s in s_list:
            result += s[::-1]
            result += ' '
        result = result[:-1]
        return result

