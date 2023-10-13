/*
* 백준 11399번 실버4
* 문제: ATM
* 링크: https://www.acmicpc.net/problem/11399
* 사용한 알고리즘: 정렬, 그리디
* 접근 방식: 보자마자 OS 스케줄링 방법 중 Shortest Job First (SJF)가 생각나서 그대로 적용시켰다! 그리디로 풀 수 있을 것 같아서 그냥 정렬시켜버림.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    
    cin >> N;
    vector<int> p(N);
    for (int i=0; i<N; i++) {
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());
    
    vector<int> accum(p);
    int sum = p[0];
    for (int i=1; i<N; i++) {
        accum[i] += accum[i-1];
        sum += accum[i];
    }
    
    cout << sum;

    return 0;
}
