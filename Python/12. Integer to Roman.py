class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        result = ""
        numberOfM = num/1000
        while numberOfM:
            result = result + "M"
            numberOfM = numberOfM - 1
        num = num%1000
        numberOfC = num/100
        if numberOfC == 4:
            result = result + "CD"
            numberOfC = numberOfC - 4
        if numberOfC >= 5:
            if numberOfC == 9:
                result = result + "CM"
                numberOfC = numberOfC - 9
            else:
                result = result + "D"
                numberOfC = numberOfC - 5
        while numberOfC:    
            result = result + "C"
            numberOfC = numberOfC - 1
        num = num%100
        numberOfX = num / 10
        if numberOfX == 4:
            result = result + "XL"
            numberOfX = numberOfX - 4
        if numberOfX >= 5:
            if numberOfX == 9:
                result = result + "XC"
                numberOfX = numberOfX - 9
            else:
                result = result + "L"
                numberOfX = numberOfX - 5
        while numberOfX:    
            result = result + "X"
            numberOfX = numberOfX - 1
        num = num%10
        if num == 4:
            result = result + "IV"
            num = num - 4
        if num >= 5:
            if num == 9:
                result = result + "IX"
                num = num - 9
            else:
                result = result + "V"
                num = num - 5
        while num:
            result = result + "I"
            num = num -1
        return result