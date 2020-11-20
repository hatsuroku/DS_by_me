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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 体力活，没啥好说的
// 就这居然也能击败93.18%的人，震撼我妈
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *prev = head, *now = head->next;
        while (now != nullptr) {
            if (now->val >= prev->val) {
                prev = now;
                now = now->next;
            }
            else {
                if (now->val < head->val) {
                    ListNode *toMove = now;
                    now = now->next;
                    prev->next = now;

                    toMove->next = head;
                    head = toMove;
                    continue;
                }
                for (ListNode *i = head; i != prev; i = i->next) {
                    ListNode *iNext = i->next;
                    if (iNext->val >= now->val) {
                        ListNode *toMove = now;
                        now = now->next;
                        prev->next = now;

                        i->next = toMove;
                        toMove->next = iNext;
                        break;
                    }
                }
            }
        }
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    Solution solu;
    int a;
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    while(cin >> a) {
        tail->next = new ListNode(a);
        tail = tail->next;
    }
    ListNode *oldHead = head;
    head = head->next;
    delete oldHead;

    head = solu.insertionSortList(head);
    for (ListNode *i = head; i != nullptr; i = i->next) {
        cout << i->val << " ";
    }

    return 0;
}
