class Solution(object):
    def minimumLengthEncoding(self, words):
        """
        :type words:List[str]
        :rtype:int
        """
        result = ''
        for word in words:
            sub = word + '#'
            if sub not in result:
                result += sub
        print(result)
        return len(result)


Sol  = Solution()
str_list = ['asdd','as','dd','sd','sdd','asdd','as','hey','hey','ey','he']
print(Sol.minimumLengthEncoding(str_list))