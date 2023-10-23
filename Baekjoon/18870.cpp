/*
* 백준 18870 실버2
* 문제: 좌표 압축
* 링크: https://www.acmicpc.net/problem/18870
* 사용한 알고리즘: sorting
* 접근 방식: 정렬하면 작은 값들의 개수를 쉽게 찾을 수 있어서 일단 정렬하고, 같은 값들에 대해 한번 더 처리함
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct element {
    int index;
    int value;
    int compressedValue;
};

bool comp(element a, element b);

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 입력
    vector<element> numbers(N);
    for (int i=0; i<N; i++) {
        numbers[i].index = i;
        cin >> numbers[i].value;
    }
    
    // 입력값 기준 정렬
    sort(numbers.begin(), numbers.end(), comp);
    
    // 압축 결과 계산
    numbers[0].compressedValue = 0;
    for (int i=1; i<N; i++) {
        int cond = ((numbers[i].value == numbers[i-1].value) ? 1 : 0);
        switch(cond) {
            case 1:
                numbers[i].compressedValue = numbers[i-1].compressedValue;
                break;
            case 0:
                numbers[i].compressedValue = numbers[i-1].compressedValue + 1;
                break;
        }
    }
    
    // 결과 출력 위해 기존 index 값에 따라 result에 재정렬
    vector<int> result(N);
    for (int i=0; i<N; i++) {
        int index = numbers[i].index;
        int compressedValue = numbers[i].compressedValue;
        result[index] = compressedValue;
    }
    
    for (int i=0; i<N; i++)
        cout << result[i] << ' ';

    return 0;
}

bool comp(element a, element b) {
    return a.value < b.value;
}
