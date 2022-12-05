/** 
 * Description: Query if 2 nodes are in the same set, size and representative of node. Union disjoint sets. 
 * Verification: https://codeforces.com/contest/1764/problem/F
 * Time: O(log N) query and update
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
