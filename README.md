# Image Dithering
## Reducing Effects of Quantization by
- Threshold dithering
- Error diffusion dither (Floyd-Steinberg)
- Ordered dithering
- Pattern dithering

![(793)](https://user-images.githubusercontent.com/105644935/213925949-0d00925e-ad48-4652-89e5-bf92c84f869a.png)


## Threshold Dithering
- For every pixel: If the intensity < 128, replace with black, else replace with white
- 128 is the threshold
- This is the naïve version of the algorithm

# code
```cpp
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
```

To keep the overall image brightness the same, you should:
- Compute the average intensity over the image
- Use a threshold that gives that average
- For example, if the average intensity is 150, use a threshold that is higher than 150 replace with white, else replace with black

# code
```cpp
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
```

![(794)](https://user-images.githubusercontent.com/105644935/213926259-4b73623a-e1fb-4a42-9883-3e45f77d4eea.png)


## Floyd-Steinberg Error Diffusion Dithering
For each pixel in the image (8 bits image) do the following:
- Threshold the pixel (if pixelo >=128 → pixeln=255 else pixeln=0)
- Compute the error at that pixel: error = pixelo - pixeln
- Propagate the error to neighbors by adding some proportion of the error to each unprocessed neighbor

#### A mask tells you how to distribute the error

`pixel[i][j + 1] += (error * 7) / 16`    

`pixel[i + 1][j - 1] += (error * 3) / 16`   

`pixel[i + 1][j] += (error * 5) / 16`  

`pixel[i + 1][j + 1] += (error * 1) / 16`  

![(795)](https://user-images.githubusercontent.com/105644935/213926608-f8c27b36-96d6-4148-8b17-02e6964b6df4.png)

# code
```cpp
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
  
```  




<br><br>

## Ordered Dithering
- Break the image into small blocks (n x n)
- Define a threshold matrix (n x n):
  - Use a different threshold for each pixel of the block
  - Compare each pixel to its own threshold (if pixelo >=Thr → pixeln=255 else pixeln=0)


# code
```cpp
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
      for(int x = 0; x < k; x++) { // loop over the threshold matrix
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
```  














