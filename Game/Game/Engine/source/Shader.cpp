#include "Shader.h"


static ShaderSource ParseShader(const string & filePath){
	ifstream stream(filePath);
	string line;
	stringstream ss[2];
	enum ShaderType{
		NONE = 0, VERTEX = 0, FRAGMENT = 1
	};
	ShaderType type = ShaderType::NONE;
	while(getline(stream, line)){
		if(line.find("#shader") != string::npos){
			if(line.find("vertex") != string::npos){
				type = ShaderType::VERTEX;
			}
			else if(line.find("fragment") != string::npos){
				type = ShaderType::FRAGMENT;
			}
		}
		else{
			ss[(int)type] << line << '\n';
		}
	}
	return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const string& source){
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE){
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, msg);
		cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " shader!\n    " << msg << '\n';
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int CreateShader(const string & vertexShader, const string & fragmentShader){
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}


Shader::Shader(const string& filePath){
	ShaderSource source = ParseShader(filePath);
	//cout << "VERTEX:\n" << source.vertexSource << "\n\n\nFRAGMENT:\n" << source.fragmentSource << "\n\n\n";
	shader = CreateShader(source.vertexSource, source.fragmentSource);
	Bind();
}
Shader::Shader(const string& vertexShader, const string& fragmentShader){
	shader = CreateShader(vertexShader, fragmentShader);
	Bind();
}
Shader::~Shader(){
	glDeleteProgram(shader);
	cout << "Deleted shader!\n";
}
void Shader::Bind(){
	glUseProgram(shader);
}