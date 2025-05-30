#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T &&A = "", U &&...B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T &&A, U &&...B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T &&A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
  using vec<vec<T>>::vec;
  vvec(int N = 0, int M = 0, const T& _init_value = T())
    : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
  using vec<vvec<T>>::vec;
  vvvec(int N = 0, int M = 0, int K = 0, const T& _init_value = T())
    : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e9;
const int MAXN = 2e5;

void solve(){
  int n; cin >> n;
  vec<int> a(n); cin >> a;

  int q; cin >> q;
  for(int x, y; q--;){
    cin >> x >> y;

    int low = n;
    for(int left = 0, right = n - 1; left <= right;){
      int mid = (left + right) / 2;
      if(a[mid] <= x) left = mid + 1;
      else low = mid, right = mid - 1;
    }

    int high = -1;
    for(int left = low, right = n - 1; left <= right;){
      int mid = (left + right) / 2;
      if(a[mid] <= y) high = mid, left = mid + 1;
      else right = mid - 1;
    }

    print(max(0LL, high - low + 1));
  }
}

signed main(){
  // #define INTERACTIVE
  #ifdef INTERACTIVE
  #undef endl
  #else
  fastio;
  #endif

  // precompute();
  cout << setprecision(1) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}