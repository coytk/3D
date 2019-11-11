#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <WinSock2.h>
#include <opencv2/opencv.hpp>
#include <thread>
#include <stdio.h>
#include <windows.h>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/opencv.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include<math.h>

#include <iostream>

#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xPos, double yPos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// ﾉ靹ﾃ
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 500;

float factor = 0.2f;
double fov = 45.0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	double time1;
float vertices[] = {
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
};

glm::vec3 cubePositions[] = {//(右左，上下，前后)+-
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(-5.0f, -5.0f, -5.0f),
	glm::vec3(-3.5f, 5.5f, 2.5f),
	glm::vec3(-3.5f, -2.0f, 3.0f),
	glm::vec3(-7.5f, 3.0f, -6.5f),
	glm::vec3(10.0f, 3.0f, 7.5f),
	glm::vec3(7.0f, -5.0f, 2.5f),
	glm::vec3(5.5f, 2.0f, -2.5f),
	glm::vec3(6.5f, -4.0f, -5.5f),
	glm::vec3(11.0f, -2.0f, -3.5f)
};

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;  //ﾁｽﾖ｡ﾖｮｼ莊ﾄｼ荳ｱｼ・
float lastFrame = 0.0f;  //ﾉﾏﾒｻﾖ｡ｻ贍ﾆｵﾄﾊｱｼ・

float lastX = 400, lastY = 300;
bool firstMouse = true;
float yaw = 0.0f, pitch = 0.0f;

