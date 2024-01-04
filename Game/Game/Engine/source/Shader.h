#include "pch.h"
using namespace std;


struct ShaderSource{
	string vertexSource, fragmentSource;
};


static ShaderSource ParseShader(const string& filePath);

static unsigned int CompileShader(unsigned int type, const string& source);

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader);


class Shader{
public:
	unsigned int shader=0;

	Shader(const string& filePath);
	Shader(const string& vertexShader, const string& fragmentShader);
	~Shader();
	void Bind();
};