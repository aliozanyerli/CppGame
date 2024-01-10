#pragma once
#include "pch.h"
//#include "ErrorHandling.h"


struct ShaderSource{
	std::string vertexSource, fragmentSource;
};


static ShaderSource ParseShader(const std::string& filePath);

static unsigned int CompileShader(unsigned int type, const std::string& source);

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);


class Shader{
public:
	unsigned int shader=0;

	Shader(const std::string& filePath);
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();
	void Bind();
};