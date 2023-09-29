/*
* 백준 9095번 실버3
* 문제: 1, 2, 3 더하기
* 링크: https://www.acmicpc.net/problem/9095
* 사용한 알고리즘: DP
* 접근 방식: https://github.com/algorithm-boost/hwani/issues/2
*/

#include <iostream>

using namespace std;

int memo[11] = {0,1,2,4,0,};  // index 0은 사용하지 않음

void dp(int n, int now, int & count);

int main()
{
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        int n;
        cin >> n;
        
        int count = 0;
        dp(n, 0, count);
        memo[n] = count;
        
        cout << count << '\n';
    }
    
    return 0;
}

// dp를 이용해 n에 대한 경우의 수 구하는 함수
void dp(int n, int now, int & count) {
    if (n == now) {
        count++;
        return;
    }
    else if (now > n)
        return;
    
    if (memo[n-now]) {
        count += memo[n-now];
        return;
    }
    
    dp(n, now+1, count);
    dp(n, now+2, count);
    dp(n, now+3, count);
}