/*************************************************************************
	> File Name: 3.stack.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 二 11/29 14:38:49 2022
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 封装传统的数组 + 指针实现一个栈
// 这里令栈顶指针初值为 -1
// 这样top永远就能指向当前栈顶的元素
// 方便操作
class Stack {
public :
    Stack(int n = 100) {
        top = -1;
        data = new int [n];
    }
    void push(int x) {
        top += 1;
        data[top] = x;
        return ;
    }
    void pop() {
        if (empty()) return ;
        top -= 1;
        return ;
    }
    bool empty() {
        return top == -1;
    }
    int size() {
        return top + 1;
    }
    void output() {
        cout << "output : " << endl;
        for (int i = top; i >= 0; i--) {
            cout << " " << data[i] << endl;
        }
        return ;
    }

private :
    int top;
    int *data;
};

int main() {
    Stack s;
    string op;
    int val;
    while (cin >> op) {
        if (op == "push") {
            cin >> val;
            s.push(val);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "size") {
            cout << "size : " << s.size() << endl;
        } else if (op == "output") {
            s.output();
        }
    }
    return 0;
}
