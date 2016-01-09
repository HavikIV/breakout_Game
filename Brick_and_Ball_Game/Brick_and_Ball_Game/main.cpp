//Manjinder Singh
//Main .cpp file
//contains the WinMain() to run the application.
//The application is a simple game that uses a ball to break the bricks.

#include "brickBallGame.h"
#include <Windows.h>
#include <Windows.Applicationmodel.Activation.h>

using namespace System;
using namespace System::Windows::Forms;

//This is used to run GUIs for programs, in other it's the Windows Main function
int CALLBACK WinMain(_In_  HINSTANCE hInstance, _In_  HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  int nCmdShow) //the parameters are defined in Windows.h
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Brick_and_Ball_Game::brickBallGame form;
	Application::Run(%form);
	return 0;

}