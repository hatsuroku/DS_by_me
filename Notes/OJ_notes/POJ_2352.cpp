//POJ-2352
//���ǵ�level�� = λ�ڸ�������������(�����Լ����ڵ�x��y�ᣬ������������)�����Ǹ���
//��Ϊ�����ǰ���y���������кõģ����Կ���ֱ�Ӱ�2άѹ����1ά
//������ֵ�y���� >= ǰ����ֵ�y���꣬����ֻҪ�� <=��x��������Ǹ�������������
//������״�������ӿ�����ٶ�

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
		int tmp = sum(x + 1); //����x+1����Ϊ�˱���0��X�ǿ���Ϊ0��
		++level[tmp];
		add(x + 1, 1);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", level[i]);
	}
}