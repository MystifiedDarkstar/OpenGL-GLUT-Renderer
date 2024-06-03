#pragma once
#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H

#include "Structures.h"
#include "Texture2D.h"

class SO_BaseClass
{
public:
	SO_BaseClass(Mesh* mesh, Texture2D* texture, Vector3* position);
	virtual ~SO_BaseClass();

	virtual void Update() {}
	virtual void Draw() {}

	inline void setSelected(bool state) { m_IsSelected = state; }
	void ChangeTexture(Texture2D* texture);

protected:
	Mesh* m_mesh;
	Texture2D* m_texture;
	Vector3* m_position;

private:
	bool m_IsSelected = false;
};


#endif // !_SCENEOBJECT_H
