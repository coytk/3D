#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>	//Ҫ�õ�OpenGL�ĺ�����Ҫ��E����ͷ�ļ�

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader {
public:
	//����ID
	unsigned int ID;

	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	//ʹ����ɫƁE
	void use();
	//����uniform����
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, float value[]) const;
};

#endif