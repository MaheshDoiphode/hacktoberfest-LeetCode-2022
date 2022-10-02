class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        if str == "":
            return 0
        str = str.split()[0]
        num = ""
        i=0
        if str[0] == "+" or str[0] == "-":
            num = num + str[0]
            i=1
        for element in str[i:]:
            try:
                temp = int(element)
                num = num + element
            except:
                break
        if num == "":
            return 0
        elif num == "+" or num == "-":
            return 0
        a = int(num)
        
        if a <= -2147483648: 
            a = -2147483648
        if a >= 2147483648:
            a = 2147483647
        return a