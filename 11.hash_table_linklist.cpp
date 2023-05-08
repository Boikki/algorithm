/*************************************************************************
	> File Name: 11.hash_table.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 六  5/ 6 14:21:00 2023
 ************************************************************************/

#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Node  {
public :
    Node(std::string data = "", Node *next = nullptr) : data(), next(nullptr) {}
    std::string data;
    Node *next;
    void insert(Node *node) {
        node->next = this->next;
        this->next = nullptr;
        return ;
    }


};

class HashTable {
public : 
    HashTable(int n = 100) : data(n), cnt(0) {}
    void insert(std::string s) {
        int ind = hash(s) % data.size();
        recalc(ind, s);
        Node *p = &data[ind];
        while (p->next && p->next->data != s) p = p->next;
        // 找到最后一位 插入
        if (p->next == nullptr) {
            p->insert(new Node(s));
            cnt += 1;
        }
        if (cnt <= (float)data.size() * 3) expand();
        return ;
    }
    bool find(std::string s) {
        int ind = hash(s) % data.size();
        recalc(ind, s);
        Node *p = data[ind].next;
        while (p && p->data != s) p = p->next;
        return p != nullptr;
    }
private :
    int cnt;
    std::vector<Node> data;

    // 扩容操作
    void expand() {
        int n = data.size() >> 1;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            Node *p = data[i].next;
            while (p) {
                h.insert(p->data);
                p = p->next;
            }
        }
        *this = h;
        return ;
    }

    // BKDR hash 
    // 经典的string -> int 哈希
    int hash(std::string s) {
        const int seed = 123;
        int h = 0;
        for (auto x : s) {
            h = h * seed + x;
        }
        return h & 0x7fffffff;
    }
    void recalc(int &ind, std::string &s) {
        return ;
    }
};

int main(int argc, char **argv) {
        int op;
        std::string s;
    HashTable h;
    while (std::cin >> op >> s) {
        switch (op) {
            case 1: h.insert(s); break;
            case 2: std::cout << "find : " << s <<  " = " << h.find(s) << std::endl; break;
        }
    }
    return 0;
}
