void exch(int &a, int &b) {
	if (a == b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

// 从左到右的三部分分别是{小于v}{大于等于v}{v}
int partition(int a[], int lo, int hi) {
	//一开始小于v的部分长度为0，初始位置位于-1
	int v = a[hi], i = lo - 1;
	//扩张{大于等于v}的部分，若碰到小于v的则扩张{小于v}的部分，然后进行交换
	for (int j = lo; j < hi; ++j) {
		if (a[j] <= v) {
			++i;
			exch(a[i], a[j]);
		}
	}
	//到最后i为{小于v}的最右边的元素的下标，所以a[i+1]就是{大于等于v}的第一个元素
	exch(a[i + 1], a[hi]);
	return i + 1;
}

void quicksort(int a[], int lo, int hi) {
	if (hi <= lo) return;	//长度为0的数组已经有序
	int j = partition(a, lo, hi);	//a[j]已经被放在了恰当的位置，所以需要处理的是[lo, j-1]和[j+1, hi]
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
}