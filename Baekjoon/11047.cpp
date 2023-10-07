/*
* 백준 11047번 실버4
* 문제: 동전 0
* 링크: https://www.acmicpc.net/problem/9461
* 사용한 알고리즘: greedy
* 접근 방식: 각 숫자들이 배수 관계라는 조건이 있길래 유형이 수학인가 싶었음
*          잘 생각해보니 해당 조건 때문에 greedy choice property를 만족한다는 것을 알고, greedy를 적용하여 해결
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    int values[10];
    for (int i=0; i<N; i++) {
        cin >> values[i];
    }
    
    int count = 0;
    for (int i=N-1; i>-1; i--) {
        while (K && K >= values[i]) {
            count++;
            K -= values[i];
        }
    }
    
    cout << count;
    
    return 0;
}
