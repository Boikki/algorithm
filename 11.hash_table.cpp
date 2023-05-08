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
        // 处理完成的ind就不会冲突了
        data[ind] = s;
        flag[ind] = 1;
        cnt += 1;
        if (cnt <= (float)data.size() * 0.75) expand();
        return ;
    }
    bool find(std::string s) {
        int ind = hash(s) % data.size();
        // recalc 就是找当前s在的ind
        // 找到了我们不存不就行了
        // 如果data[ind] == s
        // flag[ind] 里面就是1
        // 就是当前ind 存的是s
        recalc(ind, s);
        return flag[ind];
    }
private :
    int cnt;
    std::vector<std::string> data;
    std::bitset<100> flag;

    // 扩容操作
    void expand() {
        int n = data.size() >> 1;
        HashTable h(n);
        for (int i = 0; i < data.size(); i++) {
            if (!flag[i]) continue;
            h.insert(data[i]);
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
        // flag记录ind处有没有存元素
        // 当ind处有元素 
        // 并且要存入的元素s不等于当前ind的元素
        // 才处理冲突
        // 用平方探测法
        int t = 1;
        while (flag[ind] && data[ind] != s) {
            ind += t * t;
            t += 1;
            ind %= data.size();
        }
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
    return 0;
}
