#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

#include <windows.h>
#include <iostream>
#include <fstream>

#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);
	int LoadTextureTGA(const char* textureFileName);

	inline GLuint GetID() const { return m_ID; }
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

private:
	GLuint m_ID; // Texture ID
	int m_Width, m_Height;
};


#endif // !_TEXTURE2D_H

