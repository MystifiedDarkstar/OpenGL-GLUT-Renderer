#include "Pyramid.h"

Pyramid::Pyramid(Mesh* mesh,float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	if (m_mesh->Vertices != nullptr && m_mesh->Indices != nullptr)
	{
		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(pyramidRotation * 4, 0, 1, 0);
		glRotatef(pyramidRotation * 2, 1, 0, 0);
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < m_mesh->IndexCount; i++)
		{
			glColor3fv(&m_mesh->Colours[m_mesh->Indices[i]].r);
			glVertex3fv(&m_mesh->Vertices[m_mesh->Indices[i]].x);
		}
		glEnd();

		glPopMatrix();
	}
}

void Pyramid::Update()
{
	pyramidRotation = fmod(pyramidRotation + 0.5f, 360);
}
