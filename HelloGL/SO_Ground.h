#pragma once

#ifndef _SO_GROUND_H
#define _SO_GROUND_H

#include "SO_BaseClass.h"

class SO_Ground : public SO_BaseClass
{
public:
	SO_Ground(Mesh* mesh, Texture2D* texture, Vector3* startPos);
	~SO_Ground();

	void Draw();
	void Update();

	void InitMaterial();

private:
	Material* m_material;
};

#endif