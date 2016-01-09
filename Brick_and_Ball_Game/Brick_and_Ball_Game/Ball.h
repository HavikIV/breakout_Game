// *********************************************************
// Header file Ball.h for the ball pictureBox
// *********************************************************
#pragma once
#ifndef BALL_CLASS
#define BALL_CLASS

namespace ball
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class ballBox
	{
	public:
		PictureBox^ ballPic = gcnew System::Windows::Forms::PictureBox();
		// ballPic represents the ball

		ballBox();
		// default constructor
		// sets the location of the ball to 200, 200
		// the default speed is 0 in both axises

		ballBox(int, int);
		// sets the location of the ball where the paddle is

		void setSpeedX(int);
		// sets the speed the ball moves in the x direction
		// either positive or negative

		void setSpeedY(int);
		// sets the speed that the ball moves in the y direction
		// either positive or negative

		void moveBall();
		// moves the ball based on the speed in both directions

		void setLocX(int);
		// moves the ball to the given x

		int getSpeedX();
		// returns speedX

		int getSpeedY();
		// returns speedY

		~ballBox();
		// destroys the ball

	private:
		int speedX, speedY, locX, locY;
	};
}
#endif