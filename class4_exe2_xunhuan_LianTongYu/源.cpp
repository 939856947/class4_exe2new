#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{


	cv::Mat disMat = imread("D:\\333.jpg");
	Mat disMat_gray;//彩色图像转化成灰度图  
	Mat disMat_erzhi;
	Mat disMat_label;
	Mat labels;
	Mat stats;
	Mat	centroids;
	cv::Rect rect;

	int num;
	int i;
	int j;
	cvtColor(disMat, disMat_gray, COLOR_BGR2GRAY);//转化为灰度图
	threshold(disMat_gray, disMat_erzhi, 100, 255, THRESH_BINARY);//二值化
																  //Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//内核	
	num = connectedComponentsWithStats(disMat_erzhi, disMat_label, stats, centroids, 8, CV_32S);
	cout << "num=" << num - 1 << endl;
	cout << "" << stats << endl;
	cout << "" << centroids << endl;
	for (int i = 1; i < num; i++)
	{
		rect.x = stats.at<int>(i, 0);
		rect.y = stats.at<int>(i, 1);
		rect.width = stats.at<int>(i, 2);
		rect.height = stats.at<int>(i, 3);
		rectangle(disMat_erzhi, rect, CV_RGB(0,100, 233), 1, 8, 0);
	}	
	imshow("erzhi", disMat_erzhi);
	waitKey(0);
	return 0;

}