/*************************************************************************
	> File Name: 2.queue.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一 11/21 10:05:51 2022
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Queue {
public :
    Queue(int n = 10) : arr(n), head(0), tail(0), cnt(0) {}
    void push(int x) {
        if (full()) {
            cout << "queue full" << endl;
            return ;
        }
        arr[tail] = x;
        tail += 1;
        cnt += 1;
        if (tail == arr.size()) tail = 0;
        return ;
    }
    void pop() {
        if (empty()) {
            return ;
        }
        head += 1;
        cnt -= 1;
        if (head == arr.size()) head = 0;
        return ;
    }
    bool empty() {
        return cnt == 0;
    }
    bool full() {
        return cnt == arr.size();
    }
    int front() {
        if (empty()) return 0;
        return arr[head];
    }
    int size() {
        return cnt;
    }
    void output() {
        cout << "Queue : ";
        for (int i = 0, j = head; i < cnt; i++) {
            cout << arr[j] << " ";
            j += 1;
            if (j == arr.size()) j = 0;
        }
        cout << endl;
    }
private :
    int head, tail;
    int cnt;
    // cnt为当前元素数量
    vector<int> arr;
};

int main() {
    string op;
    int value;
    Queue q(5);
    while (cin >> op) {
        if (op == "insert") {
        cin >> value;
        q.push(value);
        } else if (op == "front") {
        cout << "front element : " << q.front() << endl;
        } else if (op == "pop") {
            q.pop();
        } else if (op == "size") {
            cout << "queue size : " << q.size() << endl;
        }
    q.output();
    }
    return 0;
}


