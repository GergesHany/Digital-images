#include <bits/stdc++.h>
using namespace std; 


// Ordered Dithering algorithm 

int main()
{

  int n, m;
  cin >> n >> m;
  // n is the number of rows and m is the number of columns
  vector < vector < int > > matrix(n, vector < int >(m)); // the matrix of the image
  for (auto &x : matrix) 
    for (auto &y : x) 
     cin >> y;


  int k;
  cin >> k; // k is the size of the threshold matrix
  vector < vector < int > > thr(k, vector < int >(k)); // the threshold matrix
  for (auto &x : thr) 
    for (auto &y : x) 
     cin >> y;

  vector< vector < int > > ans(n, vector < int >(m)); // the output matrix
  
  for(int i = 0; i < n; i += k) // loop over the image matrix
  {
    for(int j = 0; j < m; j += k) // loop over the image matrix
    {
      for(int x = 0; x < k; x++) // loop over the threshold matrix
      {
        for(int y = 0; y < k; y++){ // loop over the threshold matrix
          // if the pixel is greater than the threshold pixel then make it 255 else make it 0
          if(matrix[i + x][j + y] >= thr[x][y]) ans[i + x][j + y] = 255;
          else ans[i + x][j + y] = 0;
        }
      }
    }
  }
  
  for (auto &x : ans){
    for (auto &y : x) 
      cout << y << " ";
    cout << "\n";
  }

  
  return 0;
}
