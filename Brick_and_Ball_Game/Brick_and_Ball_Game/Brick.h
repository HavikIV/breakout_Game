// *********************************************************
// Header file Brick.h for the Brick pictureBox
// *********************************************************
#pragma once
#ifndef BRICK_CLASS
#define BRICK_CLASS

// I decided to make the brick class as part of a namespace as a way
// for me to get experience in coding in other ways than the way it is
// described in the programming textbooks, plus I wanted to mimic the way
// visual studio creates C++/CLI projects.
namespace brick
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// As the PictureBox is a ref class type, I had to make my brick class as a ref class also.
	// Even though code doesn't specifically say that the class is public, it is public by default.
	ref class brickBox
	{
	public:
		PictureBox^ brickPic = gcnew System::Windows::Forms::PictureBox();
		// brickPic is the picturebox that becomes the brick

		brickBox();
		//default constructor
		//creates a brick with 1 health at the coordinates (0,0)

		brickBox(int, int, int, int);
		//constructor for creating a custom brick
		//the first variable is to set the bricks health while the next two
		//variables are to set the x and y, respectably in that order,  for it's coordinates.

		~brickBox();
		//destructor
		//destroys the brick whenever the health reaches 0 or the game is ended either
		//by losing all lives or the user manually closing the game.

		void decreaseHealth();
		//function to decrease the health by 1
		//if health becomes 0, call the destructor to destroy the brick object
		//will adjust the color of the brick based on its new health

		void createBrick();
		// Function to load the setting for the brick pictureBox

		void modifyBrick(int, int, int , int);
		//Function to modify the brick after it's been created
		//changes the health, locX, locY, and the index
		//will call createBrick function to finalize the changes
		//this function will basically be the same as the second constructor

		int getHealth();
		// return the health value

	private:
		int health, locX, locY, index;
		// health is represents how many hits it takes before the brick is broken
		// locX, locY are the x-/y-coordinates of where to place the brick in the form
		// index will be the tabIndex of the pictureBox
	};
}
#endif