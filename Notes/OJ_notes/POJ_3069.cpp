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
				// ��ʱa[i]���ǵ�һ��û���ڷ�Χ�ڵ�����ĵ�
				// mark�ǰ���a[i]����Զ��Χ
                mark = a[i] + r;
                for (int j = i; j < n && a[j] <= mark; ++j) {
					// markp����[a[j], mark]���������ҵĵ㣬���ڱ��
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
		// s��û�б����ǵ�����ĵ��λ��
		int s = x[i++];
		
		// һֱ����ǰ��ֱ����s�ľ������R�ĵ�
		while(i<n && x[i] <= s + r) i++;
		
		// p���¼��ϱ�ǵĵ��λ��
		int p = x[i -1];
		// һֱ����ǰ��ֱ����p�ľ������R�ĵ�
		while(i<n && x[i] <= p+r) i++;
		
		ans++;
	}
	printf("%d\n", ans);
}