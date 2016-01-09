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
		//cli::array<paddleBox^>^ gPaddle;
		paddleBox gPaddle;
	private: System::Windows::Forms::Timer^  gAnimation;





	public:

	public:
		ballBox gBall;
		brickBallGame(void)
		{
			bCollection = gcnew cli::array<brickBox^>(30);
			//gPaddle = gcnew cli::array<paddleBox^>(1);
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
			this->SuspendLayout();
			// 
			// gAnimation
			// 
			this->gAnimation->Interval = 1;
			this->gAnimation->Tick += gcnew System::EventHandler(this, &brickBallGame::gAnimation_Tick);
			// 
			// brickBallGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"brickBallGame";
			this->Text = L"brickBallGame";
			this->Load += gcnew System::EventHandler(this, &brickBallGame::brickBallGame_Load);
			this->Click += gcnew System::EventHandler(this, &brickBallGame::brickBallGame_Click);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &brickBallGame::brickBallGame_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void brickBallGame_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void brickBallGame_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void setupBricks(int level); //function to set up the bricks based on level
	private: System::Void brickBallGame_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void runGame(); // runs the game, handles moving the ball, bascially keeps the ball moving
	private: bool launchBall = false;
	private: System::Void gAnimation_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void collisionCheck();
};
}
