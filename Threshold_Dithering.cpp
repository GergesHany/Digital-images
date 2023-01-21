#include <bits/stdc++.h>
using namespace std; 

// Threshold Dithering algorithm (Black and White Image Conversion)


int main()
{


  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int > (m)); // the matrix of the image
  vector < vector < int > > ans(n, vector < int > (m)); // the matrix of the new image



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
  
  return 0;
}
