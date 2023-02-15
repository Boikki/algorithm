/*************************************************************************
	> File Name: 2.front-middle-back-queue.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五 11/25 19:18:36 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 下面用链表的思想实现一个dequeue

struct Node {
public :
    int val;
    Node *next, *pre;
    Node(int val = 0, Node *pre = nullptr, Node *next = nullptr) : val(val), next(next), pre(pre) {}
    void insert_pre(Node *p) {
        p->pre = this->pre;
        p->next = this;
        if (this->pre) this->pre->next = p;
        this->pre = p;
        return ;
    }
    void insert_next(Node *p) {
        p->pre = this;
        p->next = this->next;
        if (this->next) this->next->pre = p;
        this->next = p;
        return ;
    }
    void delete_pre() {
        if (this->pre == nullptr) return ;
        Node *p = this->pre;
        this->pre = p->pre;
        if (p->pre) p->pre->next = this;
        delete p;
        return ;
    }
    void delete_next() {
        if (this->next == nullptr) return ;
        Node *p = this->next;
        this->next = p->next;
        if (p->next) p->next->pre = this;
        delete p;
        return ;
    }
};

class Queue {
public :
    int cnt;
    Node head, tail;
    Queue() : cnt(0) {
        head.next = &tail;
        head.pre = nullptr;
        tail.next = nullptr;
        tail.pre = &head;
    }
    void push_back(int val) {
        tail.insert_pre(new Node(val));
        cnt += 1;
        return ;
    }
    void push_front(int val) {
        head.insert_next(new Node(val));
        cnt += 1;
        return ;
    }
    int pop_back() {
        if (is_empty()) return -1;
        int ret = tail.pre->val;
        tail.delete_pre();
        cnt -= 1;
        return ret;
    }
    int pop_front() {
        if (is_empty()) return -1;
        int ret = head.next->val;
        head.delete_next();
        cnt -= 1;
        return ret;
    }
    bool is_empty() {
        return head.next == &tail;
    }
    int size() {
        return cnt;
    }
    int front() {
        return head.next->val;
    }
    int back() {
        return tail.pre->val;
    }
    
};

class FrontMiddleBackQueue {
public:
    Queue q1, q2;
    // 设计的时候考虑q1总是比q2元素要多一个或者相等
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        q1.push_front(val);
        update();
        return ;
    }
    
    void pushMiddle(int val) {
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
        update();
        return ;

    }
    
    void pushBack(int val) {
        q2.push_back(val);
        update();
        return ;
    }
    
    int popFront() {
        if (is_empty()) return -1;
        int ret = q1.pop_front();
        update();
        return ret;
    }
    
    int popMiddle() {
        if (is_empty()) return -1;
        int ret = q1.pop_back();
        update();
        return ret;
    }
    
    int popBack() {
        if (is_empty()) return -1;
        int ret;
        if (q2.is_empty()) {
            ret = q1.pop_back();
        } else {
            ret = q2.pop_back();
        }
        update();
        return ret;
    }

    bool is_empty() {
        return (q1.size() == 0);
    }

    void update() {
        if (q1.size() < q2.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if (q1.size() == q2.size() + 2) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        return ;
    }
};
