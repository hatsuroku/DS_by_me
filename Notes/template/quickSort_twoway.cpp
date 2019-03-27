void exch(int &a, int &b) {
	if (a == b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int a[], int lo, int hi) {
	int i = lo, j = hi + 1;		//�������ó�ʼֵ������ֵ�����ڱ�ֵ
	int v = a[lo];
	while (1) {
		while (a[++i] < v) {	//��a[i]>=v��ʱ��break�����ҵ���һ�����ڵ���v��ֵ
			if (i == hi) break;
		}
		while (a[--j] > v) {
			if (j == lo) break;	//��a[j]<=v��ʱ��break�����ҵ���һ��С�ڵ���v��ֵ
		}
		if (i >= j) break;		//��Ϊa[i]>=v��a[j]<=v�����i>j���Ѿ���������break
		exch(a[i], a[j]);
	}
	exch(a[lo], a[j]);			//a[i]��a[j]������a[j]������ҵı�vС��ֵ
	return i;
}

void quicksort(int a[], int lo, int hi) {
	if (hi <= lo) return;	//����Ϊ0�������Ѿ�����
	int j = partition(a, lo, hi);	//a[j]�Ѿ���������ǡ����λ�ã�������Ҫ�������[lo, j-1]��[j+1, hi]
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
}