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

void solve(char s){
  deque<char> cards[2];
  cin >> s; cards[0].eb(s);
  for(int i = 1; i < 52; i++) cin >> s >> s, cards[i % 2].eb(s);
  
  auto faceCard = [&](char c){
    return c == 'A' ? 4 : c == 'K' ? 3 : c == 'Q' ? 2 : c == 'J';
  };

  // for(auto i : cards[0]) printsp(i); print();
  // for(auto i : cards[1]) printsp(i); print();
  // print();
  
  deque<char> temp;
  // int cnt = 0;
  for(int i = 0; !cards[i].empty() && !cards[i ^ 1].empty(); i ^= 1){
    
    // print("Saya main ", i);
    
    temp.eb(cards[i].back());
    int place = faceCard(cards[i].back()); 
    cards[i].pop_back();
    int last = -1;
    
    for(; place > 0 && !cards[i ^ 1].empty(); place--){
      temp.eb(cards[i ^ 1].back());
      int next = faceCard(cards[i ^ 1].back());
      cards[i ^ 1].pop_back();
      
      last = i;
      if(next > 0) place = next + 1, i ^= 1;
    }

    if(cards[i ^ 1].empty()) break;

    if(last != -1){
      for(; !temp.empty(); temp.pop_front()){
        cards[last].push_front(temp.front());
      }
      i ^= 1;
    }



    // if(cnt++ == 100) break;
    // for(auto i : cards[0]) printsp(i); print();
    // for(auto i : cards[1]) printsp(i); print();
    // for(auto i : temp) printsp(i); print();
    // print();
  }




  // for(auto i : cards[0]) printsp(i); print();
  // for(auto i : cards[1]) printsp(i); print();
  // print();

  // print(len(cards[0]));
  // print(len(cards[1]));

  if(cards[0].empty()){
    printsp(1);
    if(len(cards[1]) < 10) prin(0);
    print(len(cards[1]));
  } else {
    printsp(2);
    if(len(cards[0]) < 10) prin(0);
    print(len(cards[0]));
  }
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  for(char s; cin >> s && s != '#';)
  solve(s);
}