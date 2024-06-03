#pragma once
#ifndef _SO_BARREL_H
#define _SO_BARREL_H

#include "SO_BaseClass.h"

class SO_Barrel : public SO_BaseClass
{
public:
	SO_Barrel(Mesh* mesh, Texture2D* texture, Vector3* startPos);
	~SO_Barrel();

	void Draw();
	void Update();

	void InitMaterial();

private:

	Material* m_material;
};

#endif _SO_BARREL_H