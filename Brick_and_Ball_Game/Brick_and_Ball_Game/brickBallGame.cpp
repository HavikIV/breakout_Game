#include "brickBallGame.h"
#include "Brick.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace Brick_and_Ball_Game;
using namespace brick;
using namespace std;

System::Void brickBallGame::brickBallGame_Load(System::Object^  sender, System::EventArgs^  e)
{
	//for loop to dynamically create picture boxes to use as bricks
	//for (int i = 2; i < 20; i++)
	//{
	//	PictureBox^ pic = gcnew System::Windows::Forms::PictureBox();
	//	pic->Name = "brick" + i;
	//	int k = 14;
	//	pic->Location = System::Drawing::Point(40 * (i - 1) + (k + (i-1)), 12);
	//	pic->Size = System::Drawing::Size(40, 16);
	//	pic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	//	//pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"brick1.BackgroundImage")));
	//	this->Controls->Add(pic);
	//}
	
	//brickBox brick1(1, 80, 21, 1);
	//this->Controls->Add(brick1.brickPic);
	//brickBox brick2(3, 120, 5, 2);
	//this->Controls->Add(brick2.brickPic);
	//brickBox brick3(2, 80, 5, 3);
	//this->Controls->Add(brick3.brickPic);
	//brickBox brick4(4, 120, 21, 4);
	//this->Controls->Add(brick4.brickPic);
	//bCollection[0] = gcnew brickBox;// brick345(1, 200, 200, 456);
	//bCollection[0]->modifyBrick(4, 120, 125, 4);
	//this->Controls->Add(bCollection[0]->brickPic);

	//brickCollection(2, 200, 200);
	//this->Controls->Add(brickCollection.brickPic);

	//for loop to dynamically create picture boxes to use as bricks
	/*for (int i = 0; i < 6; i++)
	{
		bCollection[i] = gcnew brickBox;
		bCollection[i]->modifyBrick(1, 40 * (i) + (14 + (i)), 12, i);
		this->Controls->Add(bCollection[i]->brickPic);
	}*/
	setupBricks(4);
	//gPaddle[0] = gcnew paddleBox;
	this->Controls->Add(gPaddle.paddlePic);
	this->Controls->Add(gBall.ballPic);
	//this->Cursor->Hide();
	launchBall = true;
}

System::Void brickBallGame::brickBallGame_Click(System::Object^  sender, System::EventArgs^  e)
{
	//this->brickCollection.~brickBox();
	//this->Controls->RemoveAt(3);
	//this->bCollection[0]->decreaseHealth();
	if (launchBall)
	{
		gBall.setSpeedY(-2);
		gBall.setSpeedX(-2);
		launchBall = false;
	}
}

System::Void brickBallGame::collisionCheck()
{
	if (launchBall == false)
	{
		if (gBall.ballPic->Location.X + 30 >= this->Width) // bounce off the right edge of the form
		{
			gBall.setSpeedX(-2);
		}
		else if (gBall.ballPic->Location.X <= 0) // bounce off the left edge of the form
		{
			gBall.setSpeedX(2);
		}
		else if (gBall.ballPic->Location.Y <= 0) // bounce off the top edge of the form
		{
			gBall.setSpeedY(2);
		}

		// check to see if ball hit a brick
		// have to make sure that it only counts the collision if its within the bricks surface area
		// surface area for top or bottom collision = (bCollection[i]->brickPic->Location.X <= ball <= bCollection[i]->brickPic->Location.X + 40) && top or bottom
		// surface area for left or right collision = (bCollection[i]->brickPic->Location.Y <= ball <= bCollection[i]->brickPic->Location.Y + 16) && left or right
		for (int i = 0; i < 30; i++)
		{
			if (bCollection[i]->getHealth() != 0)
			{
				if (gBall.ballPic->Location.Y + gBall.getSpeedY() <= bCollection[i]->brickPic->Location.Y + 16
					&& gBall.ballPic->Location.Y + 16 + gBall.getSpeedY() >= bCollection[i]->brickPic->Location.Y
					&& !(gBall.ballPic->Location.X + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
						&& gBall.ballPic->Location.X + 16 + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40))
				{
					if (gBall.ballPic->Location.X + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40
						&& gBall.ballPic->Location.X + 16 > bCollection[i]->brickPic->Location.X + 40) // bounce off the right edge
					{
						gBall.ballPic->Location = System::Drawing::Point(bCollection[i]->brickPic->Location.X + 40, bCollection[i]->brickPic->Location.Y);
						gBall.setSpeedX(2);
						bCollection[i]->decreaseHealth();
						break;
					}
					else if (gBall.ballPic->Location.X + 16 + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
						&& gBall.ballPic->Location.X < bCollection[i]->brickPic->Location.X) // bounce off the left edge
					{
						gBall.ballPic->Location = System::Drawing::Point(bCollection[i]->brickPic->Location.X - 16, bCollection[i]->brickPic->Location.Y);
						gBall.setSpeedX(-2);
						bCollection[i]->decreaseHealth();
						break;
					}
				}
				else if (gBall.ballPic->Location.X + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
					&& gBall.ballPic->Location.X + 16 + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40)
				{
					if (gBall.ballPic->Location.Y + 16 + gBall.getSpeedY() >= bCollection[i]->brickPic->Location.Y
						&& gBall.ballPic->Location.Y < bCollection[i]->brickPic->Location.Y) // bounce off top
					{
						gBall.ballPic->Location = System::Drawing::Point(gBall.ballPic->Location.X, bCollection[i]->brickPic->Location.Y - 16);
						gBall.setSpeedY(-2);
						bCollection[i]->decreaseHealth();
						break;
					}
					else if (gBall.ballPic->Location.Y + gBall.getSpeedY() <= bCollection[i]->brickPic->Location.Y + 16
						&& gBall.ballPic->Location.Y + 16 > bCollection[i]->brickPic->Location.Y + 16) // bounce off bottom
					{
						gBall.ballPic->Location = System::Drawing::Point(gBall.ballPic->Location.X, bCollection[i]->brickPic->Location.Y + 16);
						gBall.setSpeedY(2);
						bCollection[i]->decreaseHealth();
						break;
					}
				}
			}
		}

		// check if the ball hit the paddle
		if (gBall.ballPic->Location.Y < 230)
		{
			if (gBall.ballPic->Location.Y + 16 >= gPaddle.paddlePic->Location.Y
				&& (gBall.ballPic->Location.X + 10 >= gPaddle.paddlePic->Location.X
					&& gBall.ballPic->Location.X <= gPaddle.paddlePic->Location.X + 46)) // bounce off the top edge of the paddle, needs to check if its within the paddles x range
			{
				gBall.setSpeedY(-2);
			}
		}
	}
}

