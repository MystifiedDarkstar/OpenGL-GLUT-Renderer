#pragma once
#ifndef _SO_CHAIR_H
#define _SO_CHAIR_H

#include "SO_BaseClass.h"

class SO_Chair : public SO_BaseClass
{
public:
	SO_Chair(Mesh* mesh, Texture2D* texture, Vector3* startPos);
	~SO_Chair();

	void Draw();
	void Update();

	void InitMaterial();

private:

	Material* m_material;
};


#endif // !_SO_CHAIR_H