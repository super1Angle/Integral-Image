#include "getMatric.h"

CvMat* getMatric(Ipoint_Vec points)
{
	CvMat* H, *A, *B, *X;
	float x[9];
	A = cvCreateMat(8, 8, CV_32FC1);
	B = cvCreateMat(8, 1, CV_32FC1);
	H = cvCreateMat(3, 3, CV_32FC1);
	X = &cvMat(8, 1, CV_32FC1, x);
	cvZero(A);

	for(int i = 0;i < 4;i++){
		cvmSet(A, i, 0, points[i].first.x);
		cvmSet(A, i + 4, 3, points[i].first.x);
		cvmSet(A, i, 1, points[i].first.y);
		cvmSet(A, i + 4, 4, points[i].first.y);
		cvmSet(A, i, 2, 1.0);
		cvmSet(A, i+4, 5, 1.0);
		cvmSet(A, i, 6, -points[i].first.x*points[i].second.x);
		cvmSet(A, i + 4, 6, -points[i].first.x*points[i].second.y);
		cvmSet(A, i, 7, -points[i].first.y*points[i].second.x);
		cvmSet(A, i+4, 7, -points[i].first.y*points[i].second.y);
		cvmSet(B, i, 0, points[i].second.x);
		cvmSet(B, i+4, 0, points[i].second.y);
	}

	cvSolve(A, B, X, CV_LU);
	x[8] = 1.0;
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
			cvmSet(H, i, j, x[3*i+j]);

	cvReleaseMat(&A);
	cvReleaseMat(&B);

	return H;
}

/****************************************/
IplImage* viewTransform( IplImage*src, CvPoint2D32f* srcTri, CvPoint2D32f* dstTri )
{
	//CvPoint2D32f srcTri[4], dstTri[4];
	CvMat* H = cvCreateMat( 3, 3, CV_32FC1);
	IplImage* dst;
	
	//dst = cvCloneImage( src );  
	dst = cvCreateImage( cvSize( src->width, src->height ), src->depth, 3 );
	dst->origin = src ->origin;
	cvZero(dst);
	
	
	cvGetPerspectiveTransform( srcTri, dstTri, H );           //得到透视变换矩阵
	cvWarpPerspective( src, dst, H);                                //对图像进行透视变换

	cvReleaseMat( &H );
	//cvReleaseImage( &dst);

	return dst;
}
