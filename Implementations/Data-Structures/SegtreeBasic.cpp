//add stuff


//Segtree: initialize, make, build, modify, query， incremenet; 
template <class T> 
class Segtree {
    private: 
    vector<T> t;
    int n; T init = 0; //change initial value! 
    T op(T a, T b) {
        return a + b; //change operation!
    } 
    public:
    Segtree(T N, vector<T> v = {}) { 
        t = vector<T>(2 * N, init); 
        n = N; 
		if (v.size()) make(v); 
    }
    void make(vector<T> & a) { 
        for (int i = 0; i < n; ++i) t[n+i] = a[i]; 
    } 
    void build() {
        for (int i = n - 1; i > 0; --i) t[i] = op(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, T val) {
        for (t[p += n] = val; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    }
    void inc(int p, T val) {
        for (t[p += n] = op(t[p+n], val); p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    }
    //query on [l, r)
    T query(int l, int r) {  
        T res = init;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = op(res, t[l++]);
            if (r&1) res = op(res, t[--r]);
        }
        return res;
    }
};
