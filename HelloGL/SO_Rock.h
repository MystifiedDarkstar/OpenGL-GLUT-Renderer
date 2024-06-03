#pragma once
#ifndef _SO_ROCK_H
#define _SO_ROCK_H

#include "SO_BaseClass.h"

class SO_Rock : public SO_BaseClass
{
public:
	SO_Rock(Mesh* mesh, Texture2D* texture, Vector3* startPos);
	~SO_Rock();

	void Draw();
	void Update();

	void InitMaterial();

private:

	float rockRotation;
	Material* m_material;
};

#endif