/*
* 백준 9375번 실버3
* 문제: 패션왕 신해빈
* 링크: https://www.acmicpc.net/problem/9375
* 사용한 알고리즘: 수학, map
* 접근 방식: 처음에 별 생각없이 map 내에서 재귀로 조합 구하도록 구현했는데 시간 제한이 1초이길래 아예 수학적으로 계산하도록 해야겠다고 생각했습니다.(코드 버리기 싫어서 계속 최적화 해봤는데도 자꾸 시간초과..ㅠ)
*          옷 종류 수에 1 씩 더한 뒤 모두 곱하면 다 벗고 나가는 경우의 수까지 계산된 전체 경우의 수가 나온다는 걸 알고, 그냥 해당 값을 구해서 빼기 1을 해주는 식으로 풀이하였습니다.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef unordered_map<string, int> siMap;


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    vector<int> results;
    for (int i=0; i<T; i++) {
        int n;
        siMap countByType;
        int numberOfType = 0;
        
        cin >> n;
        for (int j=0; j<n; j++) {
            string clothesName, clothesType;
            cin >> clothesName >> clothesType;
            
            if (countByType.find(clothesType) == countByType.end()) {
                countByType.insert(make_pair(clothesType, 1));  // 실제 개수 +1 로 초기화
                numberOfType++;
            }
            countByType[clothesType]++;
        }
        
        int sum = 1;
        for (auto j = countByType.begin(); j != countByType.end(); j++) {
            sum *= j->second;
        }
        
        
        results.emplace_back(sum-1);
    }

    for (int i=0; i<results.size(); i++)
        cout << results[i] << '\n';
    
    return 0;
}
