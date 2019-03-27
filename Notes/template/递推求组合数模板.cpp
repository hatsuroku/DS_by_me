/*
 * 很快，在N = 5000, K = 2500的情况下只要154ms
 * 测试过的最大数是N = 16000, K = 8000，需要2159ms
 * N = 20000, K = 10000会segmentation fault（栈溢出
 * 由于组合数很大，如果情况允许请务必使用ULL，注意带模，能不除的就不要除
 */


#define ULL unsigned long long 
#defile LL long long

const int N = 5000, K = 2500;

ULL C[N + 1][K + 1];

ULL comNum(ULL n, ULL k) {
    if(k > n/2) return comNum(n, n - k);
    if(C[n][k] != 0) return C[n][k];
    else if (k == 0) return C[n][k] = 1;
    else if (k == 1) return C[n][k] = n;
    else return C[n][k] = (comNum(n-1, k) + comNum(n-1, k-1));
}