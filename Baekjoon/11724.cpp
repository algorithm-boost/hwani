/*
* 백준 11724번 실버2
* 문제: 연결 요소의 개수
* 링크: https://www.acmicpc.net/problem/11724
* 사용한 알고리즘: DFS
* 접근 방식: 그래프 탐색인 건 당연한데 오랜만에 인접 리스트 방식으로 구현해볼까 하다가 귀찮아서 그냥 빠르고 편한 (공간은 많이 먹는) adjacency matrix로 구현
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adjMatrix, vector<bool> &visited, int x);

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;

    vector<vector<int>> adjMatrix(N+1, vector<int>(N+1, 0));
    vector<bool> visited(N+1, false);
    
    for (int i=0; i<M; i++) {
        int x,y;
        cin >> x >> y;
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }
    
    int count = 0;
    
    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        count++;
        dfs(adjMatrix, visited, i);
    }
    
    cout << count;

    return 0;
}

void dfs(vector<vector<int>> &adjMatrix, vector<bool> &visited, int x) {
    if (visited[x])
        return;

    visited[x] = true;
    for (int i=1; i<adjMatrix.size(); i++) {
        if (!adjMatrix[x][i]) continue;
        int nx = i;
        if (visited[nx]) continue;
        dfs(adjMatrix, visited, nx);
    }
}
