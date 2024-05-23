class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        arr = []

        def helper(i: int): 
            if(i >= len(s)):
                ans.append(arr[:])
                return
            
            curstring = ""

            for j in range(i, len(s)):
                curstring += s[j]
                if(curstring == curstring[::-1]):
                    arr.append(curstring)
                    helper(j + 1)
                    arr.pop(-1)
        
        helper(0)
        return ans

        
