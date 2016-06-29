
/**
  * Compute the covariance matrix of num_vecs feature vectors
  * stored in ftr_vecs
  * The length of each feature vector is ftr_len
  * The covariance matrix is stored in cov_mx
  */
void computeCovarianceMatrix(double* ftr_vecs, double* avg_vec, int ftr_len,
                             int num_vecs, double* cov_mx)
{

	setToZero(cov_mx, ftr_len*ftr_len);

   double avg, avg_i, avg_j, dev_i, dev_j;
	double weight = 1/(double)num_vecs;

	for (int i = 0; i < ftr_len; ++i) {
		for (int j = 0; j <= i; ++j) {
         avg_i = avg_vec[i];
         avg_j = avg_vec[j];
			for (int k = 0; k < num_vecs; ++k) {
				dev_i = ftr_vecs[k*ftr_len + i] - avg_i; 
				dev_j = ftr_vecs[k*ftr_len + j] - avg_j; 
				avg += weight*dev_i*dev_j;
			}
         cov_mx[i*ftr_len + j] = avg;
         cov_mx[j*ftr_len + i] = avg;
      	avg = 0;
		}
   }
}

template<int x, int y>
void eigenMatrix(Matrix<double, x, y>* mx, double* old_mx) {

   for (int i = 0; i < x; ++i) {
		for (int j = 0; j <= i; ++j) {
			mx->operator()(i, j) = old_mx[i*x + j];
			mx->operator()(j, i) = old_mx[i*x + j];
		}
	}
} 
