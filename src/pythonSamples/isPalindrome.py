class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) < 1:
            return True
        alphanumeric = "".join(c.lower() for c in s if c.isalnum())
        # print(alphanumeric)
        return self.isPalindromeHelper(0,len(alphanumeric)-1,alphanumeric)

    def isPalindromeHelper(self,left,right,cleanStr):
        if left > right:
            return True
        if cleanStr[left] == cleanStr[right] and self.isPalindromeHelper(left+1,right-1,cleanStr):
            return True
        return False
