#include "Shader.h"



/// Shader class

Shader::Shader() : m_filePath("Engine/Assets/Shaders/Basic.shader"){
	ShaderSource source = ParseShader();
	m_rendererID = CreateShader(source.vertexSource, source.fragmentSource);
	Bind();
}
Shader::Shader(const std::string& filePath) : m_filePath(filePath){
	ShaderSource source = ParseShader();
	m_rendererID = CreateShader(source.vertexSource, source.fragmentSource);
	Bind();
}
Shader::~Shader(){
	glCall(glDeleteProgram(m_rendererID));
}
void Shader::Bind() const{
	glCall(glUseProgram(m_rendererID));
}
void Shader::Unbind() const{
	glCall(glUseProgram(0));
}

/// Compilation

ShaderSource Shader::ParseShader(){
	std::ifstream stream(m_filePath);
	std::string line;
	std::stringstream ss[2];
	enum ShaderType{
		NONE = 0, VERTEX = 0, FRAGMENT = 1
	};
	ShaderType type = ShaderType::NONE;
	while(getline(stream, line)){
		if(line.find("#shader") != std::string::npos){
			if(line.find("vertex") != std::string::npos){
				type = ShaderType::VERTEX;
			}
			else if(line.find("fragment") != std::string::npos){
				type = ShaderType::FRAGMENT;
			}
		}
		else{
			ss[(int)type] << line << '\n';
		}
	}
	return {ss[0].str(), ss[1].str()};
}
unsigned int Shader::CompileShader(unsigned int type, const std::string& source){
	glCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	glCall(glShaderSource(id, 1, &src, nullptr));
	glCall(glCompileShader(id));

	int result;
	glCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if(result == GL_FALSE){
		int length;
		glCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* msg = (char*)alloca(length * sizeof(char));
		glCall(glGetShaderInfoLog(id, length, &length, msg));
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!\n    " << msg << '\n';
		glCall(glDeleteShader(id));
		return 0;
	}

	return id;
}
unsigned int Shader::CreateShader(const std::string & vertexShader, const std::string & fragmentShader){
	glCall(unsigned int program = glCreateProgram());
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glCall(glAttachShader(program, vs));
	glCall(glAttachShader(program, fs));
	glCall(glLinkProgram(program));
	glCall(glValidateProgram(program));

	glCall(glDeleteShader(vs));
	glCall(glDeleteShader(fs));

	return program;
}


/// Uniforms

void Shader::SetUniform4f(const std::string& name, const Vector4& v){
	glCall(glUniform4f(GetUniformLocation(name), v.x, v.y, v.z, v.w));
}

unsigned int Shader::GetUniformLocation(const std::string& name){
	if(m_uniformLocationCache.find(name) != m_uniformLocationCache.end()){
		return m_uniformLocationCache[name];
	}

	glCall(int location = glGetUniformLocation(m_rendererID, name.c_str()));
	if(location == -1){
		std::cout << "[WARNING] Uniform '" << name << "' doesn't exist!\n";
	}
	m_uniformLocationCache[name] = location;
	return location;
}