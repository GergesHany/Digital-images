#include <bits/stdc++.h>
using namespace std; 

 //  Floyd-Stainberg Error Diffusion Algorithm (Black and White Image Conversion)


int main()
{


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
  
  
  return 0;
}
