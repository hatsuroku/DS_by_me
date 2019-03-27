void exch(int &a, int &b) {
	if (a == b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

void threeWayQuickSrot(int a[], int lo, int hi) {
	if (hi <= lo) return;
	int lt = lo, gt = hi, i = lo + 1;
	int v = a[lo];
	// [i, gt]的数据是未处理的
	// [lo, lt - 1]是小于v的，且lt < i是一定的
	// [gt + 1, hi]是大于v的
	while (i <= gt) {
		if (a[i] < v) {
			exch(a[i++], a[lt++]);		// 因为lt指向的是最左边（下标最小）的与v相等的元素，所以交换之后要通过++来保持这个性质
		}
		else if (a[i] > v) {
			exch(a[i], a[gt--]);		// 因为与a[gt]交换之后，a[i]是换过来的一个未知的值，所以i不用++
		}
		else ++i;
	}
	threeWayQuickSrot(a, lo, lt - 1);
	threeWayQuickSrot(a, gt + 1, hi);
}