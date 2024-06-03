#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVerticesOBJ(Mesh& mesh);
	void LoadTexCoordsOBJ(Mesh& mesh);
	void LoadNormalsOBJ(Mesh& mesh);
	void LoadIndicesOBJNew(Mesh& mesh);

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


