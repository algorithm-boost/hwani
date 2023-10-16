/*
* 백준 11723번 실버5
* 문제: 집합
* 링크: https://www.acmicpc.net/problem/11723
* 사용한 알고리즘: 비트 마스킹
* 접근 방식: 메모리도 4메가고 시간 제한도 어느 정도 있길래 비트 마스킹으로 해결
*/

#include <iostream>
#include <string>

using namespace std;

class Set {
private:
    unsigned int data;
    
public:
    Set() {
        data = 0;
    }
    void add(int x) {
        // x 있으면 연산 무시
        if ((data >> x) & 1) return;
        unsigned int temp = 1 << x;
        data |= temp;
    }
    void remove(int x) {
        // x 없으면 연산 무시
        if (!((data >> x) & 1)) return;
        unsigned int temp = 1 << x;
        data &= (~temp);
    }
    int check(int x) {
        // S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
        if ((data >> x) & 1) return 1;
        else return 0;
    }
    void toggle(int x) {
        // S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
        if ((data >> x) & 1) remove(x);
        else add(x);
    }
    void all(){
        data = 2097150;  // 11...110 (총 21자리)
    }
    void empty() {
        data = 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    Set my_set = Set();
    
    int M;
    cin >> M;

    for (int i=0; i<M; i++) {
        string command;
        int x;
        cin >> command;
        
        if (command == "add") {
            cin >> x;
            my_set.add(x);
        }
        else if (command == "remove") {
            cin >> x;
            my_set.remove(x);
        }
        else if (command == "check") {
            cin >> x;
            cout << my_set.check(x) << '\n';
        }
        else if (command == "toggle") {
            cin >> x;
            my_set.toggle(x);
        }
        else if (command == "all")
            my_set.all();
        else if (command == "empty")
            my_set.empty();
    }
    
    return 0;
}
