#include "Simulation.h"
#include <fstream>
#include <string>

using namespace std;

// CONSTRUCTOR / DESTRUCTOR
Simulation::Simulation(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitLighting();
	InitTextures();
	InitObjects();
	InitMenu();
	glutMainLoop();
}
Simulation::~Simulation(void)
{
	delete m_camera;
	
	delete m_lightPosition;
	m_lightPosition = nullptr;

	delete m_lightData;
	m_lightData = nullptr;
}

// INIT FUNCTIONS
void Simulation::InitObjects()
{
	m_camera = new Camera(glm::vec3(0.0f, 5.0f, 25.0f));

	m_SO_List = new SO_LinkedList;

	GroundMesh = MeshLoader::LoadOBJNew((char*)"Assets/Models/Ground.obj");
	RockMesh = MeshLoader::LoadOBJNew((char*)"Assets/Models/Rock1.obj");
	BarrelMesh = MeshLoader::LoadOBJNew((char*)"Assets/Models/Barrel.obj");
	ChairMesh = MeshLoader::LoadOBJNew((char*)"Assets/Models/Chair.obj");
	TableMesh = MeshLoader::LoadOBJNew((char*)"Assets/Models/Table.obj");

	Vector3* groundMeshPos = new Vector3 ( 0, 0, 0 );
	SO_BaseClass* tempGround = new SO_Ground( GroundMesh, m_GroundTexture, groundMeshPos );
	m_SO_List->MakeNode(&m_SO_List_Head, tempGround);

	
	for (int i = 0; i < 20; i++)
	{
		Vector3* rockMeshPos = new Vector3(((rand() % 300) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 500) / 10.0f);
		SO_BaseClass* tempRock = new SO_Rock( RockMesh, m_RockTexture, rockMeshPos );
		m_SO_List->MakeNode(&m_SO_List_Head, tempRock);
	}
	std::cout << m_SO_List->ReturnSizeList() << std::endl;

	Vector3* barrelMeshPos1 = new Vector3(5, 4, 5);
	SO_BaseClass* tempBarrel;
	tempBarrel = new SO_Barrel(BarrelMesh, m_YellowBarrelTexture, barrelMeshPos1);
	m_SO_List->MakeNode(&m_SO_List_Head, tempBarrel);

	Vector3* barrelMeshPos2 = new Vector3(5, 4, -5);
	tempBarrel = new SO_Barrel(BarrelMesh, m_YellowBarrelTexture, barrelMeshPos2);
	m_SO_List->MakeNode(&m_SO_List_Head, tempBarrel);

	Vector3* barrelMeshPos3 = new Vector3(-5, 4, 5);
	tempBarrel = new SO_Barrel(BarrelMesh, m_YellowBarrelTexture, barrelMeshPos3);
	m_SO_List->MakeNode(&m_SO_List_Head, tempBarrel);

	Vector3* barrelMeshPos4 = new Vector3(-5, 4, -5);
	tempBarrel = new SO_Barrel(BarrelMesh, m_YellowBarrelTexture, barrelMeshPos4);
	m_SO_List->MakeNode(&m_SO_List_Head, tempBarrel);

	SO_BaseClass* tempChair;

	Vector3* chairMeshPos1 = new Vector3(-2.7, 0.5, 1);
	tempChair = new SO_Chair(ChairMesh, m_DarkWoodTexture, chairMeshPos1);
	m_SO_List->MakeNode(&m_SO_List_Head, tempChair);

	Vector3* chairMeshPos2 = new Vector3(-3.4 , 0.5, 1);
	tempChair = new SO_Chair(ChairMesh, m_DarkWoodTexture, chairMeshPos2);
	m_SO_List->MakeNode(&m_SO_List_Head, tempChair);

	SO_BaseClass* tempTable;

	Vector3* tableMeshPos1 = new Vector3(-1.5, 0.4, 1.5);
	tempTable = new SO_Table(TableMesh, m_DarkWoodTexture, tableMeshPos1);
	m_SO_List->MakeNode(&m_SO_List_Head, tempTable);

}
void Simulation::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Simple OpenGL Program");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutPassiveMotionFunc(GLUTCallbacks::MouseMovementCallback);
	glutSetCursor(GLUT_CURSOR_NONE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	gluPerspective(60, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);

	

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

}

