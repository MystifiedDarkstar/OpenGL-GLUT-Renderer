#pragma once
#include <windows.h>
#include <iostream>

#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GLUTCallbacks.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "SO_LinkedList.h"
#include "SO_BaseClass.h"
#include "SO_Ground.h"
#include "SO_Rock.h"
#include "SO_Barrel.h"
#include "SO_Chair.h"
#include "SO_Table.h"
#include "Camera.h"

#define REFRESHRATE 16
#define SCR_WIDTH 1280
#define SCR_HEIGHT 720

#ifndef _HELLOGL_H
#define _HELLOGL_H


class Simulation
{
public:
	//constructor
	Simulation(int argc, char* argv[]);
	//destructor
	~Simulation(void);

	// INIT FUNCTIONS
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();
	void InitMenu();
	void InitTextures();

	//display function
	void Display();

	//text functions
	void DrawString(const char* text, Vector3* position, Color* color);

	//UPDATE
	void Update();

	//KEYBOARD
	void Keyboard(unsigned char key, int x, int y);
	void MouseMovement(int x, int y);
	void SelectionMenuHandler(int menuValue);

	void CalculateFrameRate();
	void SetUpdateTime(float deltaTime) { m_updateTime = deltaTime; }

	//ROTATIONS
private:
	// camera
	Camera* m_camera;
	float lastX = SCR_WIDTH / 2.0f;
	float lastY = SCR_HEIGHT / 2.0f;
	bool firstMouse = true;

	SO_LinkedList* m_SO_List;
	ListNode* m_SO_List_Head = nullptr;

	Vector4* m_lightPosition;
	Lighting* m_lightData;

	bool m_isTrackingObject = true;
	
	int m_updateTime;
	float m_deltaTime;

	Mesh* GroundMesh;
	Mesh* RockMesh;
	Mesh* BarrelMesh;
	Mesh* ChairMesh;
	Mesh* TableMesh;

	Texture2D* m_GroundTexture;
	Texture2D* m_RockTexture;
	Texture2D* m_YellowBarrelTexture;
	Texture2D* m_RedBarrelTexture;
	Texture2D* m_BlueBarrelTexture;
	Texture2D* m_DarkWoodTexture;

	SO_BaseClass* m_CurrentSelected = nullptr;
};



#endif // !_HELLOGL_H
