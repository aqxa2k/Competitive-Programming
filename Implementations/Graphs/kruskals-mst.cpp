/** 
 * Description: Find minimum or maximum spanning tree of a graph 
 * Verification: https://codeforces.com/contest/1764/problem/F
 * Time: O(E log E + E log N) 
**/

struct DSU {
	vector<int> e;
	DSU(int _n) { e = vector<int>(_n, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -e[get(x)]; } //path compression
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0; 
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x; 
		return 1; 
	}
};


// edge -> {weight, u, v}
template <class T> vector<array<T, 3>> mst(int _n, vector<array<T, 3>> e) {
	DSU d(_n); vector<array<T, 3>> ret; 
	sort(e.begin(), e.end());
	for (int i = 0; i < (int) e.size(); ++i) {
		if (d.unite(e[i][1], e[i][2])) {
			ret.push_back(e[i]); 
		}
	} 
	return ret; 
}
