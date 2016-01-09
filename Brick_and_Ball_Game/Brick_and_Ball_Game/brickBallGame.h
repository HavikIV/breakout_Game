#pragma once
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"

namespace Brick_and_Ball_Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace brick;
	using namespace paddle;
	using namespace ball;

	/// <summary>
	/// Summary for brickBallGame
	/// </summary>
	public ref class brickBallGame : public System::Windows::Forms::Form
	{
	public:
		cli::array<brickBox^> ^ bCollection; // an empty array of brickBoxes?
		paddleBox gPaddle;
		ballBox gBall;
	private: System::Windows::Forms::Label^  lblScore;
	private: System::Windows::Forms::Label^  lblLifes;
	public:
	private: System::Windows::Forms::Timer^  gAnimation;

	public:

	public:
		brickBallGame(void)
		{
			bCollection = gcnew cli::array<brickBox^>(100);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~brickBallGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gAnimation = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->lblLifes = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// gAnimation
			// 
			this->gAnimation->Interval = 1;
			this->gAnimation->Tick += gcnew System::EventHandler(this, &brickBallGame::gAnimation_Tick);
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Location = System::Drawing::Point(592, 9);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(0, 13);
			this->lblScore->TabIndex = 0;
			// 
			// lblLifes
			// 
			this->lblLifes->AutoSize = true;
			this->lblLifes->Location = System::Drawing::Point(12, 9);
			this->lblLifes->Name = L"lblLifes";
			this->lblLifes->Size = System::Drawing::Size(0, 13);
			this->lblLifes->TabIndex = 1;
			// 
			// brickBallGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 474);
			this->Controls->Add(this->lblLifes);
			this->Controls->Add(this->lblScore);
			this->Name = L"brickBallGame";
			this->Text = L"brickBallGame";
			this->Load += gcnew System::EventHandler(this, &brickBallGame::brickBallGame_Load);
			this->Click += gcnew System::EventHandler(this, &brickBallGame::brickBallGame_Click);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &brickBallGame::brickBallGame_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void brickBallGame_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void brickBallGame_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void brickBallGame_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void gAnimation_Tick(System::Object^  sender, System::EventArgs^  e);
		System::Void setupBricks(int level); //function to set up the bricks based on level		
		System::Void runGame(); // runs the game, handles moving the ball, basically keeps the ball moving with the timers help		
		System::Void collisionCheck(); // runs all of the collision checks
		System::Void formBounce(); // see if the ball needs to bounce from the walls of the form
		System::Void brickBounce(); // see if the ball hit any of the balls and handles the resulting bouncing
		System::Void paddleBounce(); // see if the ball hit the paddle and bounces it if it did
		System::Void checkLifeLoss(); // checks to see if the player loses a life, this occurs when the ball is dropped through the bottom
		System::Void gameOver(); // if the player loses all of his/her lives, ends the game.
		bool launchBall = false; // whether or not the ball needs to be launched
		int lifes = 3;	// the number of lives the player has remaining before game over, it doesn't count the starting life
		int score = 0; // variable to keep track of the score

};
}
