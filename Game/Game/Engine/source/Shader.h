#pragma once
#include "pch.h"
#include <unordered_map>

#include "MyMath.h"


struct ShaderSource{
	std::string vertexSource, fragmentSource;
};


class Shader{
private:
	std::string m_filePath = "Engine/Assets/Shaders/Basic.shader";
	unsigned int m_rendererID;
	std::unordered_map<std::string, int> m_uniformLocationCache;
public:
	Shader();
	Shader(const std::string& filePath);
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();

	void Bind() const;
	void Unbind() const;
	
	ShaderSource ParseShader();
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string & vertexShader, const std::string & fragmentShader);

	void SetUniform4f(const std::string& name, const Vector4& v);
	unsigned int GetUniformLocation(const std::string& name);
};