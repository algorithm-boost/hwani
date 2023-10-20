/*
* 백준 11726 실버3
* 문제: 2xn 타일링
* 링크: https://www.acmicpc.net/problem/11726
* 사용한 알고리즘: dynamic programming
* 접근 방식: https://github.com/algorithm-boost/hwani/issues/3
*/

#include <stdio.h>

int main() {
    int dp[1001] = {0,1,2,3,0,};
    
    int n;
    scanf("%d", &n);
    
    for (int i=4; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    
    printf("%d", dp[n]);
}
