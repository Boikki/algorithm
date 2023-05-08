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

class HashTable {
public : 
    HashTable(int n = 100) : data(n), cnt(0) {}
    void insert(std::string s) {
        // hash对数组大小取余才是位置 
        int ind = hash(s) % data.size();
        recalc(ind, s);
        // 冲突的话插入缓冲区了
        if (flag[ind]) {
            buff.insert(s);
        } else {
            data[ind] = s;
            flag[ind] = 1;
            cnt += 1;
            if (cnt <= (float)data.size() * 0.75) expand();
        }
        return ;
    }
    bool find(std::string s) {
        int ind = hash(s) % data.size();
        recalc(ind, s);
        if (!flag[ind]) return false;
        if (data[ind] == s) return true;
        // 没在buff中找到
        return buff.find(s) != buff.end();
    }
private :
    int cnt;
    std::vector<std::string> data;
    std::bitset<100> flag;
    std::set<std::string> buff;

    // 扩容操作
    void expand() {
        int n = data.size() >> 1;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (!flag[i]) continue;
            h.insert(data[i]);
        }
        // 插入buff中的元素
        for (auto x : buff) h.insert(x);

        // *this = h;
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
