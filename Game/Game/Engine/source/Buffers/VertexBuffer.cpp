#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(){ m_rendererID=0; }
VertexBuffer::VertexBuffer(const void* data,unsigned int size){
	glCall(glGenBuffers(1, &m_rendererID));
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
	glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}
VertexBuffer::~VertexBuffer(){
	Unbind();
	glCall(glDeleteBuffers(1, &m_rendererID));
}
void VertexBuffer::Bind() const {
	glCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}
void VertexBuffer::Unbind() const {
	glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}