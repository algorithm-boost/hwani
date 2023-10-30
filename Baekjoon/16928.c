/*
* 백준 16928번 골드5
* 문제: 뱀과 사다리 게임
* 링크: https://www.acmicpc.net/problem/16928
* 사용한 알고리즘: DP -> BFS, 두가지로 풀이함.
* 접근 방식: 처음엔 시간 제한도 있고 뭔가 dp스러워 보이길래 DP로 풀었다. 완전 탐색을 하는 경우의 수를 먼저 떠올렸다가, DP로 경우의 수를 줄이면 괜찮을 것 같다고 생각했다.
* 그런데 실제로 적용해보니 생각지 못한 케이스가 몇 개 있었다. 예를들어 나는 뱀은 아예 안타고 가면 최선일 거라고 생각했는데, 뱀을 타더라도 최적이 나올 수 있다.(머리로만 대충 생각하지 말고 앞으론 종이에 그려가면서 생각하자..)
* 그래서 DP 방식의 풀이는 반례들 보면서 끼워 맞추느라 조건문이 비교적 복잡해서 그래프 방식으로 다시 풀었다.
* 그래프 방식은 주사위를 굴려서 갈 수 있는 모든 정점을 큐에 넣으며 BFS 방식으로 풀이했다.
* (처음엔 이 방식에서도 주사위가 6이거나 6 이내에 뱀과 사다리가 있는 경우만 정점으로 고려했었는데, 그 방식도 옳지 못하다. 다른 경우에 최적이 있을 수 있다. 참고 -> https://www.acmicpc.net/board/view/112842
* 뭐 어쨌든.. BFS가 풀이는 좀 더 간단하고 좋은 듯.. 만족
* (지난 주 토요일에 DP 방식으로 풀어봤다가, 오늘 BFS 방식으로도 풀어보고 한꺼번에 올립니다.)
*/

/******************** 첫번째 풀이(DP) ********************/
#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    int dp[101] = {0, 0, 1, 1, 1, 1, 1, 1, 0, };
    int ladder[101] = {0,};
    int snakes[101] = {0,};
    
    int x,y;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        ladder[x] = y;
    }
    for (int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        snakes[x] = y;
    }
    
    for (int i=2; i<7; i++) {
        if (ladder[i]) {
            dp[ladder[i]] = dp[i];
            continue;
        }
        if (snakes[i]) {
            dp[i] = 0;
            continue;
        }
    }
    
    for (int i=7; i<101; i++) {
        int minOffset, j = 1;
        for (;j<=6; j++) {
            if (dp[i-j] != 0) {
                minOffset = j;
                break;
            }
        }
        if (j==7) continue;
        
        for (; j<=6; j++)
            if ((dp[i-j] != 0) && (dp[i-minOffset] > dp[i-j]))
                minOffset = j;
        
        if ((dp[i] != 0 && dp[i] > dp[i-minOffset]+1) || dp[i] == 0)
            dp[i] = dp[i-minOffset]+1;
        
        if (ladder[i])
            dp[ladder[i]] = dp[i];
        if (snakes[i]) {
            if (dp[snakes[i]] > dp[i]) {
                dp[snakes[i]] = dp[i];
                dp[i] = 0;
                i = snakes[i];
                continue;
            }
            dp[i]= 0;
        }
    }
    
    printf("%d", dp[100]);
    
    return 0;
}





/******************** 두번째 풀이(BFS) ********************/
#include <stdio.h>
#include <stdlib.h>

/***for queue***/
typedef struct {
    int data;
    int depth;
} element;
element queue[100000];
int front = -1, rear = -1;
void insert(int data, int depth);
element delete();
int queueEmpty();

int bfs(int startPos, int ladder[], int snakes[]);
void insertOneDicePosibilities(element pos, int visited[], int ladder[], int snakes[]);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    int ladder[111] = {0,};
    int snakes[111] = {0,};
    
    int x,y;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        ladder[x] = y;
    }
    for (int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        snakes[x] = y;
    }
    
    int count = bfs(1, ladder, snakes);
    printf("%d", count);
    
    return 0;
}

int bfs(int startPos, int ladder[], int snakes[]) {
    int visited[111] = {0,};
    
    visited[startPos] = 1;
    insert(startPos, 0);
    
    while (!queueEmpty()) {
        element temp = delete();
        if (temp.data >= 100) return temp.depth;
        insertOneDicePosibilities(temp, visited, ladder, snakes);
    }
    return -1;
}

void insertOneDicePosibilities(element pos, int visited[], int ladder[], int snakes[]) {
    for (int i=1; i<=6; i++) {
        int nextPos = pos.data+i;
        if (visited[nextPos]) continue;
        
        if (ladder[nextPos] && !visited[ladder[nextPos]]) {
            visited[ladder[nextPos]] = 1;
            insert(ladder[nextPos], pos.depth+1);
        }
        else if (snakes[nextPos] && !visited[snakes[nextPos]]) {
            visited[snakes[nextPos]] = 1;
            insert(snakes[nextPos], pos.depth+1);
        }
        else if (!ladder[nextPos] && !snakes[nextPos]) {
            visited[nextPos] = 1;
            insert(nextPos, pos.depth+1);
        }
    }
}

void insert(int data, int depth) {
    element ele;
    ele.data = data; ele.depth = depth;
    queue[++rear] = ele;
}
element delete() {
    if (front == rear) {
        fprintf(stderr, "cannot delete from empty queue");
        exit(EXIT_FAILURE);
    }
    return queue[++front];
}
int queueEmpty() {
    return front == rear;
}

