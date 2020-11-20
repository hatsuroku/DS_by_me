#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <tuple>
#include <functional>
#include <queue>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

// my solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++zeroNum;
                continue;
            }
            nums[i - zeroNum] = nums[i];
        }
        for (int i = 0; i < zeroNum; ++i) {
            nums[nums.size() - 1 - i] = 0;
        }
    }
};

// best solution
// 思想：双指针，模仿快排那种维持区间性质就行了。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int firstZeroPos = 0, i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[firstZeroPos++], nums[i]);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    vector<int> in;
    int a;
    while (cin >> a) {
        in.push_back(a);
    }
    Solution solu;
    solu.moveZeroes(in);
    for (auto &e : in) {
        cout << e << " ";
    }

    return 0;
}
