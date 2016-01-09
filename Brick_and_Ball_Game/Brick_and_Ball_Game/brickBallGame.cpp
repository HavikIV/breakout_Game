#include "brickBallGame.h"
#include "Brick.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace Brick_and_Ball_Game;
using namespace brick;
using namespace std;

// loads up the starting level
// sets up all of the bricks, the ball and the paddle
System::Void brickBallGame::brickBallGame_Load(System::Object^  sender, System::EventArgs^  e)
{
	setupBricks(4);
	this->Controls->Add(gPaddle.paddlePic);
	this->Controls->Add(gBall.ballPic);
	this->Cursor->Hide();
	launchBall = true;
}

// function used to launch the ball, if it needs to be
// this will also start the timer to run the game
System::Void brickBallGame::brickBallGame_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (launchBall && lifes != -1)
	{
		gBall.setSpeedY(-5);
		gBall.setSpeedX(-5);
		launchBall = false;
		// run the timer
		gAnimation->Start();
	}
}

// this moves the ball every time it is called within the timer
System::Void brickBallGame::runGame()
{
	gBall.moveBall();
}

// this runs all of the collision check functions
// these are the Bounce functions
System::Void brickBallGame::collisionCheck()
{
	if (launchBall == false)
	{
		formBounce();
		brickBounce();
		paddleBounce();
	}
}

// this function handles the movement of the paddle as the cursor moves within the form
System::Void brickBallGame::brickBallGame_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (lifes != -1)
	{
		if (e->X < this->Width - 55)
		{
			if (launchBall)
			{
				// while the ball hasn't been launched yet, it needs to stay with the paddle
				gBall.setLocX(e->X + 20);
			}
			gPaddle.movePaddle(e->X);
		}
	}
}

// this timer is essential to animating the game and actually running it
System::Void brickBallGame::gAnimation_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// updates the form to make it be animated.
	collisionCheck();
	runGame();
	checkLifeLoss();
}

// This checks if the ball has gone below the paddle
// and it will prepare the ball to relaunched
// at the price of a life from the player.
// It will also calls the gameOver()
// this function will also effectively end the game
System::Void brickBallGame::checkLifeLoss()
{
	if (gBall.ballPic->Location.Y >= 460 && lifes != -1)
	{
		gAnimation->Stop();
		lifes -= 1;
		launchBall = true;
		if (lifes > -1)
		{
			gBall.ballPic->Location = System::Drawing::Point(gPaddle.paddlePic->Location.X + 20, 446);
		}
	}
	gameOver();
	if (lifes != -1)
	{
		lblLifes->Text = "" + lifes;
	}
}

// Checks if the player lost all of his/her lives
// if the player has lost them, this will display GAME OVER!
// on the screen to let the player know
System::Void brickBallGame::gameOver()
{
	if (lifes == -1)
	{
		Label^ gOver = gcnew System::Windows::Forms::Label();
		gOver->Text = "GAME OVER!";
		gOver->Location = System::Drawing::Point(200, 200);
		gOver->Size = System::Drawing::Size(300, 300);
		gOver->Font = gcnew System::Drawing::Font(gOver->Font->FontFamily, 50);
		this->Controls->Add(gOver);
	}
}

// this checks to see if the ball hit any of the 3 sides of
// the form and bounces the ball in the opposite direction
System::Void brickBallGame::formBounce()
{
	if (gBall.ballPic->Location.X + 4 >= this->Width - 15) // bounce off the right edge of the form
	{
		gBall.setSpeedX(-5);
	}
	else if (gBall.ballPic->Location.X <= 0) // bounce off the left edge of the form
	{
		gBall.setSpeedX(5);
	}
	else if (gBall.ballPic->Location.Y <= 0) // bounce off the top edge of the form
	{
		gBall.setSpeedY(5);
	}
}

// this check to see if the ball hits the top of the paddle
// and it will bounce  it in the opposite direction on the Y-axis
System::Void brickBallGame::paddleBounce()
{
	// check if the ball hit the paddle
	if (gBall.ballPic->Location.Y < 450)
	{
		if (gBall.ballPic->Location.Y + 4 >= gPaddle.paddlePic->Location.Y
			&& (gBall.ballPic->Location.X >= gPaddle.paddlePic->Location.X
				&& gBall.ballPic->Location.X + 4 <= gPaddle.paddlePic->Location.X + 40)) // bounce off the top edge of the paddle, needs to check if its within the paddles x range
		{
			gBall.setSpeedY(-5);
		}
	}
}

