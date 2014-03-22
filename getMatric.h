#include <cv.h>
#include <highgui.h>
#include <vector>
#include "cxcore.h"

using namespace std;

typedef vector<pair<CvPoint2D32f,CvPoint2D32f>> Ipoint_Vec; 

/*function:得到变换矩阵
	para:Ipoint_vec::四对匹配点构成的容器;
	out:变换矩阵
*/
CvMat* getMatric(Ipoint_Vec points);

/*function:将倾斜的图像变正
*/

IplImage* viewTransform( IplImage* src, CvPoint2D32f* srcTri, CvPoint2D32f* dstTri );

