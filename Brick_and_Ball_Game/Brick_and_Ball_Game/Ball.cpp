#include "Ball.h"

using namespace ball;

ballBox::ballBox()
{
	speedX = 0;
	speedY = 0;
	locX = 220;
	locY = 215;
	ballPic->Location = System::Drawing::Point(locX, locY);
	ballPic->Size = System::Drawing::Size(16, 16);
	//ballPic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	//ballPic->BackColor = System::Drawing::Color::LawnGreen;
	ballPic->Image = Image::FromFile(L"golfball.png");
}

ballBox::ballBox(int x, int y)
{
	speedX = 0;
	speedY = 0;
	locX = x;
	locY = y;
	ballPic->Location = System::Drawing::Point(locX, locY);
	ballPic->Size = System::Drawing::Size(16, 16);
	//ballPic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	//ballPic->BackColor = System::Drawing::Color::LawnGreen;
	ballPic->Image = Image::FromFile(L"golfball.png");
}

ballBox::~ballBox()
{
	delete ballPic;
}

void ballBox::setSpeedX(int x)
{
	speedX = x;
}

void ballBox::setSpeedY(int y)
{
	speedY = y;
}

int ballBox::getSpeedX()
{
	return speedX;
}

int ballBox::getSpeedY()
{
	return speedY;
}

void ballBox::setLocX(int x)
{
	locX = x;
	ballPic->Location = System::Drawing::Point(locX, locY);
}

void ballBox::moveBall()
{
	locX += speedX;
	locY += speedY;
	ballPic->Location = System::Drawing::Point(locX, locY);
}