// POJ 3253
// solved by Hatsuroku on 2018/5/9

#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <queue>


int main(int argc, char* argv[]) {
	int n, l;
	std::priority_queue<int, std::vector<int>, std::greater<int> > p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l);
		p.push(l);
	}

	// 不用long long的话结果会溢出
	long long ans = 0;
	int min1, min2;
	int t;

	while (p.size() > 1) {
		min1 = p.top();	p.pop();
		min2 = p.top(); p.pop();
		t = min1 + min2;
		ans += t;
		p.push(t);
	}
	printf("%lld\n", ans);
	return 0;
}