int main() {
	

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//std::cout << "Let's start!" << std::endl;
	//system("pause");
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//ｻ｡ﾗ鋗ﾔﾊﾁｿ
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "ﾗ鋗ｧｳﾖｵﾄﾊﾔﾊﾁｿﾎｪ｣ｺ" << nrAttributes << std::endl;

	glEnable(GL_DEPTH_TEST);

	//｣｡ｴｴｽｨﾎﾒﾃﾇｵﾄﾗﾅﾉｫﾆ・
	Shader shader("Shader.vs", "Shader.fs");

	//ｵﾚﾒｻｸｷｾｳ
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//void *data = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//unsigned int EBO;
	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//ﾎﾆﾀ・
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	//ﾉ靹ﾃﾎﾆﾀ擎・ｰｺﾍｹﾂﾋｵﾄｷｽﾊ?
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(/*"zhou_yu.bmp"*/"123.png", &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "ﾎﾞｷｨｼﾓﾔﾘﾎﾊﾌ筌ｬﾇ・・魘惲・ﾊﾔｴﾊﾇｷﾐﾎ?" << std::endl;
	stbi_image_free(data);

	//ﾎﾆﾀ・
	//unsigned int texture2;
	//glGenTextures(1, &texture2);
	//glActiveTexture(GL_TEXTURE1);	//ｼ､ｻ﨩ﾆﾀ・ｶﾔﾏ・
	//glBindTexture(GL_TEXTURE_2D, texture2);
	////ﾉ靹ﾃﾎﾆﾀ晙ｷﾈﾆｺﾍｹﾂﾋｵﾄｷｽﾊｽ
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	////ｼﾓﾔﾘﾍｼﾆｬ
	//stbi_set_flip_vertically_on_load(true);
	//unsigned char* data2 = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
	//if (data2) {
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//else
	//	std::cout << "ﾎﾞｷｨｼﾓﾔﾘﾎﾊﾌ筌ｬﾇ・・魘惲・ﾊﾔｴﾊﾇｷﾐﾎ?" << std::endl;
	//stbi_image_free(data2);

	//ｸ賤ﾟOpenGLﾄﾄｸﾉﾑﾚﾄﾄｸﾆﾀ昉･ﾔｪ
	shader.use();
	shader.setInt("texture1", 0);
	//shader.setInt("texture2", 1);

	//ｱ莉ｻ
	//glm::mat4 trans;
	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 modelseq[100];
	for (int i = 0; i < 10; ++i) {
		modelseq[i] = glm::translate(modelseq[i], cubePositions[i]);
		float angle = 20.0f * i;
		modelseq[i] = glm::rotate(modelseq[i], glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	}

	cv::Mat model2DImg(500, 500, CV_8UC3);

	GLuint pboID;
	glGenBuffers(1, &pboID);

	while (!glfwWindowShouldClose(window)) {
		//Sleep(16);

		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);
		glm::mat4 model;
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, texture2);

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		shader.use();
		glm::mat4 projection;
		projection = glm::perspective(glm::radians((float)fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		//float radius = 10.0f;
		//float camX = sin(glfwGetTime()) * radius;
		//float camZ = cos(glfwGetTime()) * radius;
		glm::mat4 view;
		//view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		shader.setMat4("view", glm::value_ptr(view));
		shader.setMat4("projection", glm::value_ptr(projection));

		glBindVertexArray(VAO);
		// ﾏ・ｪｴ・ｽﾒｻｶﾑﾎ・衒ﾆﾗﾅﾒｻｸｫﾎｪｵﾄﾐｧｹ訒ｺﾃｿﾒｻｴﾎwhileﾑｭｻｷｸﾄｱ萪ｻｴﾎﾖ｣ﾐﾍ｣ｨmodel｣ｩｵﾄｽﾇｶﾈ｣ｬﾃｿｴﾎﾑｭｻｷﾄﾚｵﾄforﾑｭｻｷｸﾕｿｪﾊｼﾊｱｽｫｸｱﾄ｣ﾐﾍ｣ｨmodel1｣ｩｳｼｻｯｳﾉﾖ｣ﾐﾍ｣ｨmodel｣ｩ
		// ﾕ簷ﾙﾗｮｺﾉﾒﾔｸﾝﾃｿﾒｻﾖ｡ｵﾄﾖ｣ﾐﾍ｣ｨmodel｣ｩﾎｻﾖﾃｺﾍｽﾇｶﾈﾀｴﾉ雜ｨｸｱﾄ｣ﾐﾍ｣ｨmodel1｣ｩｵﾄﾎｻﾖﾃｺﾍｽﾇｶﾈ｣ｬﾒｲｾﾍﾊﾇﾋｵｸｱﾄ｣ﾐﾍｶｼﾐ靨ｪｸﾝﾖ｣ﾐﾍﾀｴｾｨﾎｻﾖﾃ｣ｬﾗ靑ﾕﾐｧｹ鄕ｱﾄ｣ﾐﾍﾊﾇﾈﾆﾗﾅﾖ｣ﾐﾍﾗｪ
		//glm::mat4 model1;
		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		//for (int i = 0; i < 10; ++i) {
		//	model1 = model;
		//	model1 = glm::translate(model1, cubePositions[i]);
		//	float angle = 20.0f * i;
		//	model1 = glm::rotate(model1, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		//	shader.setMat4("model", glm::value_ptr(model1));
		//	glDrawArrays(GL_TRIANGLES, 0, 36);
		//}


		for (int i = 0; i < 10; ++i) {
			model = modelseq[i];
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(30.0f), glm::vec3(0.5f, 1.0f, 0.0f));
			shader.setMat4("model", glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

		CvSize size = cvSize(500, 500);
		cv::Mat projImgGray(500, 500, CV_8UC1);
		cv::Mat projImgGrayop(500, 500, CV_8UC1);
		//cv::Mat img(300, 400, CV_8UC3);
		//glReadPixels(0, 0, img.cols, img.rows, GL_RGB, GL_UNSIGNED_BYTE, img.data);
		//cv::imshow("img", img);
		//GLint viewPort[4] = { 0 };
		//glGetIntegerv(GL_VIEWPORT, viewPort); // 10000~11000 us

		//GLubyte* buffer = (GLubyte*)malloc(viewPort[2] * viewPort[3] * sizeof(GLubyte) * 3);
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&nBeginTime);

		glReadPixels(0, 0, 500, 500, GL_BGR, GL_UNSIGNED_BYTE, model2DImg.data); // 3000us

		//cv::imshow("cvtest1", model2DImg);

		//void *buffer = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
		//void *buffer = glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
		//glReadBuffer(GL_FRONT);
		////glBindBuffer(GL_PIXEL_PACK_BUFFER, pboID);
		//glReadPixels(0, 0, 800, 800, GL_BGR, GL_UNSIGNED_BYTE, buffer);

		//IplImage* model2DImg = cvCreateImage(size, IPL_DEPTH_8U, 3);
		 //cvFlip(model2DImg, NULL, 0);
		 //return model2DImg;
		//memcpy(model2DImg.data, buffer, size.width * size.height * (size_t)3);

		//glReadBuffer(GL_FRONT);
		//glBindBuffer(GL_PIXEL_PACK_BUFFER, pboID);
		//glReadPixels(0, 0, 500, 500, GL_BGR, GL_UNSIGNED_BYTE, 0);
		//void *ptr = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
		//memcpy(model2DImg.data, ptr, 500 * 500 * 3);
		

		cv::cvtColor(model2DImg, projImgGray, CV_BGR2GRAY);
		cv::flip(projImgGray, projImgGrayop, 0);
		//delete[] buffer;
		cv::imshow("cvtest", projImgGrayop);
		//cv::Mat testcv(300, 400, CV_8UC3);
		//void *ptr = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
		////void *ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
		//std::memcpy(testcv.data, ptr, 400 * 300);
		//cv::imshow("img", testcv);

		QueryPerformanceCounter(&nEndTime);
		time1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		printf("Latency : %f us \n", time1 * 1000000);

	}

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
	//	factor += 0.01f;
	//	if (factor > 1.0f)
	//		factor = 1.0f;
	//}

	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
	//	factor -= 0.01f;
	//	if (factor < 0.0f)
	//		factor = 0.0f;
	//}


	float cameraSpeed = 2.5f * deltaTime; //ﾒﾆｶｯﾋﾙｶﾈ
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraUp;

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraUp;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::cross(cameraFront, cameraUp) * cameraSpeed;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::cross(cameraFront, cameraUp) * cameraSpeed;

	//std::cout << cameraPos.b << std::endl;
	//std::cout << cameraPos.g << std::endl;
	//std::cout << cameraPos.p << std::endl;

	//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	//	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);

	//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	//	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);

}

void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
	//static int x = 0;

	//x++;
	//if (x == 10) {
	//	int y = 0;
	//}
	if (firstMouse) {
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	float xoffset = lastX - xPos;	//ｱ・ﾋ｣ｬﾔﾚｴｰｿﾚﾖﾐ｣ｬﾗﾟｵﾄﾗ・｡ﾓﾚﾓﾒｱﾟｵﾄﾗ凜ｬｶﾒﾃﾇﾐ靨ｪﾒｻｸｵﾄｽﾇｶ?
	float yoffset = lastY - yPos;	//ﾍｬﾑｬﾔﾚｴｰｿﾚﾖﾐ｣ｬﾏﾂﾃ豬ﾄﾗ・ﾚﾉﾏﾃ豬ﾄﾗ凜ｬｶﾒﾃﾇﾍﾏﾌｧﾍｷｵﾄﾊｱｺ靨ｪﾒｻｸｵﾄｽﾇｶ?
	lastX = xPos;
	lastY = yPos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = -sin(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = -cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	cameraFront = glm::normalize(front);
}

//ﾊ・ﾖﾏ鋧｢ｻﾘｵ・
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	if (fov >= 1.0 && fov <= 45.0)
		fov -= yoffset;
	if (fov <= 1.0)
		fov = 1.0;
	if (fov >= 45.0)
		fov = 45.0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
