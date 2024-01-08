#include "VertexArray.h"



VertexArray::VertexArray(){
    glCall(glGenVertexArrays(1,&m_rendererID));
    glCall(glBindVertexArray(m_rendererID));
}
VertexArray::~VertexArray(){
	glCall(glDeleteVertexArrays(1, &m_rendererID));
}
void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for(int i = 0; i < elements.size(); ++i){
		const auto& element = elements[i];
		glCall(glEnableVertexAttribArray(i));
		glCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSize(element.type);
	}
}

void VertexArray::Bind() const{
    glCall(glBindVertexArray(m_rendererID));
}
void VertexArray::Unbind() const{
    glCall(glBindVertexArray(0));
}