void Simulation::InitLighting()
{
	m_lightPosition = new Vector4();
	m_lightPosition->x = 0.0f;
	m_lightPosition->y = 0.0f;
	m_lightPosition->z = 2.0f;
	m_lightPosition->w = 0.0f;

	m_lightData = new Lighting();
	m_lightData->Ambient.x = 1.0f;
	m_lightData->Ambient.y = 1.0f;
	m_lightData->Ambient.z = 1.0f;
	m_lightData->Ambient.w = 1.0f;
	m_lightData->Diffuse.x = 1.0f;
	m_lightData->Diffuse.y = 1.0f;
	m_lightData->Diffuse.z = 1.0f;
	m_lightData->Diffuse.w = 1.0f;
	m_lightData->Specular.x = 0.2f;
	m_lightData->Specular.y = 0.2f;
	m_lightData->Specular.z = 0.2f;
	m_lightData->Specular.w = 1.0f;
}

void Simulation::InitMenu()
{
	glutCreateMenu(GLUTCallbacks::SelectionMenu);

	glutAddMenuEntry("Barrel 1", 1);
	glutAddMenuEntry("Barrel 2", 2);
	glutAddMenuEntry("Barrel 3", 3);
	glutAddMenuEntry("Barrel 4", 4);
	glutAddMenuEntry("Yellow", 5);
	glutAddMenuEntry("Red", 6);
	glutAddMenuEntry("Blue", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Simulation::InitTextures()
{
	m_GroundTexture = new Texture2D();
	m_GroundTexture->Load((char*)"Assets/Textures/Ground.raw", 1024, 1024);

	m_RockTexture = new Texture2D();
	m_RockTexture->Load((char*)"Assets/Textures/RockTexture.raw",2048,2048);

	m_DarkWoodTexture = new Texture2D();
	m_DarkWoodTexture->Load((char*)"Assets/Textures/DarkWoodTexture.raw",1024,1024);

	m_YellowBarrelTexture = new Texture2D();
	m_YellowBarrelTexture->Load((char*)"Assets/Textures/YellowBarrel.raw", 1024, 1024);

	m_RedBarrelTexture = new Texture2D();
	m_RedBarrelTexture->Load((char*)"Assets/Textures/RedBarrel.raw", 1024, 1024);

	m_BlueBarrelTexture = new Texture2D();
	m_BlueBarrelTexture->Load((char*)"Assets/Textures/BlueBarrel.raw", 1024, 1024);
}


// DISPLAY && UPDATE
void Simulation::Display()
{
	CalculateFrameRate();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Vector3 OpenGLPropertyTextPosition = { 20, 20, 0 };
	Vector3 FPSCounterTextPosition = { 1180, 680, 0 };
	Vector3 CameraModeTextPosition = { 560, 680, 0 };
	Vector3 ControlsTextPosition = { 20, 680, 0 };

	Color TextColour = { 1.0f, 1.0f, 1.0f }; // white

	DrawString("OpenGL Graphics Renderer; Property Of Aidan Spencer", &OpenGLPropertyTextPosition, &TextColour);

	std::string updateTime = "FPS: " + std::to_string(m_updateTime);
	DrawString(updateTime.c_str(), &FPSCounterTextPosition, &TextColour);

	if(m_isTrackingObject)
		DrawString("Camera Mode: Object Tracking",&CameraModeTextPosition, &TextColour);
	else
		DrawString("Camera Mode: Free Fly", &CameraModeTextPosition, &TextColour);

	DrawString("Simulation Controls:\n> WASD - Move Camera\n> Mouse - Look Around\n> R CLICK - Selection Menu\n> TAB - Disable/Enable Object Tracking Camera\n> ESC - Quit Simulation" , &ControlsTextPosition, &TextColour);

	m_SO_List->DrawList(m_SO_List_Head);
	
	glutSwapBuffers();

	glFlush();

}
void Simulation::Update()
{
	glLoadIdentity();

	if (m_isTrackingObject)
	{
		// focus on object position
		gluLookAt(m_camera->Position.x, m_camera->Position.y, m_camera->Position.z,
			0, 0, 0,
			m_camera->Up.x, m_camera->Up.y, m_camera->Up.z);
	}
	else
	{
		// update to camera location based on mouse movement.
		gluLookAt(m_camera->Position.x, m_camera->Position.y, m_camera->Position.z,
			m_camera->Position.x + m_camera->Front.x, m_camera->Position.y + m_camera->Front.y, m_camera->Position.z + m_camera->Front.z,
			m_camera->Up.x, m_camera->Up.y, m_camera->Up.z);
	}


	glLightfv(GL_LIGHT0, GL_AMBIENT, &(m_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(m_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(m_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(m_lightPosition->x));

	m_SO_List->UpdateList(m_SO_List_Head);

	glutPostRedisplay();
}

// PLAYER INPUT EVENTS
void Simulation::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		m_camera->ProcessKeyboard(LEFT, m_deltaTime);
		break;
	case 'd':
		m_camera->ProcessKeyboard(RIGHT, m_deltaTime);
		break;
	case 'w':
		m_camera->ProcessKeyboard(FORWARD, m_deltaTime);
		break;
	case 's':
		m_camera->ProcessKeyboard(BACKWARD, m_deltaTime);
		break;
	case '\t':
		m_isTrackingObject = !m_isTrackingObject;
		m_camera->Up.x = 0.0f;
		m_camera->Up.y = 5.0f;
		m_camera->Up.z = 0.0f;
		break;
	case '\x1b': // escape key
		glutLeaveMainLoop(); // quits
		break;
	default:
		break;
	}		
}

void Simulation::MouseMovement(int x , int y)
{
	if (!m_isTrackingObject)
	{
		float xpos = static_cast<float>(x);
		float ypos = static_cast<float>(y);

		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

		lastX = xpos;
		lastY = ypos;

		m_camera->ProcessMouseMovement(xoffset, yoffset);

		glutPostRedisplay();

		//this is the main thing that keeps it from leaving the screen
		if (x < 100 || x > SCR_WIDTH - 100) {  //you can use values other than 100 for the screen edges if you like, kind of seems to depend on your mouse sensitivity for what ends up working best
			lastX = SCR_WIDTH / 2;   //centers the last known position, this way there isn't an odd jump with your cam as it resets
			lastY = SCR_HEIGHT / 2;
			glutWarpPointer(SCR_WIDTH / 2, SCR_HEIGHT / 2);  //centers the cursor
		}
		else if (y < 100 || y > SCR_HEIGHT - 100) {
			lastX = SCR_WIDTH / 2;
			lastY = SCR_HEIGHT / 2;
			glutWarpPointer(SCR_WIDTH / 2, SCR_HEIGHT / 2);
		}
	}
}

void Simulation::SelectionMenuHandler(int menuValue)
{
	Texture2D* newTexture = new Texture2D();
	switch (menuValue)
	{
	case 1: // select barrel 1
		if(m_CurrentSelected)
			m_CurrentSelected->setSelected(false); // set the previous selection false

		m_CurrentSelected = m_SO_List->GetNodeAtPos(m_SO_List_Head,21)->objectData;
		m_CurrentSelected->setSelected(true); // set new selection true
		break;
	case 2: // select barrel 2
		if (m_CurrentSelected)
			m_CurrentSelected->setSelected(false); // set the previous selection false

		m_CurrentSelected = m_SO_List->GetNodeAtPos(m_SO_List_Head, 22)->objectData;
		m_CurrentSelected->setSelected(true); // set new selection true
		break;
	case 3: // select barrel 3
		if (m_CurrentSelected)
			m_CurrentSelected->setSelected(false); // set the previous selection false

		m_CurrentSelected = m_SO_List->GetNodeAtPos(m_SO_List_Head, 23)->objectData;
		m_CurrentSelected->setSelected(true); // set new selection true
		break;
	case 4: // select barrel 4
		if (m_CurrentSelected)
			m_CurrentSelected->setSelected(false); // set the previous selection false

		m_CurrentSelected = m_SO_List->GetNodeAtPos(m_SO_List_Head, 24)->objectData;
		m_CurrentSelected->setSelected(true); // set new selection true
		break;
	case 5: // set texture of barrel Yellow
		if (m_CurrentSelected)
		{
			m_CurrentSelected->ChangeTexture(m_YellowBarrelTexture);
		}
		break;
	case 6: // set texture of barrel red
		if (m_CurrentSelected)
		{
			m_CurrentSelected->ChangeTexture(m_RedBarrelTexture);
		}
		break;
	case 7 : // set texture of barrel blue
		if (m_CurrentSelected)
		{
			m_CurrentSelected->ChangeTexture(m_BlueBarrelTexture);
		}
		break;
	default:
		break;
	}
}

void Simulation::DrawString(const char* text, Vector3* position, Color* color)
{
	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), 0 , glutGet(GLUT_WINDOW_HEIGHT),  -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glTranslatef(position->x , position->y, position->z);
	glColor4f(color->r, color->g , color->b, 1.0);

	glBindTexture(GL_TEXTURE_2D, 0);

	glRasterPos2f(0.0f,0.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)text);

	glColor3f(0,0,0);
	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_COLOR);
	glEnable(GL_LIGHTING);
}

void Simulation::CalculateFrameRate()
{
	static float framesPerSecond = 0.0f;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount() * 0.001f;
	m_deltaTime = currentTime;
	++framesPerSecond;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		m_updateTime = std::floor(framesPerSecond);
		framesPerSecond = 0;
	}
}