// checks to see if the ball hit any of the bricks within the bCollection array
// this function also handles bouncing the right direction if it did hit a brick
// have to make sure that it only counts the collision if its within the bricks surface area
// surface area for top or bottom collision = (bCollection[i]->brickPic->Location.X <= ball <= bCollection[i]->brickPic->Location.X + 40) && top or bottom
// surface area for left or right collision = (bCollection[i]->brickPic->Location.Y <= ball <= bCollection[i]->brickPic->Location.Y + 16) && left or right
System::Void brickBallGame::brickBounce()
{
	for (int i = 0; i < 100; i++)
	{
		if (bCollection[i]->getHealth() != 0)
		{
			if (gBall.ballPic->Location.Y + gBall.getSpeedY() <= bCollection[i]->brickPic->Location.Y + 16
				&& gBall.ballPic->Location.Y + 4 + gBall.getSpeedY() >= bCollection[i]->brickPic->Location.Y
				&& !(gBall.ballPic->Location.X + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
					&& gBall.ballPic->Location.X + 4 + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40))
			{
				if (gBall.ballPic->Location.X + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40
					&& gBall.ballPic->Location.X + 4 > bCollection[i]->brickPic->Location.X + 40) // bounce off the right edge
				{
					gBall.ballPic->Location = System::Drawing::Point(bCollection[i]->brickPic->Location.X + 40, gBall.ballPic->Location.Y);
					gBall.setSpeedX(5);
					bCollection[i]->decreaseHealth();
					if (bCollection[i]->getHealth() == 0)
					{
						score += 100;
					}
					else
					{
						score += 50;
					}
					break;
				}
				else if (gBall.ballPic->Location.X + 4 + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
					&& gBall.ballPic->Location.X < bCollection[i]->brickPic->Location.X) // bounce off the left edge
				{
					gBall.ballPic->Location = System::Drawing::Point(bCollection[i]->brickPic->Location.X - 4, gBall.ballPic->Location.Y);
					gBall.setSpeedX(-5);
					bCollection[i]->decreaseHealth();
					if (bCollection[i]->getHealth() == 0)
					{
						score += 100;
					}
					else
					{
						score += 50;
					}
					break;
				}
			}
			else if (gBall.ballPic->Location.X + gBall.getSpeedX() >= bCollection[i]->brickPic->Location.X
				&& gBall.ballPic->Location.X + 4 + gBall.getSpeedX() <= bCollection[i]->brickPic->Location.X + 40)
			{
				if (gBall.ballPic->Location.Y + 4 + gBall.getSpeedY() >= bCollection[i]->brickPic->Location.Y
					&& gBall.ballPic->Location.Y < bCollection[i]->brickPic->Location.Y) // bounce off top
				{
					gBall.ballPic->Location = System::Drawing::Point(gBall.ballPic->Location.X, bCollection[i]->brickPic->Location.Y - 4);
					gBall.setSpeedY(-5);
					bCollection[i]->decreaseHealth();
					if (bCollection[i]->getHealth() == 0)
					{
						score += 100;
					}
					else
					{
						score += 50;
					}
					break;
				}
				else if (gBall.ballPic->Location.Y + gBall.getSpeedY() <= bCollection[i]->brickPic->Location.Y + 16
					&& gBall.ballPic->Location.Y + 4 > bCollection[i]->brickPic->Location.Y + 16) // bounce off bottom
				{
					gBall.ballPic->Location = System::Drawing::Point(gBall.ballPic->Location.X, bCollection[i]->brickPic->Location.Y + 16);
					gBall.setSpeedY(5);
					bCollection[i]->decreaseHealth();
					if (bCollection[i]->getHealth() == 0)
					{
						score += 100;
					}
					else
					{
						score += 50;
					}
					break;
				}
			}
		}
	}
	lblScore->Text = "" + score;
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
	for (int i = 0; i < 100; i++)
	{
		// pick k randomly from healthArray for the bricks health
		k = healthArray[rand() % 3]; // picks a number from 0 to 2 to select one value from the healthArray
		bCollection[i] = gcnew brickBox; // adds a new brick to the collection, its created with the default constructor
		// modifies the created brick and puts it at the right location
		if (i < 15)
		{
			// sets up the first row
			bCollection[i]->modifyBrick(k, (40 * i) + (14 + i), 22, i);
		}
		else if (i >= 15 && i < 30)
		{
			// sets up the second row
			bCollection[i]->modifyBrick(k, (40 * (i - 15)) + (14 + (i - 15)), 39, i);
		}
		else if (i >= 30 && i < 45)
		{
			// sets up the third row
			bCollection[i]->modifyBrick(k, (40 * (i - 30)) + (14 + (i - 30)), 56, i);
		}
		else if (i >= 45 && i < 60)
		{
			// sets up the fourth row
			bCollection[i]->modifyBrick(k, (40 * (i - 45)) + (14 + (i - 45)), 73, i);
		}
		else if (i >= 60 && i < 75)
		{
			// sets up the fifth row
			bCollection[i]->modifyBrick(k, (40 * (i - 60)) + (14 + (i - 60)), 90, i);
		}
		else if (i >= 75 && i < 90)
		{
			// sets up the sixth row
			bCollection[i]->modifyBrick(k, (40 * (i - 75)) + (14 + (i - 75)), 107, i);
		}
		else if (i >= 90)
		{
			// sets up the seventh row
			bCollection[i]->modifyBrick(k, (40 * (i - 90)) + (14 + (i - 90)), 124, i);
		}
		this->Controls->Add(bCollection[i]->brickPic);
	}
}