#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(){ m_rendererID=0; m_count=0; }
IndexBuffer::IndexBuffer(const unsigned int* data,unsigned int count) : m_count(count){
	glCall(glGenBuffers(1, &m_rendererID));
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int),data,GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer(){
	Unbind();
	glCall(glDeleteBuffers(1, &m_rendererID));
}
void IndexBuffer::Bind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}
void IndexBuffer::Unbind() const {
	glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount() const {
	return m_count;
}