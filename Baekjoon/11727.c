/*
* 백준 11727번 실버3
* 문제: 2xn 타일링 2
* 링크: https://www.acmicpc.net/problem/11727
* 사용한 알고리즘: Dynamic programming
* 접근 방식: https://github.com/algorithm-boost/hwani/issues/3
*           위 링크와 똑같이 접근함. 트리 형태로 경우의 수를 구해보니(이번엔 1과 2로만 이루어진 게 아니라 2가 두가지 형태가 될 수 있어서 그 점을 고려하여 그림) 점화식이 dp[i] = dp[i-1] + dp[i-2]*2 임을 알 수 있었음.
*           나머지 연산 분배 법칙에 의해 아래와 같이 구현함.
*/

#include <stdio.h>

int main()
{
    int dp[1001] = {0,1,3};
    
    int N;
    scanf("%d", &N);
    
    for (int i=3; i<=N; i++)
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    
    printf("%d", dp[N]);
    
    return 0;
}
