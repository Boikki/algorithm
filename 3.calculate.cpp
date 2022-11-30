/*************************************************************************
	> File Name: 3.calculate.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三 11/30 09:46:22 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int calc(char *s, int l, int r) {
    // op 是最低优先级运算符位置
    // pri 是最高优先级
    // cur_pri 是当前运算符的优先级
    // temp 是由括号增加的优先级
    int op = -1, pri = 10000 - 1, cur_pri, temp = 0;
    for (int i = l; i <= r; i++) {
        cur_pri = 10000;
        switch (s[i]) {
            case '+' :
            case '-' : cur_pri = 1 + temp; break;
            case '*' :
            case '/' : cur_pri = 2 + temp; break;
            case '(' : temp += 100; break;
            case ')' : temp -= 100; break;
        }
        if (cur_pri <= pri) {
            pri = cur_pri;
            op = i;
        }
    }
    if (op == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            // atoi
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    // 分治 + 递归进行运算符的提取
    int a = calc(s, l, op - 1);
    int b = calc(s, op + 1, r);
    switch (s[op]) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
    return 0;
}

int main() {
    char s[100];
    while (~scanf("%[^\n]s", s)) {
        getchar();
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
    return 0;
}
