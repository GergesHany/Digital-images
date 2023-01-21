#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-18
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define watch(x) cout << (#x)<<" = "<<x<< "\n"
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
const ll N = 2 * 1e5 + 5;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1000000007;
const ll INF = 1LL << 60;
const double PI = acos(-1.0);
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

ll fast(ll n, ll x) { return !x ? 1 : fast(n * n % mod, x >> 1) * (x & 1 ? n : 1) % mod; }
ll invese(ll b) { return fast(b, mod - 2); }

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; return out;
}


/*

 * don't be lazy in thinking 
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down
 * Think of different views of the problem. don't look from only one side

*/


void Floyd_Stainberg_Error_Diffusion_Algorithm(){

 //  Floyd-Stainberg Error Diffusion Algorithm (Black and White Image Conversion)

  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int > (m)); // the matrix of the image
  vector < vector < int > > ans(n, vector < int > (m)); // the matrix of the new image

  // input the matrix of the image
  for (auto &x : matrix) 
    for (auto &y : x) 
      cin >> y;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){

      int old = matrix[i][j]; // the old value for the pixel

      // 128 is the threshold value for black and white 
      int new_ = (old >= 128) ? 255 : 0; // 255 is the max value for white and 0 is the min value for black 
      ans[i][j] = new_; // the new value for the pixel
      int error = old - new_; // the error between the old value and the new value
      
      // the error is distributed to the next pixels
      if(j + 1 < m) matrix[i][j + 1] += (error * 7) / 16; // 7 / 16 is the percentage of the error that is distributed to the next pixel
      if(i + 1 < n && j - 1 >= 0) matrix[i + 1][j - 1] += (error * 3) / 16; // 3 / 16 is the percentage of the error that is distributed to the next pixel 
      if(i + 1 < n) matrix[i + 1][j] += (error * 5) / 16; // 5 / 16 is the percentage of the error that is distributed to the next pixel
      if(i + 1 < n && j + 1 < m) matrix[i + 1][j + 1] += (error * 1) / 16; // 1 / 16 is the percentage of the error that is distributed to the next pixel

    }
  }
  
  // output the matrix of the new image
  for (auto &x : ans) {
    for (auto &y : x) 
      cout << y << " ";
    cout << "\n";
  }


}


void Threshold_Dithering(){

  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int > (m)); // the matrix of the image
  vector < vector < int > > ans(n, vector < int > (m)); // the matrix of the new image

  // Threshold Dithering algorithm (Black and White Image Conversion)


  int threshold = 128; // the threshold value for black and white

  // input the matrix of the image
  for (auto &x : matrix) 
    for (auto &y : x) 
      cin >> y;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        ans[i][j] = (matrix[i][j] >= threshold) ? 255 : 0;
    }
  }    

  // output the matrix of the new image
  for (auto &x : ans) {
    for (auto &y : x) 
      cout << y << " ";
    cout << "\n";
  }

}


void ordered_dithering(){


  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int > (m)); // the matrix of the image
  vector < vector < int > > ans(n, vector < int > (m)); // the matrix of the new image
  vector < vector < int > > Threshold(n, vector < int > (m)); // the matrix of the error


  // input the matrix of the image
  for (auto &x : matrix) 
    for (auto &y : x) 
      cin >> y;


  // ordered dithering algorithm (Black and White Image Conversion)
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        Threshold[i][j] = (matrix[i][j] >= 128) ? 255 : 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        ans[i][j] = (matrix[i][j] >= Threshold[i][j]) ? 255 : 0;
    }
  }

  // output the matrix of the new image
  for (auto &x : ans) {
    for (auto &y : x) 
      cout << y << " ";
    cout << "\n";
  }


}

void Accepted(){

  // pattern dithering algorithm (Black and White Image Conversion)


  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int > (m)); // the matrix of the image
  vector < vector < int > > ans(n, vector < int > (m)); // the matrix of the new image
  
  // input the matrix of the image
  for (auto &x : matrix) 
    for (auto &y : x) 
      cin >> y;

  vector < vector < int > > pattern = {{0, 2}, {3, 1}, {2, 0}, {1, 3}}; // the pattern of the dithering algorithm
  int size = 4; // the size of the pattern

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        ans[i][j] = (matrix[i][j] >= pattern[i % size][j % size]) ? 255 : 0;
    }
  }

  // output the matrix of the new image
  for (auto &x : ans) {
    for (auto &y : x) 
      cout << y << " ";
    cout << "\n";
  }

}

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}