System::Void brickBallGame::brickBallGame_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->X < this->Width - 40)
	{
		if (launchBall)
		{
			// while the ball hasn't been launched yet, it needs to stay with the paddle
			gBall.setLocX(e->X + 20);
			//run the timer
			gAnimation->Start();
		}
		gPaddle.movePaddle(e->X);
	}
}

System::Void brickBallGame::runGame()
{
	gBall.moveBall();
}

System::Void brickBallGame::gAnimation_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// updates the form to make it be animated.
	collisionCheck();
	runGame();
}

System::Void brickBallGame::setupBricks(int level)
{
	srand(time(NULL)); // initialize the random seed
	int k; // variable for health, gonna be used to hold a random variable from healthArray
	int healthArray[3] = { 1,1,1 }; // base case for healthArray

	// switch case to determine how to initialize the health array
	switch (level)
	{
	case 2:
		healthArray[1] = 2;
		healthArray[2] = 2;
		break;
	case 3:
		healthArray[0] = 2;
		healthArray[1] = 2;
		healthArray[2] = 3;
		break;
	case 4:
		healthArray[0] = 2;
		healthArray[1] = 3;
		healthArray[2] = 3;
		break;
	case 5:
		healthArray[0] = 3;
		healthArray[1] = 3;
		healthArray[2] = 4;
		break;
	case 6:
		healthArray[0] = 3;
		healthArray[1] = 4;
		healthArray[2] = 4;
		break;
	default:
		break;
	}

	// for loop to dynamically create bricks and store them in the bCollection array
	for (int i = 0; i < 30; i++)
	{
		// pick k randomly from healthArray for the bricks health
		k = healthArray[rand() % 3]; // picks a number from 0 to 2 to select one value from the healthArray
		bCollection[i] = gcnew brickBox; // adds a new brick to the collection, its created with the default constructor
		// modifies the created brick and puts it at the right location
		if (i < 6)
		{
			// sets up the first row
			bCollection[i]->modifyBrick(k, (40 * i) + (14 + i), 12, i);
		}
		else if (i >= 6 && i < 12)
		{
			// sets up the second row
			bCollection[i]->modifyBrick(k, (40 * (i - 6)) + (14 + (i - 6)), 29, i);
		}
		else if (i >= 12 && i < 18)
		{
			// sets up the third row
			bCollection[i]->modifyBrick(k, (40 * (i - 12)) + (14 + (i - 12)), 46, i);
		}
		else if (i >= 18 && i < 24)
		{
			// sets up the fourth row
			bCollection[i]->modifyBrick(k, (40 * (i - 18)) + (14 + (i - 18)), 63, i);
		}
		else if (i >= 24)
		{
			// sets up the fifth row
			bCollection[i]->modifyBrick(k, (40 * (i - 24)) + (14 + (i - 24)), 80, i);
		}
		this->Controls->Add(bCollection[i]->brickPic);
	}
}