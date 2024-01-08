#pragma once
#include "pch.h"

class IndexBuffer{
private:
	unsigned int m_rendererID;
	unsigned int m_count;
public:
	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const ;
	void Unbind() const ;

	unsigned int GetCount() const;
};