#pragma once
#ifndef _PYRAMID_SCENEOBJECT_H
#define _PYRAMID_SCENEOBJECT_H

#include "SceneObject.h"
#include <math.h>

class Pyramid : public SceneObject
{
public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();

private:

	float pyramidRotation;
	Vector3 _position;
};

#endif // !_PYRAMID_SCENEOBJECT_H