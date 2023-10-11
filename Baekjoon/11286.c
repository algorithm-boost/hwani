/*
* 백준 11286번 실버1
* 문제: 절댓값 힙
* 링크: https://www.acmicpc.net/problem/11286
* 사용한 알고리즘: min heap 직접 구현, 구조체를 이용해 두가지 기준으로 정렬
*/

#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

struct node {
    int value;
    unsigned int absoluteValue;
};
typedef struct node node;

node minHeap[100001];
int n = 0;

int pop();

void insert(int value);

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

int pop() {
    if (n <= 0)
        return 0;
    
    int result = minHeap[1].value;
    
    minHeap[1] = minHeap[n--];
    
    for (int i=1; i<=n;) {
        int indexLeftChild = i*2;
        int indexRightChild = i*2 + 1;
        
        int indexLesserChild = -1;
        if (indexRightChild <= n) {
            node leftChild = minHeap[indexLeftChild];
            node rightChild = minHeap[indexRightChild];
            if (leftChild.absoluteValue < rightChild.absoluteValue)
                indexLesserChild = indexLeftChild;
            else if (leftChild.absoluteValue > rightChild.absoluteValue)
                indexLesserChild = indexRightChild;
            // if same absolute value
            else if (leftChild.value < rightChild.value)
                indexLesserChild = indexLeftChild;
            else if (leftChild.value >= rightChild.value)
                indexLesserChild = indexRightChild;
        }
        else if (indexLeftChild <= n) {
            indexLesserChild = indexLeftChild;
        }
        else {
            break;
        }
        
        node temp;
        if (minHeap[i].absoluteValue > minHeap[indexLesserChild].absoluteValue)
            SWAP(minHeap[i], minHeap[indexLesserChild], temp);
        else if ((minHeap[i].absoluteValue == minHeap[indexLesserChild].absoluteValue) &&
                (minHeap[i].value > minHeap[indexLesserChild].value))
            SWAP(minHeap[i], minHeap[indexLesserChild], temp);
        
        i = indexLesserChild;
    }
    
    return result;
}

void insert(int value) {
    node temp;
    temp.value = value;
    temp.absoluteValue = (value>0) ? value : (-value);
    
    minHeap[++n] = temp;
    
    for (int i=n; i > 1; i/=2) {
        if (minHeap[i].absoluteValue < minHeap[i/2].absoluteValue)
            SWAP(minHeap[i], minHeap[i/2], temp);
        else if ((minHeap[i].absoluteValue == minHeap[i/2].absoluteValue) &&
                (minHeap[i].value < minHeap[i/2].value))
            SWAP(minHeap[i], minHeap[i/2], temp);
        else
            break;
    }
}
