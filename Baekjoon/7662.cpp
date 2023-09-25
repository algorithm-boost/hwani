/*
* 백준 7662번 골드4
* 문제: 이중 우선순위 큐
* 링크: https://www.acmicpc.net/problem/7662
* 사용한 알고리즘: min max heap
* 접근 방식: https://please-amend.tistory.com/entry/%EB%B0%B1%EC%A4%80-7662%EB%B2%88-%EC%9D%B4%EC%A4%91-%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84-%ED%81%90-Ccpp-%ED%92%80%EC%9D%B4
* 하.. 이슈 빡세게 쓰다가 날아가서 그냥 여기 간단하게 작성합니다 ㅠㅠ 처음에 BST로 접근하려했으나 worst case 고려하지 못하고 시간만 날렸다가 해답이 떠오르지 않아 결국 위 링크 참고하여 해결했습니다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;
map<int, int> count_element;  // soft delete? 비슷하게

void insert(int value) {
    min_heap.emplace(value);
    max_heap.emplace(value);
    count_element[value]++;
}

void deleteMin() {
    if (!min_heap.empty()){
        count_element[min_heap.top()]--;
        min_heap.pop();
    }
}

void deleteMax() {
    if (!max_heap.empty()){
        count_element[max_heap.top()]--;
        max_heap.pop();
    }
}

// 각 힙의 루트에 없는 애들이 있다면 아예 삭제시켜주기
void updateHeaps() {
    while (!min_heap.empty() && !count_element[min_heap.top()]) {
        min_heap.pop();
    }
    while (!max_heap.empty() && !count_element[max_heap.top()]) {
        max_heap.pop();
    }
}

void clearHeap() {
    while (!min_heap.empty())
        min_heap.pop();
    while (!max_heap.empty())
        max_heap.pop();
}


int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    int k, number;
    char command;
    
    
    for (int i=0; i<T; i++) {
        clearHeap();
        count_element.clear();
        
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> command >> number;
            switch (command) {
                case 'I': insert(number);
                          break;
                case 'D': if (number==-1)
                              deleteMin();
                          else
                              deleteMax();
                          updateHeaps();
                          break;
            }
        }
        // 결과 출력
        updateHeaps();
        if (min_heap.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top() << ' ' << min_heap.top() << '\n';
    }
    return 0;
}