#include <cv.h>
#include <highgui.h>
#include <vector>
#include "cxcore.h"

using namespace std;

typedef vector<pair<CvPoint2D32f,CvPoint2D32f>> Ipoint_Vec; 

/*function:�õ��任����
	para:Ipoint_vec::�Ķ�ƥ��㹹�ɵ�����;
	out:�任����
*/
CvMat* getMatric(Ipoint_Vec points);

/*function:����б��ͼ�����
*/

IplImage* viewTransform( IplImage* src, CvPoint2D32f* srcTri, CvPoint2D32f* dstTri );

