#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>	//ÒªÓÃµ½OpenGLµÄº¯Êı¾ÍÒª°E¬Õâ¸öÍ·ÎÄ¼ş

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader {
public:
	//³ÌĞòID
	unsigned int ID;

	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	//Ê¹ÓÃ×ÅÉ«ÆE
	void use();
	//ÉèÖÃuniform±äÁ¿
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, float value[]) const;
};

#endif