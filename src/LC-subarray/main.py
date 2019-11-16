def longestCommonSubarray(arr1,arr2):
    rows = len(arr1)
    cols = len(arr2)
    dp = [[0 for r in range(rows)] for c in range(cols)]
    maxL =0

    for r in range (rows):
        for c in range(cols):
            if arr1[c] == arr2[r]:
                if r ==0 or c ==0:
                    dp[r][c] +=1
                else: 
                    dp[r][c] = 1 + dp[r-1][c-1]
                    maxL = cmp(maxL,dp[r][c])
    
    return maxL


def cmp(a,b):
    if a > b:
        return a 
    return b 