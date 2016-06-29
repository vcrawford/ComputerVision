
/**
  * Compute the feature vector for every pixel in the image and put it
  * in feature_vectors
  */
void computeFeatureVectors(Mat* img, double* ftr_vecs, int ftr_len, int pix_len) 
{
   int k = 0;
   for (int i = 1; i < (img->rows - 1); ++i) {
      for (int j = 1; j < (img->cols - 1); ++j) {
         computeFeatureVector(img, i, j, &ftr_vecs[k]);
         k += ftr_len;
      }
   } 

}

/** 
 * Get the feature vector from image at x and y coordinates, put into
 * feature_vector
 */
void computeFeatureVector(Mat* img, int x, int y, double* ftr_vec)
{

   Vec3b px = img->at<Vec3b>(x, y);
   Vec3b px_nxt_x = img->at<Vec3b>(x + 1, y);
   Vec3b px_lst_x = img->at<Vec3b>(x - 1, y);
   Vec3b px_nxt_y = img->at<Vec3b>(x, y + 1);
   Vec3b px_lst_y = img->at<Vec3b>(x, y - 1);

	Vec3b dI_x = px_nxt_x - px;
	double dI_x_nm = norm(dI_x);
	Vec3b dI_y = px_nxt_y - px;
   double dI_y_nm = norm(dI_y);

   ftr_vec[0] = x;
   ftr_vec[1] = y;
   ftr_vec[2] = dI_x_nm;
   ftr_vec[3] = dI_y_nm;
   ftr_vec[4] = sqrt(pow(dI_x_nm, 2) + pow(dI_y_nm, 2));
   ftr_vec[5] = norm(dI_x - (px - px_lst_x));
   ftr_vec[6] = norm(dI_y - (px - px_lst_y));
   if (dI_y_nm != 0) {
	   ftr_vec[7] = atan(dI_x_nm/dI_y_nm);
	}
   else if (dI_x_nm < 0) {
		ftr_vec[7] = -M_PI/2;
	}
   else {
		ftr_vec[7] = M_PI/2;
	}

}

/**
  * Get the feature vector corresponding to the ith row and the jth column
  * ftr_arr holds all feature vector values
  * ftr_len is the length of the feature vectors 
  */
double* getFeatureVector(double* ftr_arr, int ftr_len, int cols, int i, int j)
{
	return getElement<double>(ftr_arr, i*cols + j, 0, ftr_len);
}


