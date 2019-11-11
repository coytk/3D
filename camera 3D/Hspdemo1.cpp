//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <WinSock2.h>
//#include <opencv2/opencv.hpp>
//#include <thread>
//#include <stdio.h>
//#include <windows.h>
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/videoio.hpp"
//#include<DynaFlash.h>
//#include<HighSpeedProjector.h>
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include<math.h>
//
//# pragma once
//
//#include <WinSock2.h>
//#include <opencv2/opencv.hpp>
//#include <thread>
//
//#ifdef USE_GL_AND_SLAVE
//#pragma comment( lib, "opengl32" )
//#pragma comment( lib, "glew32s" )
//#pragma comment( lib, "glfw3" )
//#pragma comment( lib, "SOIL" )
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#endif
//
//#ifdef _DEBUG
//#define CAMERA_EXT "d.lib"
//#else
//#define CAMERA_EXT ".lib"
//#endif
//
//#define STR_EXP(__A) #__A
//#define STR(__A) STR_EXP(__A)
//#define CV_VER STR(CV_VERSION_MAJOR) STR(CV_VERSION_MINOR) STR(CV_VERSION_REVISION)
//#pragma comment(lib, "opencv_world" CV_VER CAMERA_EXT)
//
//#include <HSC/baslerClass.hpp>
//#pragma comment(lib, "BaslerLib" CAMERA_EXT)
//
//
//#ifdef USE_GL_AND_SLAVE
//#include "HighSpeedProjector.h"
//#include <conio.h>
//#ifdef _DEBUG
////#pragma comment( lib, "opencv_world310d" )
//#pragma comment( lib, "DynaFlash100d" )
//#else
////#pragma comment( lib, "opencv_world310" )
//#pragma comment( lib, "DynaFlash100" )
//#endif
//#endif
//
//
//#pragma comment(lib,"ws2_32.lib")
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define BUFFER_SIZE 1024
//
//#include <iostream>
//
//#include "Shader.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//void mouse_callback(GLFWwindow* window, double xPos, double yPos);
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//# define USE_PROJECTOR 0
//# define AREA_THRESHOLD_MIN 2 //---- 椫妔拪弌偺嵟彫抣 1.5
//# define AREA_THRESHOLD_MAX 100 //---- 椫妔拪弌偺嵟戝抣 30
//# define CAPTURE_BUFFER_NUM 50
//# define TRACKING_ROI_SIZE 25 //---- 僩儔僢僉儞僌帪偺ROI僒僀僘
//# define TRACKING_ROI_SIZE_HALF ((TRACKING_ROI_SIZE-1)/2)
//using namespace std;
//
//
//// 设置
//const unsigned int SCR_WIDTH = 1024;
//const unsigned int SCR_HEIGHT = 768;
//
//float rowang;
//float colang;
//
//float factor = 0.25f;
//double fov = 18.9f;
//
//float vertices[] = {
//	-0.25f, -0.25f, -0.25f, 0.0f, 0.0f,
//	0.25f, -0.25f, -0.25f, 1.0f, 0.0f,
//	0.25f, 0.25f, -0.25f, 1.0f, 1.0f,
//	0.25f, 0.25f, -0.25f, 1.0f, 1.0f,
//	-0.25f, 0.25f, -0.25f, 0.0f, 1.0f,
//	-0.25f, -0.25f, -0.25f, 0.0f, 0.0f,
//
//	-0.25f, -0.25f, 0.25f, 0.0f, 0.0f,
//	0.25f, -0.25f, 0.25f, 1.0f, 0.0f,
//	0.25f, 0.25f, 0.25f, 1.0f, 1.0f,
//	0.25f, 0.25f, 0.25f, 1.0f, 1.0f,
//	-0.25f, 0.25f, 0.25f, 0.0f, 1.0f,
//	-0.25f, -0.25f, 0.25f, 0.0f, 0.0f,
//
//	-0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//	-0.25f, 0.25f, -0.25f, 1.0f, 1.0f,
//	-0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//	-0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//	-0.25f, -0.25f, 0.25f, 0.0f, 0.0f,
//	-0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//
//	0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//	0.25f, 0.25f, -0.25f, 1.0f, 1.0f,
//	0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//	0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//	0.25f, -0.25f, 0.25f, 0.0f, 0.0f,
//	0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//
//	-0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//	0.25f, -0.25f, -0.25f, 1.0f, 1.0f,
//	0.25f, -0.25f, 0.25f, 1.0f, 0.0f,
//	0.25f, -0.25f, 0.25f, 1.0f, 0.0f,
//	-0.25f, -0.25f, 0.25f, 0.0f, 0.0f,
//	-0.25f, -0.25f, -0.25f, 0.0f, 1.0f,
//
//	-0.25f, 0.25f, -0.25f, 0.0f, 1.0f,
//	0.25f, 0.25f, -0.25f, 1.0f, 1.0f,
//	0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//	0.25f, 0.25f, 0.25f, 1.0f, 0.0f,
//	-0.25f, 0.25f, 0.25f, 0.0f, 0.0f,
//	-0.25f, 0.25f, -0.25f, 0.0f, 1.0f
//};
//
//glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(2.0f, 5.0f, -15.0f),
//	glm::vec3(-1.5f, -2.2f, -2.5f),
//	glm::vec3(-3.8f, -2.0f, -12.3f),
//	glm::vec3(2.4f, -0.4f, -3.5f),
//	glm::vec3(-1.7f, 3.0f, -7.5f),
//	glm::vec3(1.3f, -2.0f, -2.5f),
//	glm::vec3(1.5f, 2.0f, -2.5f),
//	glm::vec3(1.5f, 0.2f, -1.5f),
//	glm::vec3(-1.3f, 1.0f, -1.5f)
//};
//
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//float xx;
//float yy;
//
//float eyedis;
//
//float deltaTime = 0.0f;  //两帧之间的间隔时紒E
//float lastFrame = 0.0f;  //上一帧绘制的时紒E
//
//float screenwidth = 3.6;
//float screenheight = 2.0;
//float screendepth = 6.0;
//
//float lastX = 400, lastY = 300;
//bool firstMouse = true;
//float yaw = 0.0f, pitch = 0.0f;
//cv::Point centroid_arr;       //廳怱嵗昗
//int main() {
//
//	int height = 480;
//	int width = 640;
//
//	auto temp = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	int k;
//
//	cv::VideoCapture cap(0);
//	if (!cap.isOpened())
//		exit(1);
//
//	//Mat temp;
//	//Mat linshi;
//	//Mat temp(height, width, CV_8UC3);
//	cv::Mat linshi(height, width, CV_8UC1);
//	float a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	cv::Mat frameDisp;
//	glm::vec3 front;
//	LARGE_INTEGER nFreq;
//	LARGE_INTEGER nBeginTime;
//	LARGE_INTEGER nEndTime;
//	double time;
//	std::vector<cv::Mat> frameGrayBuffer;        //夋憸僨乕僞傪娗棟偡傞儕儞僌僶僢僼傽
//	cv::Mat frameGray_bin = cv::Mat::zeros(height, width, CV_8UC1);    //擇抣壔夋憸
//	cv::Mat frameGray = cv::Mat::zeros(height, width, CV_8UC1);
//	int latest_buffer_idx = 0;        // 嵟怴偺夋憸偺僶僢僼傽埵抲
//	int latest_proc_buffer_idx = 0;        //捈慜偵撉傒庢偭偨僶僢僼傽偺埵抲
//
//										   //cv::Point centroid_arr;        //廳怱嵗昗
//
//
//										   //    frameGrayBuffer弶婜壔
//	for (int buffer_idx = 0; buffer_idx < CAPTURE_BUFFER_NUM; buffer_idx++) {
//		frameGrayBuffer.push_back(cv::Mat::zeros(height, width, CV_8UC1));
//	}
//
//	// 僋儔僗偺嶌惉
//	HighSpeedProjector hsproj;
//
//	// 搳塭儌乕僪偺愝掕
//	hsproj.set_projection_mode(PM::MIRROR);               // 儈儔乕儌乕僪ON
//
//	hsproj.set_projection_mode(PM::FLIP);
//
//	// hsproj.set_projection_mode( PM::ILLUMINANCE_HIGH );     // 崅徠搙儌乕僪偵曄峏( 挿偔搳塭偟偰偄傞応崌偼ON偵偟偪傖偩傔 
//
//	// 搳塭僷儔儊僞偺愝掕
//	hsproj.set_parameter_value(PP::FRAME_RATE, 1500);
//	hsproj.set_parameter_value(PP::BUFFER_MAX_FRAME, 50);
//
//	// 搳塭夋憸偺弨旛
//	auto image = cv::imread("0000.jpg", 0);
//	//cv::imshow("image", image);
//	//cv::waitKey(10);
//
//	// 搳塭奐巒
//	hsproj.connect_projector();
//
//
//	//auto linshi = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	auto result = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	cv::namedWindow("contours", cv::WINDOW_AUTOSIZE | cv::WINDOW_FREERATIO);
//	//廳怱埵抲弶婜壔
//	while (1) {
//
//		//夋憸庢摼
//		cap >> temp;
//		//imshow("test", temp);
//		//QueryPerformanceFrequency(&nFreq);
//		//QueryPerformanceCounter(&nBeginTime);
//
//		cvtColor(temp, linshi, CV_RGB2GRAY);
//		//cvtColor(temp, result, CV_RGB2GRAY);
//
//		//QueryPerformanceCounter(&nEndTime);
//		//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		//printf("cap thread : %f us \n", time * 1000000);
//
//		flip(linshi, result, 1);
//		frameGray = result;
//		//    2抣壔
//		cv::adaptiveThreshold(frameGray, frameGray_bin, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 9, 8);
//		//    椫妔拪弌
//		std::vector<std::vector<cv::Point>> contour_;
//		cv::findContours(frameGray_bin, contour_, cv::noArray(), cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//		//    柺愊偺彫偝偄or戝偒偄椫妔傪嶍彍
//		auto contour_it = std::remove_if(contour_.begin(), contour_.end(), [](const std::vector<cv::Point> & p) {return cv::contourArea(p) < AREA_THRESHOLD_MIN || cv::contourArea(p) > AREA_THRESHOLD_MAX; });
//		contour_.erase(contour_it, contour_.end());
//		//if (contour_.size() != 1) return -1; 
//		//    廳怱傪寁嶼
//		for (auto& contour : contour_) {
//			cv::Moments moment = cv::moments(contour, true);
//			centroid_arr = cv::Point(moment.m10 / moment.m00, moment.m01 / moment.m00);
//		}
//
//		cv::circle(frameGray, centroid_arr, 3, cv::Scalar(255), 1);
//		cv::imshow("contours", frameGray);
//		int key = cv::waitKey(1);
//		if (key == 'q') {
//			break;
//		}
//		//cv::waitKey(1);
//		//a = time * 1000000 + a;
//		//b++;
//		//QueryPerformanceCounter(&nEndTime);
//		//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		//printf("cap thread : %f us \n", time * 1000000);
//	}
//
//	bool flag = true;
//	//    夋憸庢摼
//	std::thread thrA([&] {  // frameGrayBuffer偵嶣憸偟偨夋憸傪曐懚偡傞僗儗僢僪
//
//		while (flag) {  //  僗儗僢僪A偱偼(僨乕僞傪彂偒崬傓)
//
//			if ((latest_buffer_idx + 1) < frameGrayBuffer.size()) {
//				cap >> temp;  // 僇儊儔偐傜夋憸傪庢摼偟latest_buffer_idx + 1偺埵抲偵曐懚
//							  //QueryPerformanceFrequency(&nFreq);
//							  //QueryPerformanceCounter(&nBeginTime);
//				cvtColor(temp, linshi, CV_RGB2GRAY);
//				//QueryPerformanceCounter(&nEndTime);
//				//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//				//printf("cap thread : %f us \n", time * 1000000);
//				cv::flip(linshi, result, 1);
//				frameGrayBuffer[latest_buffer_idx + 1] = result;
//				latest_buffer_idx++;  //  latest_buffer_idx++偲偟嵟怴偺夋憸偺埵抲傪峏怴偟偰偄傑偡
//			}
//			else {  // latest_buffer_idx++ = buf_size偺帪丄latest_buffer_idx = 0偲偟偰抣傪峏怴
//				cap >> temp;
//				cvtColor(temp, linshi, CV_RGB2GRAY);
//				cv::flip(linshi, result, 1);
//				frameGrayBuffer[0] = result;
//				latest_buffer_idx = 0;
//			}
//
//		}
//	});
//	std::thread thrB([&] {
//		while (flag) {
//			//QueryPerformanceFrequency(&nFreq);
//			//QueryPerformanceCounter(&nBeginTime);
//			if (latest_proc_buffer_idx != latest_buffer_idx) {
//				cv::Point2f roipt1(centroid_arr.x - TRACKING_ROI_SIZE_HALF, centroid_arr.y - TRACKING_ROI_SIZE_HALF);
//				cv::Point2f roipt2(centroid_arr.x + TRACKING_ROI_SIZE_HALF + 1, centroid_arr.y + TRACKING_ROI_SIZE_HALF + 1);
//				if (0 <= roipt1.x && 0 <= roipt1.y && roipt2.x <= width && roipt2.y <= height) { // ROI偑夋柺撪偵偁傞
//					cv::Rect roi(roipt1, roipt2); //Rect偼 pt1 <= x,y < pt2
//					cv::Mat grayroiimg = frameGrayBuffer[latest_buffer_idx](roi);
//					latest_proc_buffer_idx = latest_buffer_idx;
//					cv::Mat binroiimg;
//					cv::adaptiveThreshold(grayroiimg, binroiimg, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 7, 8); // Method=MEAN_C, Block=5*5, C=8
//					cv::Moments moment = cv::moments(binroiimg, true);
//					cv::Point2f roicentroid(moment.m10 / moment.m00, moment.m01 / moment.m00); // ROI偑恀敀偩偭偨応崌偼moment偵曄側抣偑擖傞柾條
//					if (roicentroid.x >= 0 && roicentroid.y >= 0) { // 僩儔僢僉儞僌惉岟
//						centroid_arr = roipt1 + roicentroid;
//						xx = centroid_arr.x;
//						yy = centroid_arr.y;
//					}//僩儔僢僉儞僌幐攕帪峏怴偟側偄
//				}
//			}
//			//QueryPerformanceCounter(&nEndTime);
//			//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//			//printf("track thread : %f us \n", time * 1000000);
//
//		}
//	});
//
//
//	std::thread thrC([&] {
//		while (flag) {
//			frameGray = frameGrayBuffer[latest_buffer_idx];
//			cv::Mat frameDisp(height, width, CV_8UC3);
//			cv::cvtColor(frameGray, frameDisp, cv::COLOR_GRAY2BGR);
//			cv::circle(frameDisp, centroid_arr, 30, cv::Scalar(255, 255, 255), -1);
//			cv::imshow("frameGray_tmp", frameDisp);
//			cv::waitKey(1);
//			//printf("send thread : %f us \n", time * 1000000);
//		}
//	});
//
//
//
//
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	//std::cout << "Let's start!" << std::endl;
//	//system("pause");
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	//glfwSetCursorPosCallback(window, mouse_callback);
//	//glfwSetScrollCallback(window, scroll_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//获取畜属性数量
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	//std::cout << "畜支持的属性数量为：" << nrAttributes << std::endl;
//
//	glEnable(GL_DEPTH_TEST);
//
//	//！创建我们的着色苼E
//	Shader shader("Shader.vs", "Shader.fs");
//
//	//第一个环境
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//纹纴E
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//设置纹历虂E昂凸说姆绞?
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int widthgl, heightgl, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(/*"zhou_yu.bmp"*/"123.png", &widthgl, &heightgl, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthgl, heightgl, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "无法加载问题，莵E丒榇丒蜃试词欠裼形蟆?" << std::endl;
//	stbi_image_free(data);
//
//	//纹纴E
//	//unsigned int texture2;
//	//glGenTextures(1, &texture2);
//	//glActiveTexture(GL_TEXTURE1);	//激畸昶纴E对蟻E
//	//glBindTexture(GL_TEXTURE_2D, texture2);
//	////设置纹历追绕和过滤的方式
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	////加载图片
//	//stbi_set_flip_vertically_on_load(true);
//	//unsigned char* data2 = stbi_load("awesomeface.png", &widthgl, &heightgl, &nrChannels, 0);
//	//if (data2) {
//	//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthgl, heightgl, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//	//    glGenerateMipmap(GL_TEXTURE_2D);
//	//}
//	//else
//	//    std::cout << "无法加载问题，莵E丒榇丒蜃试词欠裼形蟆?" << std::endl;
//	//stbi_image_free(data2);
//
//	//告诉OpenGL哪个采样器属于哪个纹历靴元
//	shader.use();
//	shader.setInt("texture1", 0);
//	//shader.setInt("texture2", 1);
//
//	//变换
//	//glm::mat4 trans;
//	//trans = glm::scale(trans, glm::vec3(0.25f, 0.25f, 0.25f));
//	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//
//
//
//
//	glm::mat4 modelseq[100];
//	for (int i = 0; i < 10; ++i) {
//		modelseq[i] = glm::translate(modelseq[i], cubePositions[i]);
//		float angle = 20.0f * i;
//		modelseq[i] = glm::rotate(modelseq[i], glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//	}
//
//
//	std::thread thrD([&] {
//		while (flag)
//		{
//			//难道又是 hazard??
//			//xx = centroid_arr.x;
//			//yy = centroid_arr.y;
//
//			//screendepth = 490.31*pow(eyedis, -0.98);
//			screendepth = 6.0;
//
//			rowang = abs(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) + atan((screenwidth / 2 - (320 - xx) * 1 / 100) / screendepth));
//			cout << glm::degrees(rowang) << endl;
//			colang = abs(atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth) + atan((screenheight / 2 - (240 - yy) * 1 / 100) / screendepth));
//			cout << glm::degrees(colang) << endl;
//
//			//sleep(1);
//			cv::waitKey(1);
//
//
//			front.x = -sin(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) - 0.5*rowang);
//			front.y = sin(0.5*colang - atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth));
//			front.z = -cos(0.5*colang - atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth)) * cos(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) - 0.5*rowang);
//			//cameraFront = glm::normalize(front);
//			cameraFront = front;
//
//		}
//	});
//
//	cv::Mat model2DImg(768, 1024, CV_8UC3);
//	CvSize size = cvSize(768, 1024);
//	cv::Mat projImgGray(768, 1024, CV_8UC1);
//	cv::Mat projImgGrayop(768, 1024, CV_8UC1);
//
//	while (!glfwWindowShouldClose(window)) {
//		//Sleep(17);
//
//		QueryPerformanceFrequency(&nFreq);
//		QueryPerformanceCounter(&nBeginTime);
//
//		//sleep(50);
//		//cv::waitKey(50);
//		glm::mat4 model;
//		processInput(window);
//
//		//std::cout << centroid_arr << std::endl;
//
//
//		//rowang = abs(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) + atan((screenwidth / 2 - (320 - xx) * 1 / 100) / screendepth));
//		//cout << glm::degrees(rowang) << endl;
//		//colang = abs(atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth) + atan((screenheight / 2 - (240 - yy) * 1 / 100) / screendepth));
//		//cout << glm::degrees(colang) << endl;
//		//fov = glm::degrees(colang);
//
//
//		//front.x = -sin(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) - 0.5*rowang);
//		//front.y = sin(0.5*colang - atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth));
//		//front.z = -cos(0.5*colang - atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth)) * cos(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) - 0.5*rowang);
//		////cameraFront = glm::normalize(front);
//		//cameraFront = front;
//
//
//		//std::cout << xx * 1 / 100 << std::endl;
//		//std::cout << yy * 1 / 100 << std::endl;
//
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		//glActiveTexture(GL_TEXTURE1);
//		//glBindTexture(GL_TEXTURE_2D, texture2);
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		shader.use();
//		glm::mat4 projection;
//		fov = glm::degrees(colang);
//		projection = glm::perspective(glm::radians((float)fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		//float radius = 10.0f;
//		//float camX = sin(glfwGetTime()) * radius;
//		//float camZ = cos(glfwGetTime()) * radius;
//		glm::mat4 view;
//		//view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
//		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//
//		shader.setMat4("view", glm::value_ptr(view));
//		shader.setMat4("projection", glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		// 蟻E丒揭欢盐丒迦谱乓桓龆髯男Ч好恳淮蝫hile循环改变一次主模型（model）的角度，每次循环内的for循环刚开始时将副模型（model1）初始化成主模型（model）
//		// 这样操作之后可以根据每一帧的主模型（model）位置和角度来设定副模型（model1）的位置和角度，也就是说副模型都需要根据主模型来决定位置，蛘效果副模型是绕着主模型转
//		//glm::mat4 model1;
//		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//		//for (int i = 0; i < 10; ++i) {
//		//	model1 = model;
//		//	model1 = glm::translate(model1, cubePositions[i]);
//		//	float angle = 20.0f * i;
//		//	model1 = glm::rotate(model1, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//		//	shader.setMat4("model", glm::value_ptr(model1));
//		//	glDrawArrays(GL_TRIANGLES, 0, 36);
//		//}
//
//		for (int i = 0; i < 10; ++i) {
//			model = modelseq[i];
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//			shader.setMat4("model", glm::value_ptr(model));
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		//glfwSwapBuffers(window);
//
//		glfwPollEvents();
//
//		//glBindBuffer(GL_PIXEL_PACK_BUFFER, tst);
//		//glReadPixels(0, 0, 1024, 768, GL_BGR, GL_UNSIGNED_BYTE, nullptr);
//		//void *ptr = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
//		//memcpy(model2DImg.data, ptr, 1024 * 768 * 3);
//		//glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
//		//cv::cvtColor(model2DImg, projImgGray, CV_BGR2GRAY);
//		//cv::flip(projImgGray, projImgGrayop, 0);
//		//cv::imshow("cvtest", projImgGrayop);
//
//		glReadPixels(0, 0, 1024, 768, GL_BGR, GL_UNSIGNED_BYTE, model2DImg.data); // 
//
//
//		//memcpy(model2DImg.data, buffer, size.width * size.height * (size_t)3);
//		cv::cvtColor(model2DImg, projImgGray, CV_BGR2GRAY);
//		//cv::flip(projImgGray, projImgGrayop, 0);
//		//cv::imshow("cvtest", projImgGray);
//
//
//
//		//if (_kbhit() == true) break;
//		hsproj.send_image_8bit(projImgGray.data);
//		//cv::imshow("flame", flame);
//		//cv::waitKey(1);
//		QueryPerformanceCounter(&nEndTime);
//		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		printf("Latency : %f us \n", time * 1000000);
//	}
//
//	glBindVertexArray(0);
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow *window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//	//	factor += 0.01f;
//	//	if (factor > 1.0f)
//	//		factor = 1.0f;
//	//}
//
//	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//	//	factor -= 0.01f;
//	//	if (factor < 0.0f)
//	//		factor = 0.0f;
//	//}
//	//std::cout << centroid_arr << std::endl;
//	//cameraPos = glm::vec3(centroid_arr.x * 1 / 100, centroid_arr.y * 1 / 100, 4.0f);
//
//
//	//float cameraSpeed = 2.5f * deltaTime; //移动速度
//	//if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	//cameraPos += cameraSpeed * cameraFront;
//
//	// if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	// cameraPos -= cameraSpeed * cameraFront;
//
//	cameraPos = glm::vec3((320 - xx) * 1 / 100, (240 - yy) * 1 / 100, screendepth);
//	/*
//	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
//	cameraPos += cameraSpeed * cameraUp;
//
//	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
//	cameraPos -= cameraSpeed * cameraUp;
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	cameraPos += glm::cross(cameraFront, cameraUp) * cameraSpeed;
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	cameraPos -= glm::cross(cameraFront, cameraUp) * cameraSpeed;
//	*/
//
//	//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	//	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
//
//	//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	//	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
//
//}
//
//void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
//	//static int x = 0;
//
//	//x++;
//	//if (x == 10) {
//	//	int y = 0;
//	//}
//	//if (firstMouse) {
//	//	lastX = xPos;
//	//	lastY = yPos;
//	//	firstMouse = false;
//	//}
//
//	//float xoffset = lastX - xPos;	//别蛠E耍诖翱谥校蟊叩淖丒∮谟冶叩淖辏颐切枰桓稣慕嵌?
//	//float yoffset = lastY - yPos;	//同样，在窗口中，下面的坐眮E笥谏厦娴淖辏颐峭咸返氖焙蛐枰桓稣慕嵌?
//	//lastX = xPos;
//	//lastY = yPos;
//
//	//float sensitivity = 0.05f;
//	//xoffset *= sensitivity;
//	//yoffset *= sensitivity;
//
//	//yaw += xoffset;
//	//pitch += yoffset;
//
//	//if (pitch > 89.0f)
//	//	pitch = 89.0f;
//	//if (pitch < -89.0f)
//	//	pitch = -89.0f;
//
//
//
//
//}
//
////鼠眮E雎窒⒒氐丒
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
////	if (fov >= 1.0 && fov <= 45.0)
////		fov -= yoffset;
////	if (fov <= 1.0)
////		fov = 1.0;
////	if (fov >= 45.0)
////		fov = 45.0;
////}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
