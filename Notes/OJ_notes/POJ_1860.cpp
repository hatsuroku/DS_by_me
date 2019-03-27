#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int NN = 110;
struct edge {
    int from;
    int to;
    double rate;
    double cost;
};

vector<edge> adj[NN];
queue<int> q;
bool onQ[NN];

int route_count[NN];

int N;  // the number of currencies
int M;  // the number of exchange points
int S;  // the number of currency Nick has
double V;  // the quantity of currency units he has
double dist[NN];


bool spfa();

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M >> S >> V;
    for(int i=0; i<M; ++i) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        edge e1 = {a, b, rab, cab};
        edge e2 = {b, a, rba, cba};
        adj[e1.from].push_back(e1);
        adj[e2.from].push_back(e2);
    }
    cout << (spfa() ? "YES\n" : "NO\n");

    return 0;
}

bool spfa() {
    memset(onQ, 0, sizeof(onQ));
    dist[S] = V;
    q.push(S);
    while(!q.empty()) {
        int from = q.front(); q.pop();
        onQ[from] = false;
        for(vector<edge>::iterator iter = adj[from].begin(); iter != adj[from].end(); ++iter) {
            double tmp = (dist[iter->from] - iter->cost) * iter->rate;
            if(tmp > dist[iter->to]) {
                // 一个顶点被放松第n轮后一定存在环
                if(++route_count[iter->to] > N) return true;
                dist[iter->to] = tmp;
                q.push(iter->to);
                onQ[iter->to] = true;
            }
        }
    }
    return false;
}