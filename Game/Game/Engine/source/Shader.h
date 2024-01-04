#include "pch.h"
using namespace std;

static unsigned int CompileShader(unsigned int type, const string& source);

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader);


class Shader{
public:
	unsigned int shader=0;

	Shader(const string& vertexShader, const string& fragmentShader);
	void Bind();
};