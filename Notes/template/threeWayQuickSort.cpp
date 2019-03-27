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
	// [i, gt]��������δ�����
	// [lo, lt - 1]��С��v�ģ���lt < i��һ����
	// [gt + 1, hi]�Ǵ���v��
	while (i <= gt) {
		if (a[i] < v) {
			exch(a[i++], a[lt++]);		// ��Ϊltָ���������ߣ��±���С������v��ȵ�Ԫ�أ����Խ���֮��Ҫͨ��++�������������
		}
		else if (a[i] > v) {
			exch(a[i], a[gt--]);		// ��Ϊ��a[gt]����֮��a[i]�ǻ�������һ��δ֪��ֵ������i����++
		}
		else ++i;
	}
	threeWayQuickSrot(a, lo, lt - 1);
	threeWayQuickSrot(a, gt + 1, hi);
}