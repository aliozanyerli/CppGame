#pragma once
#include "pch.h"
#define ASSERT(x) if(!(x)) __debugbreak();
#define glCall(x) ClearError(); x; ASSERT(LogCall(#x, __FILE__, __LINE__))




static void ClearError(){
	while(glGetError());
}

static bool LogCall(const char* function, const char* file, int line){
	std::ofstream logger("../Logs/log.txt");
	while(GLenum error = glGetError()){
		std::cout << "[OpenGL error](" << error << ")   " << function << "\n    in  " << file << "    on line  " << line << '\n';
		logger << "[OpenGL error](" << error << ")   " << function << "\n    in  " << file << "    on line  " << line << '\n';
		return 0;
	}
	logger.close();
	return 1;
}