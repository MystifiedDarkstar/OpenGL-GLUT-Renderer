#include "SO_BaseClass.h"

SO_BaseClass::SO_BaseClass(Mesh* mesh, Texture2D* texture, Vector3* position)
{
	m_mesh = mesh;
	m_texture = texture;
	m_position = position;
}
SO_BaseClass::~SO_BaseClass()
{

}

void SO_BaseClass::ChangeTexture(Texture2D* texture)
{
	if (m_IsSelected)
	{
		m_texture = texture;
	}
}
