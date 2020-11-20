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

// My Solution
// 因为要维护字典，所以会非常慢
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int maxLen = 1, nowLen = 1;
        map<char, int> lastPos;
        lastPos[s[0]] = 0;
        for (int head = 0, tail = 1; tail < s.size(); ++tail) {
            char nowChar = s[tail];
            if (lastPos.count(nowChar) == 0) {
                lastPos[nowChar] = tail;
                ++nowLen;
            }
            else {
                nowLen = tail - lastPos[nowChar];
                for (; lastPos.count(nowChar); ++head) {
                    lastPos.erase(s[head]);
                }
                lastPos[nowChar] = tail;
            }
            maxLen = (nowLen > maxLen) ? nowLen : maxLen;
        }
        return maxLen;
    }
};


// best solution
// 只维护头尾指针，自然会快很多
// 要意识到head只会前进不会后退，tail也是

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.size() == 0) return 0;
//         int head = 0;
//         int maxlen = 0;
//         for(int tail = 0; tail < s.size(); ++tail) {
//             for(int k = head; k < tail; ++k) {
//                 if(s[k] == s[tail]) {
//                     head = k + 1;
//                     break;
//                 }
//             }
//             if(tail - head + 1 > maxlen) {
//                 maxlen = tail - head + 1;
//             }
//         }
//         return maxlen;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    Solution solu;
    string s;
    while(cin >> s) {
        cout << solu.lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
