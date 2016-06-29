#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <cmath>
#include <sstream>
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>

using namespace std;
using namespace cv;
using namespace Eigen;

Mat* loadImages(string*, int);
void displayImage(Mat*);
void computeFeatureVector(Mat*, int, int, double*);
double getPixelMagnitude(uchar*, int);
template <class X>
void printArray(X*, int); 
void computeFeatureVectors(Mat*, double*, int, int);
double* getFeatureVector(double*, int, int, int, int);
template <class X>
X* getElement(double*, int, int, int); 
template <class X>
void computeAverageArray(X*, int, int, X*); 
void computeAverageFeatureVectorNew(double*, int, int, double*);
void setToZero(double*, int);
void computeCovarianceMatrix(double*, double*, int, int, double*);
void printMatrix(double*, int, int);
template<int x, int y>
void eigenMatrix(Matrix<double, x, y>*, double*); 

#include "ArrayUtil.cpp"
#include "LoadAndViewImage.cpp"
#include "FeatureVector.cpp"
#include "CovarianceMatrix.cpp"


