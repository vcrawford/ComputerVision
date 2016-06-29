/**
  * Get the jth element of the ith block
  */
template <class X>
X* getElement(double* arr, int i, int j, int blk_len) 
{
   return &arr[i*blk_len + j];
}


/**
  * Average the first num elements of an array of arrays
  * arr is an array that is full of array of length len
  * Puts the average in array avg
  */
template <class X>
void computeAverageArray(X* arr, int num, int len, X* avg) 
{
	setToZero(avg, len);

	double weight = 1/(double)num;

   for (int i = 0; i < num; i++) {
      for (int j = 0; j < len; j++) {
			avg[j] += weight*arr[i*len + j];
   	}
   }

}

template <class X>
void printArray(X* arr, int length)
{
   for (int i = 0; i < length; i++) {
      cout << arr[i];
      if (i != (length - 1)) {
			cout << ", ";
      }
   }

   cout << endl;

}

void setToZero(double* vec, int length) 
{
   for (int i = 0; i < length; i++) {
   	vec[i] = 0;
   }
}


void printMatrix(double* mat, int rows, int cols)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << mat[i*cols + j] << " ";
		}
      cout << endl;
   }
}


