#pragma once
#include "pch.h"


/*
For void Push<T>(unsigned int count), supported types are following:
	- float
	- unsigned int
	- unsigned char
*/



struct VertexBufferElement{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSize(unsigned int type){
		switch(type){
			case GL_FLOAT: return 4;
			case GL_INT: return 4;
			case GL_UNSIGNED_BYTE: return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout{
private:
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_stride;
public:
	VertexBufferLayout() : m_stride(0){}

	template<typename T>
	void Push(unsigned int count){
		std::runtime_error(false);
	}
	
	template<>
	void Push<float>(unsigned int count){
		m_elements.push_back(VertexBufferElement{GL_FLOAT, count, GL_FALSE});
		m_stride += count * VertexBufferElement::GetSize(GL_FLOAT);
	}
	template<>
	void Push<unsigned int>(unsigned int count){
		m_elements.push_back(VertexBufferElement{GL_UNSIGNED_INT, count, GL_FALSE});
		m_stride += count * VertexBufferElement::GetSize(GL_UNSIGNED_INT);
	}
	template<>
	void Push<unsigned char>(unsigned int count){
		m_elements.push_back(VertexBufferElement{GL_UNSIGNED_BYTE, count, GL_TRUE});
		m_stride += count * VertexBufferElement::GetSize(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement>& GetElements() const {return m_elements;}
	inline unsigned int GetStride() const {return m_stride;}
};