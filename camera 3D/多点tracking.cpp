//# pragma once
//#include "HighSpeedProjector.h"
//#include <conio.h>
//#include <fstream>
//# include <opencv2/opencv.hpp>
//# include <thread>
//# include <stdio.h>
//# include <windows.h>
//# include <string>
//# include <iostream>
//# include <algorithm>
//# include <vector>
//# include <time.h>
//
//# ifdef _DEBUG
//# define CAMERA_EXT "d.lib"
//# else
//# define CAMERA_EXT ".lib"
//# endif
//
//# define STR_EXP(__A) #__A
//# define STR(__A) STR_EXP(__A)
//# define CV_VER STR(CV_VERSION_MAJOR) STR(CV_VERSION_MINOR) STR(CV_VERSION_REVISION)
//# pragma comment(lib, "opencv_world410.lib")
//
//
//# include <HSC/baslerClass.hpp>
//# pragma comment(lib, "BaslerLib" CAMERA_EXT)
//
////add 
///*#include "HighSpeedProjector.h"
//# include <conio.h>
//# ifdef _DEBUG
////#pragma comment( lib, "opencv_world310d" )
//# pragma comment( lib, "DynaFlash100d" )
//# else
////#pragma comment( lib, "opencv_world310" )
//# pragma comment( lib, "DynaFlash100" )
//# endif*/
//
//# define EXPLICIT_ROI 1
//
////# pragma comment(lib,"ws2_32.lib")
//# define _WINSOCK_DEPRECATED_NO_WARNINGS
//# define BUFFER_SIZE 10240
//
//# define USE_PROJECTOR 0
//# define AREA_THRESHOLD_MIN 2 //---- 輪郭抽出の最小値 1.5
//# define AREA_THRESHOLD_MAX 100 //---- 輪郭抽出の最大値 30
//# define CAPTURE_BUFFER_NUM 50
//# define TRACKING_ROI_SIZE 25 //---- トラッキング時のROIサイズ
//# define TRACKING_ROI_SIZE_HALF ((TRACKING_ROI_SIZE-1)/2)
//
//# define CAM_WIDTH 720
//# define CAM_HEIGHT 540
//
//# define DEBUG 1
//# define READY 1
//# define TIME_MEASURE_TRACKING 0
//# define TIME_MEASURE_PROJECTION 0
//# define PROJECTION 0
//
//using namespace std;
//
//int main() {
//	typedef struct _roi {
//		int point_num;
//		cv::Point center;
//		int top = 0;
//		int bottom = 0;
//		int right = 0;
//		int left = 0;
//		cv::Mat roi_img;
//		int step = 1;
//		int min = 20;
//		cv::Point velocity;
//		int state = 0;
//	}ROI;
//
//	ROI roi[4];
//	
//	roi[0].center = cv::Point(0, 0);
//	roi[1].center = cv::Point(CAM_WIDTH, 0);
//	roi[2].center = cv::Point(0, CAM_HEIGHT);
//	roi[3].center = cv::Point(CAM_WIDTH, CAM_HEIGHT);
//	roi[0].point_num = 0;
//	roi[1].point_num = 1;
//	roi[2].point_num = 2;
//	roi[3].point_num = 3;
//
//	cv::Point leftUp, rightBottom;
//
//	int countSuccess = 0;
//	bool isSuccess = false;
//
//	int thresh = 150;
//	cv::Mat gray;
//	cv::Mat bin = cv::Mat::zeros(CAM_HEIGHT, CAM_WIDTH, CV_8UC3);
//	string str;
//
//	cv::Mat tgtimg = cv::Mat::zeros(CAM_HEIGHT, CAM_WIDTH, CV_8UC3);
//	cv::Mat tgttransmat;
//
//	// 変換用
//	cv::Point2f src_pt[4], dst_pt[4];
//	cv::Mat dst = cv::Mat::zeros(CAM_HEIGHT, CAM_WIDTH, CV_8UC3);
//	cv::Mat Redst = cv::Mat::zeros(768, 1024, CV_8UC3);
//
//#if READY
//	//カメラ-プロジェクタ間のホモグラフィ
//	cv::Matx33f Hmt(3, 3, CV_32F);
//	float d1, d2, d3;
//	std::ifstream Hfile("HomographyMatrix.dat");
//	if (!Hfile) {
//		std::cout << "can't open input file." << std::endl;
//		return -1;
//	}
//	int i = 0;
//	while (!Hfile.eof()) {
//		Hfile >> d1 >> d2 >> d3;
//		Hmt(i, 0) = d1;
//		Hmt(i, 1) = d2;
//		Hmt(i, 2) = d3;
//		i++;
//	}
//	i = 0;
//
//	//投影画像の準備
//	cv::Mat clip;
//	cv::Mat Reclip = cv::Mat::zeros(540, 720, CV_8UC3);
//	int whitesize = 30;
//	std::ifstream Cfile("bright.dat");
//	if (!Cfile) {
//		std::cout << "can't open input file." << std::endl;
//		return -1;
//	}
//	cv::Mat primg = cv::imread("bright.jpg");
//	int maxX = 0, maxY = 0, minX = CAM_WIDTH, minY = CAM_HEIGHT;
//	while (!Cfile.eof()) {
//		Cfile >> d1 >> d2;
//		src_pt[i].x = d1;
//		src_pt[i].y = d2;
//		maxX = (maxX < d1) ? d1 : maxX;
//		maxY = (maxY < d2) ? d2 : maxY;
//		minX = (minX > d1) ? d1 : minX;
//		minY = (minY > d2) ? d2 : minY;
//		i++;
//	}
//	
//	
//	cv::Point2f cli_pt[] = {
//		cv::Point2f(src_pt[0].x - minX, src_pt[0].y - minY),
//		cv::Point2f(src_pt[1].x - minX, src_pt[1].y - minY),
//		cv::Point2f(src_pt[2].x - minX, src_pt[2].y - minY),
//		cv::Point2f(src_pt[3].x - minX, src_pt[3].y - minY),
//	};
//
//	cv::Point2f Re_pt[] = {
//		cv::Point2f(0 + whitesize, 0 + whitesize),
//		cv::Point2f(720 - whitesize, 0 + whitesize),
//		cv::Point2f(0 + whitesize, 540 - whitesize),
//		cv::Point2f(720 - whitesize, 540 - whitesize),
//	};
//
//	cv::Rect tmp(cv::Point(minX,minY), cv::Point(maxX, maxY));
//	clip = primg(tmp);
//	cv::imshow("clip1", clip);
//	cv::waitKey(0);
//	cv::Mat Remat = cv::getPerspectiveTransform(cli_pt, Re_pt);
//	cv::warpPerspective(clip, Reclip, Remat, Reclip.size());
//	for (int i = 0; i < 4; i++) {
//		cv::rectangle(Reclip,
//			cv::Point(Re_pt[i].x - whitesize, Re_pt[i].y - whitesize),
//			cv::Point(Re_pt[i].x + whitesize, Re_pt[i].y + whitesize),
//			cv::Scalar(255, 255, 255), -1);
//	}
//
//	cv::imshow("clip", Reclip);
//	cv::imwrite("clip.jpg", Reclip);
//	cv::waitKey(0);
//
//#endif
//
//	basler cam;
//
//	int width = CAM_WIDTH;
//	int height = CAM_HEIGHT;
//	float  fps = 250.0f;
//	float gain = 1.0f;
//	
//	HighSpeedProjector hsproj;
//
//	// 投影モードの設定
//	//hsproj.set_projection_mode(PM::MIRROR);               // ミラーモードON
//	//hsproj.set_projection_mode( PM::ILLUMINANCE_HIGH );     // 高照度モードに変更( 長く投影している場合はONにしちゃだめ 
//
//														  // 投影パラメタの設定
//	hsproj.set_parameter_value(PP::FRAME_RATE, 500);
//	hsproj.set_parameter_value(PP::BUFFER_MAX_FRAME, 50);
//	hsproj.set_projection_mode(PM::COLOR);
//
//	// 投影画像の準備
//	auto white = (cv::Mat(768, 1024, CV_8UC3, cv::Scalar::all(255)));
//
//
//	cv::imshow("image", white);
//	cv::waitKey(10);
//
//	// 投影開始
//	hsproj.connect_projector();
//	hsproj.send_image_24bit(white.data);
//	
//	
//
//
//	auto img = (cv::Mat(height, width, CV_8UC3, cv::Scalar::all(255)));
//
//	cam.connect(0);
//	cam.setParam(paramTypeCamera::paramInt::WIDTH, width);
//	cam.setParam(paramTypeCamera::paramInt::HEIGHT, height);
//	cam.setParam(paramTypeCamera::paramFloat::FPS, fps);
//	cam.setParam(paramTypeCamera::paramFloat::GAIN, gain);
//	cam.setParam(paramTypeBasler::Param::ExposureTime, 3950.0f);
//	cam.setParam(paramTypeBasler::AcquisitionMode::EnableAcquisitionFrameRate);
//	//cam.setParam(paramTypeBasler::FastMode::SensorReadoutModeFast);
//	cam.setParam(paramTypeBasler::GrabStrategy::OneByOne);
//	//cam.setParam(paramTypeBasler::CaptureType::BayerBGGrab);
//	cam.setParam(paramTypeBasler::CaptureType::ColorBGRGrab);
//	//cam.setParam(paramTypeBasler::CaptureType::MonocroGrab);
//	cam.parameter_all_print();
//
//	cam.start();
//
//	bool flag = true;
//	
//	clock_t start, end, start_p, end_p;
//	int okcount=0;
//
//	std::thread thr_t([&] {
//#if TIME_MEASURE_TRACKING
//		int frame = 0;
//		start = clock();
//#endif
//		while (flag) {
//			cam.captureFrame(img.data);
////			cv::imshow("img", img);
//			cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
//			cv::threshold(gray, bin, thresh, 255, cv::THRESH_BINARY);
//			countSuccess = 0;
//			for (int i = 0; i < 4; i++) {
//				leftUp = cv::Point(
//					min(max(roi[i].center.x + roi[i].left, 0), CAM_WIDTH),
//					min(max(roi[i].center.y + roi[i].top, 0), CAM_HEIGHT)
//				);
//				rightBottom = cv::Point(
//					min(max(roi[i].center.x + roi[i].right, 0), CAM_WIDTH),
//					min(max(roi[i].center.y + roi[i].bottom, 0), CAM_HEIGHT)
//				);
//				cv::Rect tmp(leftUp, rightBottom);
//				roi[i].roi_img = bin(tmp);
//				vector<vector<cv::Point> > contours;
//				cv::findContours(roi[i].roi_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
//				
//
//				double max_area = 0;
//
//				int max_area_contour = -1;
//				for (int j = 0; j < contours.size(); j++) {
//					double area = contourArea(contours.at(j));
//					if (max_area < area) {
//						max_area = area;
//						max_area_contour = j;
//					}
//				}
//
//				if (max_area_contour >= 0) {
//					countSuccess++;
//					roi[i].state = 1;
//					int count = contours.at(max_area_contour).size();
//					double x = 0;
//					double y = 0;
//					for (int k = 0; k < count; k++) {
//						int x_ = contours.at(max_area_contour).at(k).x;
//						int y_ = contours.at(max_area_contour).at(k).y;
//						x += x_;
//						y += y_;
//
//					}
//					x /= count;
//					y /= count;
//
//					roi[i].velocity = cv::Point(leftUp.x + x - roi[i].center.x, leftUp.y + y - roi[i].center.y);
//					roi[i].center = cv::Point(leftUp.x + x, leftUp.y + y);
//
//					roi[i].left = min(roi[i].velocity.x, -roi[i].min);
//					roi[i].top = min(roi[i].velocity.y, -roi[i].min);
//					roi[i].right = max(roi[i].velocity.x, roi[i].min);
//					roi[i].bottom = max(roi[i].velocity.y, roi[i].min);
//
//					int maskSize = 20;
//					cv::rectangle(bin, 
//						cv::Point(roi[i].center.x - maskSize, roi[i].center.y - maskSize),
//						cv::Point(roi[i].center.x + maskSize, roi[i].center.y + maskSize),
//						cv::Scalar(0, 0, 0), -1);
//#if DEBUG
//					cv::rectangle(img,
//						cv::Point(roi[i].center.x - maskSize, roi[i].center.y - maskSize),
//						cv::Point(roi[i].center.x + maskSize, roi[i].center.y + maskSize),
//						cv::Scalar(0, 255, 0), -1);
//
//
//#endif
//				} else {
//					roi[i].state = 0;
//					roi[i].velocity = cv::Point(0, 0);
//					roi[i].left = max(roi[i].left - roi[i].step, -CAM_WIDTH);
//					roi[i].top = max(roi[i].top - roi[i].step, -CAM_HEIGHT);
//					roi[i].right = min(roi[i].right + roi[i].step, CAM_WIDTH);
//					roi[i].bottom = min(roi[i].bottom + roi[i].step, CAM_HEIGHT);
//				}
//				
//			}
//			if (countSuccess >= 4) {
//				okcount = 0;
//				isSuccess = true;
//				dst_pt[0] = cv::Point2f((float)roi[0].center.x, (float)roi[0].center.y);
//				dst_pt[1] = cv::Point2f((float)roi[1].center.x, (float)roi[1].center.y);
//				dst_pt[2] = cv::Point2f((float)roi[2].center.x, (float)roi[2].center.y);
//				dst_pt[3] = cv::Point2f((float)roi[3].center.x, (float)roi[3].center.y);				
//			}
//			else {
//				if (okcount > 0) {
//					isSuccess = false;
//					okcount = 0;
//				}
//				okcount++;
//			}
//#if DEBUG
//			for (int i = 0; i < 4; i++) {
//					cv::putText(img, to_string(roi[i].point_num), cv::Point(roi[i].center.x, roi[i].center.y), cv::FONT_HERSHEY_SIMPLEX, 1.2, cv::Scalar(255, 255, 255), 2);
//					leftUp = cv::Point(
//						min(max(roi[i].center.x + roi[i].left, 0), CAM_WIDTH),
//						min(max(roi[i].center.y + roi[i].top, 0), CAM_HEIGHT)
//					);
//					rightBottom = cv::Point(
//						min(max(roi[i].center.x + roi[i].right, 0), CAM_WIDTH),
//						min(max(roi[i].center.y + roi[i].bottom, 0), CAM_HEIGHT)
//					);
//					cv::Scalar color = (roi[i].state == 0) ? cv::Scalar(0, 0, 255) : cv::Scalar(0, 255, 0);
//					cv::rectangle(img,leftUp, rightBottom, color, 2, 3);
//			}
//#endif
//#if TIME_MEASURE_TRACKING
//			end = clock();
//			frame++;
//			if (((double)(end - start) / CLOCKS_PER_SEC) > 1.0) {
//				std::cout << "tracking fps : " << frame << std::endl;
//				frame = 0;
//				start = clock();
//			}
//#endif
//		}		
//	});
//
//	std::thread thr_p([&]{
//#if TIME_MEASURE_PROJECTION
//		int frame = 0;
//		start_p = clock();
//#endif
//		while (flag) {
//#if PROJECTION
//			if (isSuccess) {
//				tgttransmat = cv::getPerspectiveTransform(Re_pt, dst_pt);
//				cv::warpPerspective(Reclip, tgtimg, tgttransmat, tgtimg.size());
//				cv::warpPerspective(tgtimg, Redst, Hmt, Redst.size());
//				hsproj.send_image_24bit(Redst.data);
//			}
//			else {
//				hsproj.send_image_24bit(white.data);
//			}
//#if TIME_MEASURE_PROJECTION
//			end_p = clock();
//			frame++;
//			if (((double)(end_p - start_p) / CLOCKS_PER_SEC) > 1.0) {
//				std::cout << "projection fps : " << frame << std::endl;
//				frame = 0;
//				start_p = clock();
//			}
//#endif
//#endif
//		}
//	});
//	
//	int type = 0;
//	while (1) {
//		switch (type) {
//		case 0: 
//			cv::imshow("img", img);
//			break;
//		case 1:
//			cv::imshow("img", bin);
//			break;
//		default:
//			break;
//		}
//// 		dst_pt[0] = cv::Point2f((float)roi[0].center.x, (float)roi[0].center.y);
//// 		dst_pt[1] = cv::Point2f((float)roi[1].center.x, (float)roi[1].center.y);
//// 		dst_pt[2] = cv::Point2f((float)roi[2].center.x, (float)roi[2].center.y);
//// 		dst_pt[3] = cv::Point2f((float)roi[3].center.x, (float)roi[3].center.y);
//// 		cv::Mat homography_matrix = cv::getPerspectiveTransform(src_pt, dst_pt);
//
//// 		// 透視変換
//// 		cv::warpPerspective(c1, dst, homography_matrix, dst.size());
//
//// 		//ROIを白色で投影
//// 		for (int j = 0; j < 4; j++) {
//// 			cv::rectangle(dst, roi[j].leftUp, roi[j].rightBottom, cv::Scalar(255, 255, 255), -1);
//// 		}
//
//
//// 		cv::warpPerspective(dst, Redst, Hmt, Redst.size());
//// //		cv::imshow("dst", Redst);
//// 		hsproj.send_image_24bit(Redst.data);
//
//		int key = cv::waitKey(1);
//		if (key == 27) { // ESC
//#if 0
//			cv::imwrite("capc.jpg", img);
//			cv::imwrite("capb.jpg", bin);
//			std::ofstream fout("Coordinate.dat");
//			for (int i = 0; i < 4; i++) {				
//				fout << roi[i].center.x << " " << roi[i].center.y << std::endl;
//			}
//#endif
//			/*
//			dst_pt[0] = cv::Point2f((float)roi[0].center.x, (float)roi[0].center.y);
//			dst_pt[1] = cv::Point2f((float)roi[1].center.x, (float)roi[1].center.y);
//			dst_pt[2] = cv::Point2f((float)roi[2].center.x, (float)roi[2].center.y);
//			dst_pt[3] = cv::Point2f((float)roi[3].center.x, (float)roi[3].center.y);
//			*/
//			break;
//		} else if (key == 't') {
//				type = (type + 1) % 2;
//			}
//	
//	}
//
//	flag = false;
//	if (thr_t.joinable())thr_t.join();
//	if (thr_p.joinable())thr_p.join();
//
//	cam.stop();
//	cam.disconnect();
///*
//	cv::waitKey(0);
//	cv::Mat homography_matrix = cv::getPerspectiveTransform(src_pt, dst_pt);
//	cv::Mat c1 = cv::imread("cap1c.jpg");
//	std::cout << homography_matrix;
//	// 透視変換
//	cv::warpPerspective(c1, dst, homography_matrix, dst.size());
//
//	imshow("result", dst);
//	imwrite("result.jpg", dst);
//	cv::waitKey(0);
//*/
//	return 0;
// }