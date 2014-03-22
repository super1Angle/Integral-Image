#include "getMatric.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
//	CvPoint2D32f src[4], dst[4];
//	IplImage* srcImage1 = cvLoadImage( "image/�ز�/1.jpg" );
//	IplImage* srcImage2 = cvLoadImage( "image/�ز�/3.jpg" );
//	IplImage* dstImage1;
//	IplImage* dstImage2;
	vector<Mat> imgs;
	Mat pano;
///*�õ���һ��ͼ��viewTransform1*/
//	src[0].x = 1093;
//	src[0].y = 693;
//	src[1].x = 1242;
//	src[1].y = 705;
//	src[2].x = 1095;
//	src[2].y = 939;
//	src[3].x = 1242;
//	src[3].y = 945;
//
//	dst[0].x = 937;
//	dst[0].y = 497;
//	dst[1].x = 1097;
//	dst[1].y = 497;
//	dst[2].x = 937;
//	dst[2].y = 747;
//	dst[3].x = 1097;
//	dst[3].y = 747;
//
//	dstImage1 = viewTransform( srcImage1, src, dst );
//	cv::Mat result( dstImage1 );
//	imwrite( "viewTransform1.jpg", result );
//
//
///*�õ��ڶ���ͼ��viewTransform2*/
//
//	src[0].x = 809;
//	src[0].y = 731;
//	src[1].x = 927;
//	src[1].y = 725;
//	src[2].x = 793;
//	src[2].y = 943;
//	src[3].x = 914;
//	src[3].y = 940;
//
//	dst[0].x = 809;
//	dst[0].y = 731;
//	dst[1].x = 939;
//	dst[1].y = 731;
//	dst[2].x = 809;
//	dst[2].y = 947;
//	dst[3].x = 939;
//	dst[3].y = 947;
//
//	dstImage2 = viewTransform( srcImage2, src, dst );
//	cv::Mat result1( dstImage2 );
//	imwrite( "viewTransform2.jpg", result1 );
	/*�м���һ����ʵ���˶Ա任��ͼ��ļ��ã�����ʹ�ñ߿��ϲ����ֺ�ɫ���򣬷����ƴ��
	ʧ��(�ⲿ������photoshop�ֶ�ʵ�ֵ�)��ǰ��һ���ֳ�����ʵ��������޹أ���ֻ��Ϊ��
	��������photoshop���õ�ԭʼͼƬ���������Ƕ�����úõ�ͼƬ*/
	
	Mat result1 = imread( "image/�ز�/panorama1.jpg" );
	Mat result2 = imread( "image/�ز�/panorama.jpg" );
	//Mat result2 = imread( "image/�ز�/panorama.jpg" );
	//Mat result3 = imread( "image/�ز�/viewTransform11" );

	imgs.push_back( result1 );
	imgs.push_back( result2 );
	//imgs.push_back( result3 );

	Stitcher stitcher = Stitcher::createDefault( false );
    Stitcher::Status status = stitcher.stitch(imgs, pano);
	printf( "%d", status == Stitcher::OK );

    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << status << endl;
        return -1;
    }

    imwrite( "panorama.jpg", pano );
	/*cvReleaseImage( &dstImage2 );*/
	/*cvReleaseImage( &srcImage2 );
	cvReleaseImage( &srcImage1 );*/
	/*cvReleaseImage( &dstImage1 );*/
	
	return 0;
}

