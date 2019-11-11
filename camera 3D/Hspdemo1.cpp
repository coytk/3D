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
//# define AREA_THRESHOLD_MIN 2 //---- �֊s���o�̍ŏ��l 1.5
//# define AREA_THRESHOLD_MAX 100 //---- �֊s���o�̍ő�l 30
//# define CAPTURE_BUFFER_NUM 50
//# define TRACKING_ROI_SIZE 25 //---- �g���b�L���O����ROI�T�C�Y
//# define TRACKING_ROI_SIZE_HALF ((TRACKING_ROI_SIZE-1)/2)
//using namespace std;
//
//
//// ����
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
//float deltaTime = 0.0f;  //��֮֡��ļ��ʱ��E
//float lastFrame = 0.0f;  //��һ֡���Ƶ�ʱ��E
//
//float screenwidth = 3.6;
//float screenheight = 2.0;
//float screendepth = 6.0;
//
//float lastX = 400, lastY = 300;
//bool firstMouse = true;
//float yaw = 0.0f, pitch = 0.0f;
//cv::Point centroid_arr;       //�d�S���W
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
//	std::vector<cv::Mat> frameGrayBuffer;        //�摜�f�[�^���Ǘ����郊���O�o�b�t�@
//	cv::Mat frameGray_bin = cv::Mat::zeros(height, width, CV_8UC1);    //��l���摜
//	cv::Mat frameGray = cv::Mat::zeros(height, width, CV_8UC1);
//	int latest_buffer_idx = 0;        // �ŐV�̉摜�̃o�b�t�@�ʒu
//	int latest_proc_buffer_idx = 0;        //���O�ɓǂݎ�����o�b�t�@�̈ʒu
//
//										   //cv::Point centroid_arr;        //�d�S���W
//
//
//										   //    frameGrayBuffer������
//	for (int buffer_idx = 0; buffer_idx < CAPTURE_BUFFER_NUM; buffer_idx++) {
//		frameGrayBuffer.push_back(cv::Mat::zeros(height, width, CV_8UC1));
//	}
//
//	// �N���X�̍쐬
//	HighSpeedProjector hsproj;
//
//	// ���e���[�h�̐ݒ�
//	hsproj.set_projection_mode(PM::MIRROR);               // �~���[���[�hON
//
//	hsproj.set_projection_mode(PM::FLIP);
//
//	// hsproj.set_projection_mode( PM::ILLUMINANCE_HIGH );     // ���Ɠx���[�h�ɕύX( �������e���Ă���ꍇ��ON�ɂ����Ⴞ�� 
//
//	// ���e�p�����^�̐ݒ�
//	hsproj.set_parameter_value(PP::FRAME_RATE, 1500);
//	hsproj.set_parameter_value(PP::BUFFER_MAX_FRAME, 50);
//
//	// ���e�摜�̏���
//	auto image = cv::imread("0000.jpg", 0);
//	//cv::imshow("image", image);
//	//cv::waitKey(10);
//
//	// ���e�J�n
//	hsproj.connect_projector();
//
//
//	//auto linshi = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	auto result = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	cv::namedWindow("contours", cv::WINDOW_AUTOSIZE | cv::WINDOW_FREERATIO);
//	//�d�S�ʒu������
//	while (1) {
//
//		//�摜�擾
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
//		//    2�l��
//		cv::adaptiveThreshold(frameGray, frameGray_bin, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 9, 8);
//		//    �֊s���o
//		std::vector<std::vector<cv::Point>> contour_;
//		cv::findContours(frameGray_bin, contour_, cv::noArray(), cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//		//    �ʐς̏�����or�傫���֊s���폜
//		auto contour_it = std::remove_if(contour_.begin(), contour_.end(), [](const std::vector<cv::Point> & p) {return cv::contourArea(p) < AREA_THRESHOLD_MIN || cv::contourArea(p) > AREA_THRESHOLD_MAX; });
//		contour_.erase(contour_it, contour_.end());
//		//if (contour_.size() != 1) return -1; 
//		//    �d�S���v�Z
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
//	//    �摜�擾
//	std::thread thrA([&] {  // frameGrayBuffer�ɎB�������摜��ۑ�����X���b�h
//
//		while (flag) {  //  �X���b�hA�ł�(�f�[�^����������)
//
//			if ((latest_buffer_idx + 1) < frameGrayBuffer.size()) {
//				cap >> temp;  // �J��������摜���擾��latest_buffer_idx + 1�̈ʒu�ɕۑ�
//							  //QueryPerformanceFrequency(&nFreq);
//							  //QueryPerformanceCounter(&nBeginTime);
//				cvtColor(temp, linshi, CV_RGB2GRAY);
//				//QueryPerformanceCounter(&nEndTime);
//				//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//				//printf("cap thread : %f us \n", time * 1000000);
//				cv::flip(linshi, result, 1);
//				frameGrayBuffer[latest_buffer_idx + 1] = result;
//				latest_buffer_idx++;  //  latest_buffer_idx++�Ƃ��ŐV�̉摜�̈ʒu���X�V���Ă��܂�
//			}
//			else {  // latest_buffer_idx++ = buf_size�̎��Alatest_buffer_idx = 0�Ƃ��Ēl���X�V
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
//				if (0 <= roipt1.x && 0 <= roipt1.y && roipt2.x <= width && roipt2.y <= height) { // ROI����ʓ��ɂ���
//					cv::Rect roi(roipt1, roipt2); //Rect�� pt1 <= x,y < pt2
//					cv::Mat grayroiimg = frameGrayBuffer[latest_buffer_idx](roi);
//					latest_proc_buffer_idx = latest_buffer_idx;
//					cv::Mat binroiimg;
//					cv::adaptiveThreshold(grayroiimg, binroiimg, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 7, 8); // Method=MEAN_C, Block=5*5, C=8
//					cv::Moments moment = cv::moments(binroiimg, true);
//					cv::Point2f roicentroid(moment.m10 / moment.m00, moment.m01 / moment.m00); // ROI���^���������ꍇ��moment�ɕςȒl������͗l
//					if (roicentroid.x >= 0 && roicentroid.y >= 0) { // �g���b�L���O����
//						centroid_arr = roipt1 + roicentroid;
//						xx = centroid_arr.x;
//						yy = centroid_arr.y;
//					}//�g���b�L���O���s���X�V���Ȃ�
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
//	//��ȡ������������
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	//std::cout << "����֧�ֵ���������Ϊ��" << nrAttributes << std::endl;
//
//	glEnable(GL_DEPTH_TEST);
//
//	//���������ǵ���ɫƁE
//	Shader shader("Shader.vs", "Shader.fs");
//
//	//��һ������
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
//	//����E
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//��������́E��͹��˵ķ��?
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
//		std::cout << "�޷��������⣬ǁE�E��E���Դ�Ƿ�����?" << std::endl;
//	stbi_image_free(data);
//
//	//����E
//	//unsigned int texture2;
//	//glGenTextures(1, &texture2);
//	//glActiveTexture(GL_TEXTURE1);	//��������E��ρE
//	//glBindTexture(GL_TEXTURE_2D, texture2);
//	////��������׷�ƺ͹��˵ķ�ʽ
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	////����ͼƬ
//	//stbi_set_flip_vertically_on_load(true);
//	//unsigned char* data2 = stbi_load("awesomeface.png", &widthgl, &heightgl, &nrChannels, 0);
//	//if (data2) {
//	//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthgl, heightgl, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//	//    glGenerateMipmap(GL_TEXTURE_2D);
//	//}
//	//else
//	//    std::cout << "�޷��������⣬ǁE�E��E���Դ�Ƿ�����?" << std::endl;
//	//stbi_image_free(data2);
//
//	//����OpenGL�ĸ������������ĸ�����ѥԪ
//	shader.use();
//	shader.setInt("texture1", 0);
//	//shader.setInt("texture2", 1);
//
//	//�任
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
//			//�ѵ����� hazard??
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
//		// ρE���E�һ��΁E�����һ������ת��Ч����ÿһ��whileѭ���ı�һ����ģ�ͣ�model���ĽǶȣ�ÿ��ѭ���ڵ�forѭ���տ�ʼʱ����ģ�ͣ�model1����ʼ������ģ�ͣ�model��
//		// ��������֮����Ը���ÿһ֡����ģ�ͣ�model��λ�úͽǶ����趨��ģ�ͣ�model1����λ�úͽǶȣ�Ҳ����˵��ģ�Ͷ���Ҫ������ģ��������λ�ã�����Ч����ģ����������ģ��ת
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
//	//float cameraSpeed = 2.5f * deltaTime; //�ƶ��ٶ�
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
//	//float xoffset = lastX - xPos;	//��́Eˣ��ڴ����У���ߵ�����E����ұߵ����꣬��������Ҫһ�����ĽǶ?
//	//float yoffset = lastY - yPos;	//ͬ�����ڴ����У����������E�����������꣬����������̧ͷ��ʱ����Ҫһ�����ĽǶ?
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
////��E�����Ϣ�ص�E
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
