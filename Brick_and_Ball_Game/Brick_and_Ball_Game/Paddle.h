// *********************************************************
// Header file Paddle.h for the paddle pictureBox
// *********************************************************
#pragma once
#ifndef PADDLE_CLASS
#define PADDLE_CLASS

// I decided to make the brick class as part of a namespace as a way
// for me to get experience in coding in other ways than the way it is
// described in the programming textbooks, plus I wanted to mimic the way
// visual studio creates C++/CLI projects.
namespace paddle
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class paddleBox
	{
	public:
		PictureBox^ paddlePic = gcnew System::Windows::Forms::PictureBox();
		// paddlePic is the representation of the paddle for the game

		paddleBox();
		// default constructor
		// creates a paddle at the coordinates (200,200)

		paddleBox(int, int);
		// constructor for creating a custom paddle
		// variables are to set the x and y, respectably in that order, for it's coordinates.

		~paddleBox();
		// destructor
		// destroys the paddle once the game is closed

		void createPaddle();
		// function to load the settings for the paddle pictureBox

		void movePaddle(int);
		// function to move the paddle
		// takes either a positive or negative int value
		// the value is used to move the paddle either left or right
		// positive for moving to the right and negative for moving to the left

	private:
		int locX, locY;
		// health is represents how many hits it takes before the brick is broken
		// locX, locY are the x-/y-coordinates of where to place the brick in the form
		// index will be the tabIndex of the pictureBox
	};
}
#endif