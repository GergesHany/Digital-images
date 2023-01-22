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

  for (auto &row : matrix) 
   for (auto &col : row) 
    cin >> col; // read the image matrix (0 <= col <= 255)


  int threshold = 0; // the threshold value (0 <= threshold <= 255) 
  
  // To keep the overall image brightness the same, you should
  // calculate the average brightness of the original image and
  // set the threshold to that value.


  long long sum = 0; // the sum of all the pixels in the image
  for (auto &row : matrix) 
   for (auto &col : row) 
    sum += col; // sum all the pixels in the image

  threshold = sum / (n * m); // calculate the threshold value

  // Now, we will convert the image to black and white
  // using the threshold value
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
     if (matrix[i][j] >= threshold) ans[i][j] = 255; // if the pixel is greater than the threshold, make it white
     else ans[i][j] = 0; // if the pixel is less than the threshold, make it black
   }
  }  

  // print the new image matrix
  for (auto &row : ans) {
   for (auto &col : row) 
     cout << col << " ";
   cout << "\n";
  }


  return 0;
}