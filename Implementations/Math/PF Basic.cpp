//not finished
//add stuff


template <class T> vector<pair<T, int>> factor_basic(T x) {
  vector<pair<T, int>> ret; 
  if (x % 2 == 0) {
	ret.push_back({2, 0});
	while (x % 2 == 0) ret.back().second++, x /= 2; 
  }
  for (T i = 3; i * i <= x; ++i) {
	  if (x % i == 0) {
	    ret.push_back({i, 0});
      while (x % i == 0) {
        ret.back().second()++, x /= i; 
    }	
  }
  if (x > 2) ret.push_back({x, 1}); 
  return ret; 
}

#define factor factor_basic
