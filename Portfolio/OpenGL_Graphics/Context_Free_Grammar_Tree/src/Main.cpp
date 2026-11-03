/**
 * @file Main.cpp
 * @brief This file contains the implementations needed for setting up the glut window, and user interface.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Libraries
#include "Main.h"

//Main Routine
int main(int argc, char* argv[]){
	//Command Argument Check
	if (argc == 2){
		SystemPath.append(argv[1]);
	}
	else{
		cout << "Please enter: \"./assignment4 LSystem.txt\"" << endl;
		return 0;
	}

	//Load Positions/Normals/UVs
	LoadOBJ(ModelName, ModelPath, Positions, Normals, UVs, NULL, numPositions, numNormals, numUVs, NULL);

	//Initialize GLUT library and display.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(WindowPositionX,WindowPositionY);
	glutInitWindowSize(ScreenWidth, ScreenHeight);
	glutCreateWindow("Assignment 4");

	//Initialize viewport, display callback, and scene.
	glViewport(0, 0, ScreenWidth, ScreenHeight);
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	Initialize();

	//Load L System
	if (!System.LoadSystem(SystemPath))
		return 0;
	System.Update();
	System.BuildSystem();
	System.Display();

	//Controller
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecial);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);

	//GLUT Main Loop
	glutMainLoop();
	return(0);
}

//Initialize Scene
void Initialize(){

	//Scene Setup
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	//Viewport Orientation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
		45.0f,    //FOV y
		1.0f,     //Aspect Ratio
		0.1f,     //Near Distance
		1000.0f); //Far Distance

	//Texture Setup
	textureHandle = LoadImage(TextureName, TextureDirectory);

	//Light Setup
	glEnable(GL_LIGHTING);
	GLfloat gsLightAmbientColour[]     =  {0.2f, 0.2f, 0.2f, 1.0f};			//Grey
	GLfloat gsLightDiffuseColour[6][4] = {{1.0f, 0.0f, 0.0f, 0.0f},			//Red
																				{1.0f, 1.0f, 0.0f, 0.0f},			//Yellow
																				{0.0f, 1.0f, 0.0f, 0.0f},			//Green
																				{1.0f, 1.0f, 1.0f, 0.0f},			//White
																				{1.0f, 1.0f, 1.0f, 0.0f},			//White
																				{1.0f, 1.0f, 1.0f, 0.0f}};		//White
	GLfloat gsLightPosition[6][4]      = {{10.0f, 0.0f, 10.0f, 0.0f},		//Front Left
																				{-10.0f, 0.0f, 10.0f, 0.0f},	//Front Right
																				{0.0f, 0.0f, -10.0f, 0.0f},		//Back
																				{10.0f, 0.0f, 10.0f, 0.0f},		//Front Left
																				{-10.0f, 0.0f, 10.0f, 0.0f},	//Front Right
																				{0.0f, 0.0f, -10.0f, 0.0f}};	//Back
	for (int i=0 ; i<6 ; i++){
		glLightfv(GL_LIGHT0+i, GL_AMBIENT, gsLightAmbientColour);
		glLightfv(GL_LIGHT0+i, GL_DIFFUSE, gsLightDiffuseColour[i]);
		glLightfv(GL_LIGHT0+i, GL_POSITION, gsLightPosition[i]);
	}
}

//Render Scene
void RenderScene(){

	//Clear Colour/Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		EyeX, EyeY, EyeZ,  //Eye Position
		EyeX, EyeY, 0.0f,  //Lookat Position
		0.0f, 1.0f, 0.0f); //Up Vector

	//Tree
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();{
		glMultMatrixf(RotationMatrix.getData());
		System.DrawSystem(Spine, Girth);
	}
	glPopMatrix();

	//Object
	if (Arena){
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glPushMatrix();
		{
			//Rotation
			glMultMatrixf(RotationMatrix.getData());

			//Enable and bind normal/vertex positions.
			glEnableClientState(GL_NORMAL_ARRAY);         //Enable Normal Buffer
			glNormalPointer(GL_FLOAT, 0, Normals);        //Supply Normals Array
			glEnableClientState(GL_VERTEX_ARRAY);         //Enable Vertex Buffer
			glVertexPointer(3, GL_FLOAT, 0, Positions);   //Supply Vertex Array

			//Draw with index/vertex buffers.
			glDrawArrays(GL_TRIANGLES, 0, numPositions);
		}
		glPopMatrix();
	}

	//Texture
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, UVs);

	//Lights
	glPushMatrix();{

		//Toggle Lights
		for (int i=0 ; i<6 ; i++){
			if (ToggleLights[i]){
				glEnable(GL_LIGHT0+i);
			}
			else{
				glDisable(GL_LIGHT0+i);
			}
		}
	}
	glPopMatrix();

	//Cleanup
	glFlush();
	glutSwapBuffers();
}

//Load Image
GLuint LoadImage(string &ImageName, const string &ImagePath){

	//File
	string FilePath = ImagePath + ImageName;
	CBitmap *Bitmap = new CBitmap(FilePath.c_str());
	GLuint Image = 0;

	//Open
	if (NULL != Bitmap){

		//Enable
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);

		//Bind
		glGenTextures(1, &Image);
		glBindTexture(GL_TEXTURE_2D, Image);

		//Texture Properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		//Generate
		int   ImageWidth  = Bitmap->GetWidth();
		int   ImageHeight = Bitmap->GetHeight();
		void *ImageData   = Bitmap->GetBits();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ImageWidth, ImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, ImageData);

		//Error
		GLenum errEnum = glGetError();
		errEnum = glGetError();
		if (GL_NO_ERROR != errEnum){
			printf("An error occured: %x\n", errEnum);
		}

		//Finish
		glBindTexture(GL_TEXTURE_2D, 0);
		delete Bitmap;
	}

	return Image;
}
