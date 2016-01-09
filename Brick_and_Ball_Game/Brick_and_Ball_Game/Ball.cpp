#include "Ball.h"

using namespace ball;

ballBox::ballBox()
{
	speedX = 0;
	speedY = 0;
	locX = 218;
	locY = 446;
	createBall();
}

ballBox::ballBox(int x, int y)
{
	speedX = 0;
	speedY = 0;
	locX = x;
	locY = y;
	createBall();
}

ballBox::~ballBox()
{
	delete ballPic;
}

int ballBox::getSpeedX()
{
	return speedX;
}

int ballBox::getSpeedY()
{
	return speedY;
}
void ballBox::setSpeedX(int x)
{
	speedX = x;
}

void ballBox::setSpeedY(int y)
{
	speedY = y;
}

void ballBox::setLocX(int x)
{
	locX = x;
	ballPic->Location = System::Drawing::Point(locX, locY);
}

void ballBox::setLocY(int y)
{
	locY = y;
	ballPic->Location = System::Drawing::Point(locX, locY);
}

void ballBox::createBall()
{
	ballPic->Location = System::Drawing::Point(locX, locY);
	ballPic->Size = System::Drawing::Size(4, 4);
	ballPic->Image = Image::FromFile(L"golfball.png");
	ballPic->Enabled = false;
}

void ballBox::moveBall()
{
	locX += speedX;
	locY += speedY;
	ballPic->Location = System::Drawing::Point(locX, locY);
}