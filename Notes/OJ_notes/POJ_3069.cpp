//POJ 3069
//solved by Hatsuroku on 2018/5/9
#include <stdio.h>
#include <algorithm>

int main() {
    int r, n;
    int a[1000];
    int mark = -1, ans = 0, markp = -1;
    while(scanf("%d %d", &r, &n)) {
        if(r == -1) {
            break;
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        std::sort(a, a+n);
        for(int i=0; i<n; ++i) {
            if(a[i] > mark) {
				// 此时a[i]就是第一个没有在范围内的最左的点
				// mark是包含a[i]的最远范围
                mark = a[i] + r;
                for (int j = i; j < n && a[j] <= mark; ++j) {
					// markp是在[a[j], mark]区间内最右的点，用于标记
                    markp = a[j];
                }
                mark = markp + r;
                ans++;
            }
        }
        printf("%d\n", ans);
        ans = 0;
        mark = -1;
    }
    return 0;
}


//solution in the book
void solve(int n, int r, int x[]) {
	int i=0, ans=0;
	std::sort(x, x+n);
	while(i < n) {
		// s是没有被覆盖的最左的点的位置
		int s = x[i++];
		
		// 一直向右前进直到距s的距离大于R的点
		while(i<n && x[i] <= s + r) i++;
		
		// p是新加上标记的点的位置
		int p = x[i -1];
		// 一直向右前进直到距p的距离大于R的点
		while(i<n && x[i] <= p+r) i++;
		
		ans++;
	}
	printf("%d\n", ans);
}