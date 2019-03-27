void exch(int &a, int &b) {
	if (a == b) return;
	int tmp = a;
	a = b;
	b = tmp;
}

// �����ҵ������ֱַ���{С��v}{���ڵ���v}{v}
int partition(int a[], int lo, int hi) {
	//һ��ʼС��v�Ĳ��ֳ���Ϊ0����ʼλ��λ��-1
	int v = a[hi], i = lo - 1;
	//����{���ڵ���v}�Ĳ��֣�������С��v��������{С��v}�Ĳ��֣�Ȼ����н���
	for (int j = lo; j < hi; ++j) {
		if (a[j] <= v) {
			++i;
			exch(a[i], a[j]);
		}
	}
	//�����iΪ{С��v}�����ұߵ�Ԫ�ص��±꣬����a[i+1]����{���ڵ���v}�ĵ�һ��Ԫ��
	exch(a[i + 1], a[hi]);
	return i + 1;
}

void quicksort(int a[], int lo, int hi) {
	if (hi <= lo) return;	//����Ϊ0�������Ѿ�����
	int j = partition(a, lo, hi);	//a[j]�Ѿ���������ǡ����λ�ã�������Ҫ�������[lo, j-1]��[j+1, hi]
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
}