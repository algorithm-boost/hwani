/*
* 백준 17626번 실버3
* 문제: Four Squares
* 링크: https://www.acmicpc.net/problem/17626
* 사용한 알고리즘: Dynamic programming
* 접근 방식: dp로 접근해야겠다고 생각은 했다. 근데 어디서 경우의 수를 줄이는 게 좋을지 명확하지 않았다.
* 그리디하게 가장 큰 놈부터 선택했을 때 딱 맞아떨어지면 답인가? -> 잘 모르겠다. 작은 놈들끼리 뭉쳐서 더 작은 경우의 수로 될 수도 있을 것 같았다.
* 그래서 그냥 완전 탐색이지만 루트(n) 범위부터 탐색하도록 했고(제곱해야햐니까! 아 그리고 실제로 루트를 구하는 건 귀찮아서 그냥 2로 나눔), 탐색하는 범위 내에서 min 값을 찾도록만 해서 제출해봤다.
* 그랬더니 성공했다! (실패하면 시간 줄이는 방법을 좀 더 고민해보려했는데..)
* (다시보니 경우의 수가 1이 되면 나머지는 보지도 않고 반복문을 빠져나오게 하는 부분도 있으면 쪼끔 더 빠를듯)
*/

#include <stdio.h>

int dp[50001] = {0, 1, 2, 3, 1, 2, 0};

int main() {
    
    int n;
    scanf("%d", &n);
    
    for (int i=6; i<=n; i++) {
        int count = 0;
        for (int j=(i/2); j>=1; j--) {
            int squaredValue = j*j;
            if (squaredValue > i) continue;
            count = 1 + dp[i - squaredValue];
            if (!dp[i]) dp[i] = count;
            else if (dp[i] > count) dp[i] = count;
        }
    }
    
    printf("%d", dp[n]);
    
    return 0;
}
