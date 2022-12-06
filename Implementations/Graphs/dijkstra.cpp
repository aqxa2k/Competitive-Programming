/** 
 * Description: Finds shortest path from node x to all other nodes
 * Verification: https://open.kattis.com/problems/shortestpath1
 * Time: O(M log N) 
**/

template <class T> 
class dijkstra {
    //CHANGE MAXN IF IS INT 
    const long long __inf_d = 9e18; //const int __inf_d = 1e9; 
    public: 
        int n; 
        vector<T> d; 
        vector<vector<pair<int, T>>> g; 
        dijkstra(int _n) {
            n = _n; 
            d = vector<T>(n); 
            g = vector<vector<pair<int, T>>>(n); 
        }
        inline void add(int u, int v, T w, bool dir = 0) {
            g[u].push_back({v, w}); 
            if (dir) g[v].push_back({v, w}); 
        }
        void run(int st = 0) {
            for (int i = 0; i < n; ++i) d[i] = __inf_d; 
            priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q; 
            d[st] = 0; q.push({0, st}); 
            while (!q.empty()) {
                pair<T, int> p = q.top();  q.pop(); 
                T dist = p.first; int u = p.second; 
                for (pair<T, int> next: g[u]) {
                    int v = next.first; T next_dist = dist + next.second; 
                    if (next_dist < d[v]) {
                        d[v] = next_dist; q.push({next_dist, v}); 
                    }
                }
            }
        }
        inline T get(int node) { if (d[node] == __inf_d) return -1; return d[node]; } 
}; 
