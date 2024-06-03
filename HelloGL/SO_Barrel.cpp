#include "SO_Barrel.h"

SO_Barrel::SO_Barrel(Mesh* mesh, Texture2D* texture, Vector3* startPos) : SO_BaseClass(mesh, texture, startPos)
{

}

SO_Barrel::~SO_Barrel()
{
	delete m_material;
	m_material = nullptr;
}

void SO_Barrel::Draw()
{
	if (m_mesh->Vertices != nullptr && m_mesh->Normals != nullptr && m_mesh->TexCoords != nullptr &&
		m_mesh->VertexIndices != nullptr && m_mesh->NormalsIndices != nullptr && m_mesh->TexCoordsIndices != nullptr)
	{
		InitMaterial();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(m_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(m_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(m_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, m_material->Shininess);

		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_texture->GetID());

		glScalef(0.5f,0.5f,0.5f);
		glTranslatef(m_position->x, m_position->y, m_position->z);

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < m_mesh->VertexIndexCount; i++)
		{
			glTexCoord3fv(&m_mesh->TexCoords[m_mesh->TexCoordsIndices[i]].U);
			glNormal3fv(&m_mesh->Normals[m_mesh->NormalsIndices[i]].x);
			glVertex3fv(&m_mesh->Vertices[m_mesh->VertexIndices[i]].x);
		}

		glEnd();

		glPopMatrix();
	}
}

void SO_Barrel::Update()
{

}

void SO_Barrel::InitMaterial()
{
	m_material = new Material();

	m_material->Ambient.x = 1.0f; m_material->Ambient.y = 1.0f; m_material->Ambient.z = 1.0f;
	m_material->Ambient.w = 1.0f;

	m_material->Diffuse.x = 0.5f; m_material->Diffuse.y = 0.5f; m_material->Diffuse.z = 0.5f;
	m_material->Diffuse.w = 1.0f;

	m_material->Specular.x = 1.0f; m_material->Specular.y = 1.0f; m_material->Specular.z = 1.0f;
	m_material->Specular.w = 1.0f;

	m_material->Shininess = 1000.0f;
}
