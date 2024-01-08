#pragma once
#include "pch.h"

class VertexBuffer{
private:
	unsigned int m_rendererID;
public:
	VertexBuffer();
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const ;
	void Unbind() const ;
};