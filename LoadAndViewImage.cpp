
Mat* loadImages(string* img_names, int num) {
   Mat* images = new Mat [num];

   for (int i = 0; i < num; i++) {
		images[i] = imread(img_names[i]);
   }

   return images;
}


void displayImage(Mat* image) {

   namedWindow("OpenCv Image");
   imshow("OpenCv Image", *image);
   waitKey(0);

}


