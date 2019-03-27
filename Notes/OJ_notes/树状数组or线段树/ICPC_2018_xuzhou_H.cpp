#include <iostream>
#include <stdio.h>
#include <math.h>

/*
  维护两棵线段树，一棵是普通的求和数，另一棵存(n-i+1)*a[i]
  分别求和再相减即可
*/

// #define LOCAL
#define ll long long int
#define lbt(x) ((x)&(-x))

using namespace std;
const int nodenum = 200010;
long long p_tree[nodenum];
long long s_tree[nodenum];
int n, q;

void s_update(int k, long long x) {
	k += n;
	s_tree[k] = x;
	for(k /= 2; k >= 1; k /= 2) {
		s_tree[k] = s_tree[2 * k] + s_tree[2 * k + 1];
	}
}

long long sum(int a, int b, ll tree[]) {
	a += n, b += n;
	long long s = 0;
	while(a <= b) {
		if ((a & 1) == 1) s += tree[a++];
		if ((b & 1) == 0) s += tree[b--];
		a >>= 1 , b >>= 1;
	}
	return s;
}

void p_update(int k, long long x) {
	int pre_k = k;
	k += n;
	p_tree[k] = x * (n - pre_k + 1);
	for(k /= 2; k >= 1; k /= 2) {
		p_tree[k] = p_tree[2 * k] + p_tree[2 * k + 1];
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		long long tmp;
		cin >> tmp;
		s_update(i, tmp);
		p_update(i, tmp);
	}
	while(q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			ll result = sum(b, c, p_tree);
			ll result2 =  sum(b, c, s_tree);
			ll ano = n - c;
			result = result - result2 * ano;
			cout << result << endl;
		}
		else {
			s_update(b, c);
			p_update(b, c);
		}
	}
}