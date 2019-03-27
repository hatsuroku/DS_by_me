
int min(int a, int b) {
	return a < b ? a : b;
}

void merge(int a[], int lo, int mid, int hi) {
	int i = lo, j = mid + 1;
	int aux[500];
	for (int k = lo; k <= hi; ++k) {
		aux[k] = a[k];
	}
	for (int k = lo; k <= hi ; ++k) {
		if (i > mid)				a[k] = aux[j++];
		else if (j > hi)			a[k] = aux[i++];
		else if (aux[j] < aux[i])	a[k] = aux[j++];
		else						a[k] = aux[i++];
	}
}

void mergesort(int a[]) {
	for (int sz = 1; sz < 500; sz *= 2) {
		for (int lo = 0; lo < 500 - sz; lo += (sz * 2)) {
			merge(a, lo, lo + sz - 1, min(lo + sz * 2 - 1, 500 - 1));
		}
	}
}