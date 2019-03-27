#include <iostream>
#include <vector>

using namespace std;

template <typename _Type>
class mypq {
private:
    vector<_Type> data = vector<_Type>(1);
public:
    mypq() = default;
    ~mypq() = default;
    void push(_Type &&target);
    _Type top();
    void pop();
    bool empty() {
        return data.empty();
    }
};

template <typename _Type>
void mypq<_Type>::push(_Type &&target) {
    int pos = data.size();
    data.emplace_back(target);
    using std::swap;
    while(pos > 1 && data[pos] < data[pos/2]) {
        swap(data[pos], data[pos/2]);
        pos /= 2;
    }
}

template <typename _Type>
_Type mypq<_Type>::top() {
    return data[1];
}

template <typename _Type>
void mypq<_Type>::pop() {
    using std::swap;
    swap(data[1], *data.rbegin());
    data.pop_back();
    int pos = 1;
    for(int j = pos * 2; j < data.size(); ) {
        if(j+1 < data.size() && data[j+1] < data[j]) {
            ++j;
        }
        if(data[j] < data[pos]) {
            swap(data[j], data[pos]);
            pos = j;
            j = pos * 2;
        }
        else break;
    }
}

void test_pq() {
    mypq<int> q;
    for(int i = 0; i < 10; ++i) {
        q.push(rand() % 10);
    }
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}