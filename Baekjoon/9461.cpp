/*
* 백준 9461번 실버3
* 문제: 파도반 수열
* 링크: https://www.acmicpc.net/problem/9461
* 사용한 알고리즘: dp
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    long long int memo[101] ={0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
    
    for (int i=11; i<101; i++) {
        memo[i] = memo[i-1] + memo[i-5];
    }
    
    for (int i=0; i<T; i++) {
        int n;
        cin >> n;
        
        cout << memo[n] << '\n';
    }
    
    return 0;
}
