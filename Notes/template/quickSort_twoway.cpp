void exch(int &a, int &b) {
	if (a == b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int a[], int lo, int hi) {
	int i = lo, j = hi + 1;		//先设立好初始值，两个值都是哨兵值
	int v = a[lo];
	while (1) {
		while (a[++i] < v) {	//当a[i]>=v的时候break，即找到第一个大于等于v的值
			if (i == hi) break;
		}
		while (a[--j] > v) {
			if (j == lo) break;	//当a[j]<=v的时候break，即找到第一个小于等于v的值
		}
		if (i >= j) break;		//因为a[i]>=v，a[j]<=v，如果i>j则已经有序，所以break
		exch(a[i], a[j]);
	}
	exch(a[lo], a[j]);			//a[i]和a[j]交换后，a[j]就是最靠右的比v小的值
	return i;
}

void quicksort(int a[], int lo, int hi) {
	if (hi <= lo) return;	//长度为0的数组已经有序
	int j = partition(a, lo, hi);	//a[j]已经被放在了恰当的位置，所以需要处理的是[lo, j-1]和[j+1, hi]
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
}