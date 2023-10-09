/*
* 백준 11279번 실버2
* 문제: 최대 힙
* 링크: https://www.acmicpc.net/problem/11279
* 사용한 알고리즘: max heap 직접 구현
*/

#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int max_heap[100001] = {0, };
int n = 0;

int pop() {
    if (n <= 0) {
        return 0;
    }
    
    int top = max_heap[1];
    
    max_heap[1] = max_heap[n];
    n--;
    
    for (int i=1; i<=n;) {
        int left_child = i*2;
        int right_child = i*2 + 1;
        
        int bigger_index;
        if (left_child <= n && right_child <= n)
            bigger_index = (max_heap[left_child] > max_heap[right_child]) ? left_child : right_child;
        else if (left_child <= n)
            bigger_index = left_child;
        else
            break;
        
        if (max_heap[bigger_index] > max_heap[i]) {
            int temp;
            SWAP(max_heap[bigger_index], max_heap[i], temp);
            i = bigger_index;
        }
        else {
            break;
        }
    }
    
    return top;
}

void insert(int value) {
    max_heap[++n] = value;
    
    for (int i=n; i != 1; i /= 2) {
        if (max_heap[i] > max_heap[i/2]) {
            int temp;
            SWAP(max_heap[i], max_heap[i/2], temp);
        }
        else
            break;
    }
}

int main()
{
    int N, x;
    
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
        scanf("%d", &x);
        
        if (x==0)
            printf("%d\n", pop());
        else
            insert(x);
    }
    
    return 0;
}
