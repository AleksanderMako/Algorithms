class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        numAsList1 = list(num1)
        numAsList2 = list(num2)
        res=[]
        carry =0
    
        while len(numAsList1) or len(numAsList2):
            firstNumDigit = 0
            secondNuDigit=0
            if len(numAsList1) >0:
                firstNumDigit=int(numAsList1[-1])
                numAsList1.pop()
            else:
                firstNumDigit=0
        
            
            if len(numAsList2) >0 :
                secondNuDigit=int(numAsList2[-1])
                numAsList2.pop()
            else:
                secondNuDigit=0
        
            sumSoFar = firstNumDigit+secondNuDigit+carry
            #print(sumSoFar)
            res.append(str(sumSoFar%10))
            carry = sumSoFar//10
           # print(carry)
        res.reverse()
        return res
   
        