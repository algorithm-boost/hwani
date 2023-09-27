/*
* 백준 9019번 골드4
* 문제: DSLR
* 링크: https://www.acmicpc.net/problem/9019
* 사용한 알고리즘: bfs
* 접근 방식: https://github.com/algorithm-boost/hwani/issues/1
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class regi {
    int number;
    int digit[4];

    void numberToDigit() {
        this->digit[0] = this->digit[1] = this->digit[2] = this->digit[3] = 0;
        for (int i=3, n = this->number; n; n /= 10, i--)
            (this->digit)[i] = n % 10;
    }
    void digitToNumber() {
        this->number = (((digit[0])*10 + digit[1])*10 + digit[2])*10 + digit[3];
    }

public:
    void setNumber(int number) {
        (this->number) = number;
        numberToDigit();
    }
    int getNumber() {
        return number;
    }

    void executeCommand(char command) {
        int t;
        switch(command) {
            case 'D':
                number *= 2;
                number %= 10000;
                numberToDigit();
                break;
            case 'S':
                if (number == 0)
                    number = 9999;
                else
                    number--;
                numberToDigit();
                break;
            case 'L':
                t = digit[0];
                digit[0] = digit[1];
                digit[1] = digit[2];
                digit[2] = digit[3];
                digit[3] = t;
                digitToNumber();
                break;
            case 'R':
                t = digit[3];
                digit[3] = digit[2];
                digit[2] = digit[1];
                digit[1] = digit[0];
                digit[0] = t;
                digitToNumber();
                break;

        }
    }
};

struct queue_element {
    int number;
    string commands;
};

char commands[4] = {'D', 'S', 'L', 'R'};

string bfs(queue<queue_element> &, unsigned char *, const int &, const int &);
bool check(const int &, const int &);

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    vector<string> results;
    int T, n, m;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        cin >> n >> m;
    
        queue<queue_element> bfs_queue;
        unsigned char visited[10000] = {0,};
        results.emplace_back(bfs(bfs_queue, visited, n, m));
    }

    for (int i=0; i<results.size(); i++)
        cout << results[i] << '\n';
    

    return 0;
}

string bfs(queue<queue_element> & bfs_queue, unsigned char visited[], const int & initial_number, const int & target_number) {
    regi my_register;

    queue_element temp_element = {initial_number, ""};
    visited[initial_number] = 1;
    bfs_queue.emplace(temp_element);
    
    queue_element popped_element;
    while (!bfs_queue.empty()) {
        popped_element = bfs_queue.front(); bfs_queue.pop();
        if (check(popped_element.number, target_number))
            return popped_element.commands;
        
        for (int i=0; i<4; i++) {
            temp_element = popped_element;

            my_register.setNumber(temp_element.number);
            my_register.executeCommand(commands[i]);
            temp_element.number = my_register.getNumber();
            if (visited[temp_element.number])
                continue;
            else
                visited[temp_element.number] = 1;
            
            temp_element.commands += commands[i];

            bfs_queue.emplace(temp_element);
        }
    }
    return "Noting Found";
}


bool check(const int & number, const int & target) {
    return number==target;
}
