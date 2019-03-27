//POJ-2352
//星星的level数 = 位于该星星左下区域(包括自己处在的x轴y轴，但不包括自身)的星星个数
//因为输入是按照y的升序排列好的，所以可以直接把2维压缩成1维
//后面出现的y坐标 >= 前面出现的y坐标，所以只要把 <=该x坐标的星星个数加起来即可
//采用树状数组来加快求和速度

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define lowbit(k) ((k)&(-k)) 
//#define LOCAL
const int kmax = 32000 + 10;
const int nmax = 15000 + 10;


int tree[kmax], level[nmax], n;

int sum(int k) {
	int result = 0;
	while (k) {
		result += tree[k];
		k -= lowbit(k);
	}
	return result;
}

void add(int k, int v) {
	while (k < kmax) {
		tree[k] += v;
		k += lowbit(k);
	}
}

int main() {
#ifdef LOCAL
	freopen("F:\\VSproject\\RealHomeWork\\CPPLearning\\CPPLearning\\input.txt", "r", stdin);
	freopen("F:\\VSproject\\RealHomeWork\\CPPLearning\\CPPLearning\\output.txt", "w", stdout);
#endif
	memset(tree, 0, sizeof(tree));
	memset(level, 0, sizeof(level));
	scanf("%d", &n);
	for (int j = 0; j < n; ++j) {
		int x, y;
		scanf("%d%d", &x, &y);
		int tmp = sum(x + 1); //加入x+1，是为了避免0，X是可能为0的
		++level[tmp];
		add(x + 1, 1);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", level[i]);
	}
}