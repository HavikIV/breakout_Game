#include "Paddle.h"

using namespace paddle;

paddleBox::paddleBox()
{
	locX = 200;
	locY = 450;
	createPaddle();
}

paddleBox::paddleBox(int x, int y)
{
	locX = x;
	locY = y;
	createPaddle();
}

paddleBox::~paddleBox()
{
	delete paddlePic;
}

void paddleBox::createPaddle()
{
	paddlePic->Location = System::Drawing::Point(locX, locY);
	paddlePic->Size = System::Drawing::Size(40, 4);
	paddlePic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	paddlePic->BackColor = System::Drawing::Color::HotPink;
	paddlePic->Enabled = false;
}

void paddleBox::movePaddle(int movX)
{
	paddlePic->Location = System::Drawing::Point(movX, locY);
}

