#pragma once
#include "GL/freeglut.h"
#include <iostream>
#include <vector>

class SO_BaseClass;

struct Vector2
{
	float x, y;

	Vector2(float xInput, float yInput)
	{
		x = xInput;
		y = yInput;
	}
	Vector2()
	{
		x = 0;
		y = 0;
	}
};
struct Vector3
{
	float x, y, z;
	Vector3(float xInput, float yInput, float zInput)
	{
		x = xInput;
		y = yInput;
		z = zInput;
	}
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};
//struct Camera
//{
//	Vector3 camPosition, centerView, camUpVec;
//};
struct Color
{
	GLfloat r, g, b;
};
struct Vertex
{
	GLfloat x, y, z;
};
struct TexCoord 
{
	GLfloat U;
	GLfloat V;
};

struct Mesh
{
	Vertex* Vertices;
	Vector3* Normals;
	TexCoord* TexCoords;
	GLushort* VertexIndices;
	GLushort* NormalsIndices;
	GLushort* TexCoordsIndices;

	std::vector<Vertex*> VertexVector;
	std::vector<Vector3*> NormalVector;
	std::vector<TexCoord*> TexCoordsVector;
	std::vector<GLushort*> VertexIndicesVector;
	std::vector<GLushort*> NormalIndicesVector;
	std::vector<GLushort*> TexCoordsIndicesVector;

	int VertexCount, NormalCount, VertexIndexCount, TexCoordCount;
};

struct Vector4 
{
	float x, y, z, w;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};

