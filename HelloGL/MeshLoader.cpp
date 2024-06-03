#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	//void LoadVertices(ifstream& inFile, Mesh& mesh);
	//void LoadNormals(ifstream& inFile, Mesh& mesh);
	//void LoadTexCoords(ifstream& inFile, TexturedMesh& mesh);
	//void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVerticesOBJ(Mesh& mesh);
	void LoadTexCoordsOBJ(Mesh& mesh);
	void LoadNormalsOBJ(Mesh& mesh);
	void LoadIndicesOBJNew(Mesh& mesh);
	void LoadIndicesOBJ(Mesh& mesh);

	//void LoadVertices(ifstream& inFile, Mesh& mesh)
	//{
	//	inFile >> mesh.VertexCount;

	//	if (mesh.VertexCount > 0)
	//	{
	//		mesh.Vertices = new Vertex[mesh.VertexCount];

	//		for (int i = 0; i < mesh.VertexCount; i++)
	//		{
	//			inFile >> mesh.Vertices[i].x;
	//			inFile >> mesh.Vertices[i].y;
	//			inFile >> mesh.Vertices[i].z;
	//		}
	//	}
	//}

	//void LoadNormals(ifstream& inFile, Mesh& mesh)
	//{
	//	//TODO: LOAD COLOURS
	//	inFile >> mesh.NormalCount;
	//	mesh.Normals = new Vector3[mesh.NormalCount];
	//	for (int i = 0; i < mesh.NormalCount; i++)

	//	{
	//		inFile >> mesh.Normals[i].x;
	//		inFile >> mesh.Normals[i].y;
	//		inFile >> mesh.Normals[i].z;
	//	}
	//}

	//void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	//{
	//	//TODO: Load TexCoords
	//	inFile >> mesh.Mesh->TexCoordCount;
	//	mesh.Mesh->TexCoords = new TexCoord[mesh.Mesh->TexCoordCount];
	//	for (int i = 0; i < mesh.Mesh->TexCoordCount; i++)
	//	{
	//		inFile >> mesh.Mesh->TexCoords[i].U;
	//		inFile >> mesh.Mesh->TexCoords[i].V;
	//	}
	//}
	//void LoadIndices(ifstream& inFile, Mesh& mesh)
	//{
	//	//TODO: Load Indices
	//	inFile >> mesh.VertexIndexCount;
	//	mesh.VertexIndices = new GLushort[mesh.VertexIndexCount];
	//	for (int i = 0; i < mesh.VertexIndexCount; i++)
	//	{
	//		inFile >> mesh.VertexIndices[i];
	//	}
	//}

	void LoadIndicesOBJNew(Mesh& mesh)
	{
		mesh.VertexIndices = new GLushort[mesh.VertexIndexCount];
		mesh.TexCoordsIndices = new GLushort[mesh.VertexIndexCount];
		mesh.NormalsIndices = new GLushort[mesh.VertexIndexCount];

		for (int i = 0; i < mesh.VertexIndexCount; i++)
		{
			mesh.VertexIndices[i] = *mesh.VertexIndicesVector[i];
		}
		for (int i = 0; i < mesh.VertexIndexCount; i++)
		{
			mesh.TexCoordsIndices[i] = *mesh.TexCoordsIndicesVector[i];
		}
		for (int i = 0; i < mesh.VertexIndexCount; i++)
		{
			mesh.NormalsIndices[i] = *mesh.NormalIndicesVector[i];
		}
	}
	void LoadIndicesOBJ(Mesh& mesh)
	{
		mesh.VertexIndices = new GLushort[mesh.VertexIndexCount];
		for (int i = 0; i < mesh.VertexIndexCount; i++)
		{
			mesh.VertexIndices[i] = *mesh.VertexIndicesVector[i];
		}

	}

	void LoadVerticesOBJ(Mesh& mesh)
	{
		mesh.Vertices = new Vertex[mesh.VertexCount];
		for (int i = 0; i < mesh.VertexCount; i++)
		{
			mesh.Vertices[i] = *mesh.VertexVector[i];
		}
	}

	void LoadTexCoordsOBJ(Mesh& mesh)
	{
		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];
		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			mesh.TexCoords[i] = *mesh.TexCoordsVector[i];
		}
	}

	void LoadNormalsOBJ(Mesh& mesh)
	{
		mesh.Normals = new Vector3[mesh.NormalCount];
		for (int i = 0; i < mesh.NormalCount; i++)
		{
			mesh.Normals[i] = *mesh.NormalVector[i];
		}
	}

	//Mesh* MeshLoader::Load(char* path)
	//{
	//	Mesh* mesh = new Mesh();

	//	ifstream inFile;

	//	inFile.open(path);

	//	if (!inFile.good())  
	//	{
	//		cerr  << "Can't open texture file " << path << endl;
	//		return nullptr;
	//	}

	//	//LOAD DATA USING METHODS ABOVE
	//	LoadVertices(inFile , *mesh);
	//	LoadNormals(inFile , *mesh);
	//	LoadIndices(inFile, *mesh);


	//	return mesh;
	//}

	//TexturedMesh* MeshLoader::LoadTextured(char* path)
	//{
	//	TexturedMesh* mesh = new TexturedMesh();
	//	mesh->Mesh = new Mesh();

	//	//LOAD FILE AND DATA
	//	ifstream inFile;

	//	inFile.open(path);

	//	if (!inFile.good())
	//	{
	//		cerr << "Can't open texture file " << path << endl;
	//		return nullptr;
	//	}

	//	//LOAD DATA USING METHODS ABOVE
	//	LoadVertices(inFile, *mesh->Mesh);
	//	LoadTexCoords(inFile, *mesh);
	//	LoadNormals(inFile, *mesh->Mesh);
	//	LoadIndices(inFile, *mesh->Mesh);

	//	return mesh;
	//}

	Mesh* MeshLoader::LoadOBJNew(char* path)
	{
		Mesh* mesh = new Mesh();

		//LOAD FILE AND DATA
		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open file " << path << endl;
			return nullptr;
		}

		std::string firstLineChar;
		while (inFile >> firstLineChar)
		{
			if (firstLineChar == "v")
			{
				Vertex* temp = new Vertex();
				inFile >> temp->x;
				inFile >> temp->y;
				inFile >> temp->z;
				mesh->VertexVector.push_back(temp);
				mesh->VertexCount++;
			}
			else if (firstLineChar == "vt")
			{
				TexCoord* temp = new TexCoord();
				inFile >> temp->U;
				inFile >> temp->V;
				mesh->TexCoordsVector.push_back(temp);
				mesh->TexCoordCount++;
			}
			else if (firstLineChar == "vn")
			{
				Vector3* temp = new Vector3();
				inFile >> temp->x;
				inFile >> temp->y;
				inFile >> temp->z;
				mesh->NormalVector.push_back(temp);
				mesh->NormalCount++;
			}
			else if (firstLineChar == "f")
			{
				for (int i = 0; i < 3; i++)
				{

					GLushort* vertexIndexTemp = new GLushort;
					GLushort* texCoordIndexTemp = new GLushort;
					GLushort* normalIndexTemp = new GLushort;

					inFile >> *vertexIndexTemp;
					inFile >> *texCoordIndexTemp;
					inFile >> *normalIndexTemp;

					*vertexIndexTemp -= 1;
					*texCoordIndexTemp -= 1;
					*normalIndexTemp -= 1;

					mesh->VertexIndicesVector.push_back(vertexIndexTemp);
					mesh->VertexIndexCount++;

					mesh->TexCoordsIndicesVector.push_back(texCoordIndexTemp);

					mesh->NormalIndicesVector.push_back(normalIndexTemp);

				}
			}
			else
			{
				std::cout << "Letter Not Recognised! Char: " << firstLineChar << std::endl;
			}
		}

		LoadVerticesOBJ(*mesh);
		LoadIndicesOBJNew(*mesh);
		LoadNormalsOBJ(*mesh);
		LoadTexCoordsOBJ(*mesh);

		inFile.close();

		return mesh;
	}
}
//	Mesh* MeshLoader::LoadOBJ(char* path)
//	{
//		Mesh* mesh = new Mesh();
//
//		//LOAD FILE AND DATA
//		ifstream inFile;
//
//		inFile.open(path);
//
//		if (!inFile.good())
//		{
//			cerr << "Can't open file " << path << endl;
//			return nullptr;
//		}
//
//		char firstLineChar;
//		while (inFile >> firstLineChar)
//		{
//			if (firstLineChar == 'v')
//			{
//				Vertex* temp = new Vertex();
//				inFile >> temp->x;
//				inFile >> temp->y;
//				inFile >> temp->z;
//				mesh->VertexVector.push_back(temp);
//				mesh->VertexCount++;
//			}
//			else if (firstLineChar == 'f')
//			{
//				for (int i = 0; i < 3; i++)
//				{
//
//					GLushort* vertexIndexTemp = new GLushort;
//
//					inFile >> *vertexIndexTemp;
//
//					*vertexIndexTemp -= 1;
//
//					mesh->VertexIndicesVector.push_back(vertexIndexTemp);
//					mesh->VertexIndexCount++;
//				}
//			}
//			else
//			{
//				std::cout << "Letter Not Recognised! Char: " << firstLineChar << std::endl;
//			}
//		}
//
//		LoadVerticesOBJ(*mesh);
//		LoadIndicesOBJ(*mesh);
//
//		inFile.close();
//
//		return mesh;
//	}
//}

