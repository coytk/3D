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
//#include <dlib/image_processing/frontal_face_detector.h>
//#include <dlib/image_processing/render_face_detections.h>
//#include <dlib/image_processing.h>
//#include <dlib/gui_widgets.h>
//#include <dlib/image_io.h>
//#include <dlib/opencv.h>
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include<math.h>
//
//using namespace dlib;
//
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
//const unsigned int SCR_WIDTH = 1920;
//const unsigned int SCR_HEIGHT = 1080;
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
//static cv::Rect dlibRectangleToOpenCV(dlib::rectangle rect, int width, int height)
//{
//	/*
//		int l = rect.left() - 15;
//		int t = rect.top() - 15;
//		int r = rect.right() + 15;
//		int b = rect.left() + 15;
//
//		if (l < 0){
//			l = 0;
//		}
//		if (t < 0){
//			t = 0;
//		}
//		if (r > width){
//			r = width;
//		}
//		if (b > height){
//			b = height;
//		}
//		*/
//		//return cv::Rect(cv::Point2i(l, t), cv::Point2i(r, b));
//	return cv::Rect(cv::Point2i(rect.left() - 15, rect.top() - 15), cv::Point2i(rect.right() + 15, rect.bottom() + 15));
//}
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
//	bool flag = true;
//	auto temp = (cv::Mat(height, width, CV_8UC1, cv::Scalar::all(255)));
//	int k;
//	cv::VideoCapture cap(0);
//	if (!cap.isOpened())
//		exit(1);
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
//
//		// This example takes in a shape model file and then a list of images to
//		// process.  We will take these filenames in as command line arguments.
//		// Dlib comes with example images in the examples/faces folder so give
//		// those as arguments to this program.
//		//if (argc == 1)
//		//{
//		//	cout << "Call this program like this:" << endl;
//		//	cout << "./face_landmark_detection_ex shape_predictor_68_face_landmarks.dat faces/*.jpg" << endl;
//		//	cout << "\nYou can get the shape_predictor_68_face_landmarks.dat file from:\n";
//		//	cout << "http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
//		//	return 0;
//		//}
//
//		// We need a face detector.  We will use this to get bounding boxes for
//		// each face in an image.
//		//QueryPerformanceFrequency(&nFreq);
//		//QueryPerformanceCounter(&nBeginTime);
//
//		frontal_face_detector detector = get_frontal_face_detector();
//
//		//QueryPerformanceCounter(&nEndTime);
//		//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		//printf("Latency : %f us \n", time * 1000000);
//
//		// And we also need a shape_predictor.  This is the tool dlib.get will predict face
//		// landmark positions given an image and face bounding box.  Here we are just
//		// loading the model from the shape_predictor_68_face_landmarks.dat file you gave
//		// as a command line argument.
//		shape_predictor sp;
//		string shape_model = "D:/shape_predictor_68_face_landmarks.dat";
//		//deserialize(argv[1]) >> sp;
//		//cout << argv[1] << endl;
//		deserialize(shape_model) >> sp;
//
//
//		//double fps = capture.get(CV_CAP_PROP_FPS);
//		//struct timeval t1, t2;//123
//		image_window win, win_faces;
//		//cv::Mat framegray(480, 640, CV_8UC1);
//		// Loop over all the images provided on the command line.
//		std::thread thrA([&] {
//			while (flag)
//			{
//				cv::Mat result;
//				cv::Mat frame;
//				cap >> frame;
//
//				//cv::flip(frame, result, 1);
//				//cv::cvtColor(frame, framegray, CV_RGB2GRAY);
//
//				array2d<rgb_pixel> img;
//				assign_image(img, cv_image<bgr_pixel>(frame));
//				// Make the image larger so we can detect small faces.
//				//pyramid_up(img);
//
//				//gettimeofday(&t1, NULL);
//				// Now tell the face detector to give us a list of bounding boxes
//				//// around all the faces in the image.
//				QueryPerformanceFrequency(&nFreq);
//				QueryPerformanceCounter(&nBeginTime);
//
//				std::vector<rectangle> dets = detector(img); 
//
//				QueryPerformanceCounter(&nEndTime);
//				time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//				printf("Latency : %f us \n", time * 1000000);
//
//				//cout << "Number of faces detected: " << dets.size() << endl;
//
//				//gettimeofday(&t1, NULL);//123
//				// Now we will go ask the shape_predictor to tell us the pose of
//				// each face we detected.
//				std::vector<full_object_detection> shapes;
//
//				//QueryPerformanceFrequency(&nFreq);
//				//QueryPerformanceCounter(&nBeginTime);
//
//				for (unsigned long j = 0; j < dets.size(); ++j)
//				{
//
//					full_object_detection shape = sp(img, dets[j]);
//
//					//cout << "number of parts: " << shape.num_parts() << endl;
//					//cout << "pixel position of first part:  " << (shape.part(0))(0) << endl;// nose
//					//cout << "pixel position of second part: " << (shape.part(0))(1) << endl;// nose
//					eyedis = shape.part(45)(0) - shape.part(36)(0);
//					//centroid_arr.y = ((shape.part(36))(1) + (shape.part(45))(1)) / 2;
//					centroid_arr.x = (shape.part(27))(0);
//					centroid_arr.y = (shape.part(27))(1);
//
//					xx = centroid_arr.x;
//					yy = centroid_arr.y;
//
//					// You get the idea, you can get all the face part locations if
//					// you want them.  Here we just store them in shapes so we can
//					// put them on the screen.
//					shapes.push_back(shape);
//				}
//
//				//QueryPerformanceCounter(&nEndTime);
//				//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//				//printf("Latency : %f us \n", time * 1000000);
//				//gettimeofday(&t2, NULL);// 123
//
//				//cv::Mat result = dlib::toMat(img);
//				// Now let's view our face poses on the screen.
//				//cv::imshow("result", result);
//				//cv::waitKey(10);
//
//				win.clear_overlay();
//				win.set_image(img);
//				win.add_overlay(render_face_detections(shapes));
//
//				// We can also extract copies of each face that are cropped, rotated upright,
//				// and scaled to a standard size as shown here:
//				/*
//				dlib::array<array2d<rgb_pixel> > face_chips;
//				extract_image_chips(img, get_face_chip_details(shapes), face_chips);
//				win_faces.set_image(tile_images(face_chips));
//				*/
//				//cout << "Hit enter to process the next image..." << endl;
//				//cin.get();
//
//				//double us = get_elapsed_time(&t1, &t2);
//				//printf("processing time = %.5f (ms)\n", us/1000.0);
//
//			}
//		});
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
//	unsigned int texture2;
//	glGenTextures(1, &texture2);
//	glActiveTexture(GL_TEXTURE1);	//激畸昶纴E对蟻E
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	//设置纹历追绕和过滤的方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//加载图片
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data2 = stbi_load("awesomeface.png", &widthgl, &heightgl, &nrChannels, 0);
//	if (data2) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthgl, heightgl, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "无法加载问题，莵E丒榇丒蜃试词欠裼形蟆?" << std::endl;
//	stbi_image_free(data2);
//
//	//告诉OpenGL哪个采样器属于哪个纹历靴元
//	shader.use();
//	shader.setInt("texture1", 0);
//	shader.setInt("texture2", 1);
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
//	std::thread thrB([&] {
//		while (flag)
//		{
//			//难道又是 hazard??
//			//xx = centroid_arr.x;
//			//yy = centroid_arr.y;
//			screendepth = 490.31*pow(eyedis, -0.98);
//
//			rowang = abs(atan(((320 - xx) * 1 / 100 + screenwidth / 2) / screendepth) + atan((screenwidth / 2 - (320 - xx) * 1 / 100) / screendepth));
//			//cout << glm::degrees(rowang) << endl;
//			colang = abs(atan(((240 - yy) * 1 / 100 + screenheight / 2) / screendepth) + atan((screenheight / 2 - (240 - yy) * 1 / 100) / screendepth));
//			//cout << glm::degrees(colang) << endl;
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
//	while (!glfwWindowShouldClose(window)) {
//		//QueryPerformanceFrequency(&nFreq);
//		//QueryPerformanceCounter(&nBeginTime);
//		
//		//sleep(50);
//		//cv::waitKey(50);
//		glm::mat4 model;
//		processInput(window);
//		
//		//std::cout << centroid_arr << std::endl;
//
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
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
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
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(25.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//			shader.setMat4("model", glm::value_ptr(model));
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//		//QueryPerformanceCounter(&nEndTime);
//		//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		//printf("Latency : %f us \n", time * 1000000);
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
//
//
//
//
//	//float cameraSpeed = 2.5f * deltaTime; //移动速度
//	//if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	//	cameraPos += cameraSpeed * cameraFront;
//
//	//if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	//	cameraPos -= cameraSpeed * cameraFront;
//
//	cameraPos = glm::vec3((320 - xx) * 1 / 100, (240 - yy) * 1 / 100, screendepth);
//	/*
//	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
//		cameraPos += cameraSpeed * cameraUp;
//
//	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
//		cameraPos -= cameraSpeed * cameraUp;
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		cameraPos += glm::cross(cameraFront, cameraUp) * cameraSpeed;
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		cameraPos -= glm::cross(cameraFront, cameraUp) * cameraSpeed;
//		*/
//
//		//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		//	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
//
//		//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		//	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
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
