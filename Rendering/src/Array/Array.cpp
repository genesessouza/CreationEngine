#include "Engine/Rendering/Array/Array.h"

#include "Engine/Platform/OpenGL/OpenGLArray.h"

namespace Engine::Rendering::Array
{
	VertexArray* VertexArray::Create()
	{
		return new Engine::Platform::OpenGL::OpenGLVertexArray();
	}
}