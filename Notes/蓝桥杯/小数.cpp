/*
 * 蓝桥杯什么撒比玩意？？？？
 * 400位居然就能过了，亏你还给出10^9那么大的数据
 * 知不知道112/113循环位就有一百多了我淦
 * orz
 */


#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define max2(a,b) ((a) > (b) ? (a) : (b))
#define min2(a,b) ((a) < (b) ? (a) : (b))

using namespace std;
const int maxbit = 500, maxr = 500;
// bits记录位（商），rr记录余数
int bits[maxbit], rr[maxr], bit = 1, r = 1, cirstart;
int circulation[maxbit];


// 模拟竖式除法
// 一共算够最大位数（太蠢了
int simudivi(int a, int b) {
    bool decimalFlag = false;
    if(a >= b) {
        a %= b;
    }
    while(bit < maxbit) {
        a *= 10;
        int quotient;
        quotient = a / b;
        a %= b;
//        printf("%d: q-%d r-%d\n", bit, quotient, a);
        rr[r++] = a;
        bits[bit++] = quotient;
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    simudivi(a, b);
    int circulen = 0;
    // 寻找循环段
    // 如果小数点后第一位就是循环段的开头，会把第一位识别成非循环段
    // 不知道该怎么解决orz
    for(int i = 1, breakflag = 0; i < maxbit; ++i) {
        for(int j = i + 1; j < maxbit; ++j) {
            if(rr[i] == rr[j]) {
                circulen = j - i;
                memcpy(circulation, bits + i + 1, circulen * sizeof(int));
                cirstart = i + 1;
                breakflag = 1;
                break;
            }
        }
        if(breakflag) break;
    }

    if(n < cirstart) {
        for (int i = 0; i < 3; ++i) {
            printf("%d", bits[n+i]);
        }
    } else {
        n -= cirstart;
        if(n > circulen) n %= circulen;
        for (int i = 0; i < 3; ++i) {
            printf("%d", circulation[(n+i)%circulen]);
        }
    }

//    for(int i = 0; i < circulen; ++i) {
//        printf("\n%d", circulation[i]);
//    }
//
//
//    printf("\n\n\n");
//    for(int i = 1; i < maxbit; ++i) {
//        printf("%d", bits[i]);
//        if(i % 100 == 0) printf("\n");
//    }
//    printf("\n\n\n");
//    for(int i = 1; i < maxr; ++i) {
//        printf("%5d", rr[i]);
//        if(i % 100 == 0) printf("\n");
//    }

}