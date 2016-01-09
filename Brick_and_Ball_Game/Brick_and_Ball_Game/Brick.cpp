#include "Brick.h"

using namespace brick;

brickBox::brickBox()
{
	health = 1;
	locX = 12;
	locY = 12;
	index = 1;
	createBrick();
}

brickBox::brickBox(int h, int x, int y, int n)
{
	health = h;
	locX = x;
	locY = y;
	index = n;
	createBrick();
}

brickBox::~brickBox()
{
	if (health == 0)
	{
		delete brickPic;
	}
}

void brickBox::decreaseHealth()
{
	health -= 1; //deceases the health by 1
	
	// determine if the brick needs to be destroyed
	if (health == 0)
	{
		brickBox::~brickBox();
	}

	// change the color of the brick based on the new health
	switch (health)
	{
	case 1:
		brickPic->BackColor = System::Drawing::Color::Firebrick;
		break;
	case 2:
		brickPic->BackColor = System::Drawing::Color::DimGray;
		break;
	case 3: 
		brickPic->BackColor = System::Drawing::Color::SteelBlue;
		break;
	default:
		break;
	}
}

void brickBox::createBrick()
{
	//set the index, location, size, and border style for the brickPic
	brickPic->TabIndex = index;
	brickPic->Location = System::Drawing::Point(locX, locY);
	brickPic->Size = System::Drawing::Size(40, 16);
	brickPic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

	//set the BackColor based on the health amount
	switch (health)
	{
	case 1:
		brickPic->BackColor = System::Drawing::Color::Firebrick;
		break;
	case 2:
		brickPic->BackColor = System::Drawing::Color::DimGray;
		break;
	case 3:
		brickPic->BackColor = System::Drawing::Color::SteelBlue;
		break;
	case 4:
		brickPic->BackColor = System::Drawing::Color::Black;
		break;
	default:
		break;
	}
}

void brickBox::modifyBrick(int h, int x, int y, int n)
{
	health = h;
	locX = x;
	locY = y;
	index = n;
	createBrick();
}

int brickBox::getHealth()
{
	return health;
}