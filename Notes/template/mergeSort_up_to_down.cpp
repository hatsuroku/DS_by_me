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

void mergesort(int a[], int lo, int hi) {
	if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	mergesort(a, lo, mid);
	mergesort(a, mid + 1, hi);
	merge(a, lo, mid, hi);
}