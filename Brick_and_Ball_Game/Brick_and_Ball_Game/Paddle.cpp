#include "Paddle.h"

using namespace paddle;

paddleBox::paddleBox()
{
	locX = 200;
	locY = 230;
	//set the index, location, size, and border style for the brickPic
	paddlePic->Location = System::Drawing::Point(locX, locY);
	paddlePic->Size = System::Drawing::Size(40, 16);
	paddlePic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	paddlePic->BackColor = System::Drawing::Color::HotPink;
}

paddleBox::paddleBox(int x, int y)
{
	locX = x;
	locY = y;
	//set the index, location, size, and border style for the brickPic
	paddlePic->Location = System::Drawing::Point(locX, locY);
	paddlePic->Size = System::Drawing::Size(40, 16);
	paddlePic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	paddlePic->BackColor = System::Drawing::Color::HotPink;
}

paddleBox::~paddleBox()
{
	delete paddlePic;
}

void paddleBox::movePaddle(int movX)
{
	paddlePic->Location = System::Drawing::Point(movX, locY);
}

void paddleBox::launchBall()
{
	//launches the ball
}

