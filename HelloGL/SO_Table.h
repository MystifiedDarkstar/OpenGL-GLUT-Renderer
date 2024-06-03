#pragma once
#ifndef _SO_TABLE_H
#define _SO_TABLE_H

#include "SO_BaseClass.h"

class SO_Table : public SO_BaseClass
{
public:
	SO_Table(Mesh* mesh, Texture2D* texture, Vector3* startPos);
	~SO_Table();

	void Draw();
	void Update();

	void InitMaterial();

private:

	Material* m_material;
};

#endif