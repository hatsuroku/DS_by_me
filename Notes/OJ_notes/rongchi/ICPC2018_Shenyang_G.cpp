#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iterator>
#include <vector>
#include <algorithm>

// #define LOCAL
#define ull unsigned long long int
#define ll long long int

using namespace std;
ll mod = 1e9 + 7;
ll m, n;
int prime[10000+10];
int pnum;

void factorization(int m) {
	int tmp = m;
	for(int i = 2; i * i <= m; ++i) {
		if(tmp % i == 0) {
			prime[pnum++] = i;
			while(tmp % i == 0) {
				tmp /= i;
			}
		}
	}
	if(tmp > 1) {
		prime[pnum++] = tmp;
	}
}

ll pow(ll a, ll b, ll mod) {
	ll result = 1;
	while(b) {
		if(b & 1) {
			result = (result * a) % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return result;
}

int main() {
	ll div2 = pow(2, mod - 2, mod);
	ll div6 = pow(6, mod - 2, mod);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while(scanf("%d%d", &n, &m) != EOF) {
		pnum = 0;
		factorization(m);
		ll sum = 0;
		for(int i = 1; i < (1 << pnum); ++i) {
			ll cnt = 0, k = 1;
			for(int j = 0; j < pnum; ++j) {
				if(i & (1 << j)) {
					cnt++;
					k *= prime[j];
				}
			}
			ll t = n / k;
			ll t2plust = t * (t + 1) % mod;
			if (cnt & 1) { 
				sum += k * t2plust % mod * div2  +  k * k % mod * t2plust % mod * (2 * t + 1) % mod * div6;
			}
			else {
				sum -= k * t2plust % mod * div2  +  k * k % mod * t2plust % mod * (2 * t + 1) % mod * div6;
			}
		}

		ll res = n * (n + 1) % mod * div2;
		res += n * (n + 1) % mod * (2 * n + 1) % mod * div6;
		res = ((res - sum) % mod + mod) % mod;
		printf("%lld\n", res);
	}
}