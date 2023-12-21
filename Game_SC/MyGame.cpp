#include "MyGame.h"
#include <stdlib.h>
#include <time.h>

MyGame::MyGame() {
	SetKeyPressedCallback([this](const oc::KeyPressed& e) {OnKeyPress(e); });
	for (auto& item : mWhackas) {
		item->AddState(std::string("../Assets/Pictures/whacka.png"));
	}
	mPlayer.AddState("../Assets/Pictures/hammer_whack.png");
	mNextPop = std::chrono::steady_clock::now() + mPopTime;
	srand(time(NULL));
}

void MyGame::OnUpdate() {
	//DrawScaled(mXPos, mYPos, 0.5, mPic);
	Draw(mBG);
	if (mNextPop <= std::chrono::steady_clock::now()) {
		bool allPopped = true; //for an error case!
		for (auto& item : mWhackas) {
			allPopped = allPopped && (item->GetState() == 1);
			if (!allPopped) { break; }
		}
		if(!allPopped) { //error case, so it doesn't freeze when all moles have popped up without being hit
			//time to add another mole!
			int popPos = rand() % 9;
			while (mWhackas[popPos]->GetState() == 1) { //ensure it is a new mole that popped up
				popPos = rand() % 9;
			}
			mWhackas[popPos]->SetState(1); //popped up mole!
		}
		mNextPop = std::chrono::steady_clock::now() + mPopTime;
	}
	if (mPlayer.GetState() == 1) {
		for (auto& item : mWhackas) {
			if (item->GetState() == 1 && UnitsOverlap(*item, mPlayer)) {
				item->SetState(0);
			}
		}
		if (std::chrono::steady_clock::now() >= mUnwhack) {
			//we have finished the amount of time we stay whacked
			mPlayer.SetState(0);
		}
	}
	Draw(mPlayer);
	for (auto& item : mWhackas) {
		Draw(*item);
	}
}

void MyGame::OnKeyPress(const oc::KeyPressed& e) {
	if (e.GetKeyCode() == ORCHID_KEY_RIGHT && mPlayer.GetXCoord() != 500 && mPlayer.GetState() != 1) {
		mPlayer.UpdateXCoord(200);
	}
	else if (e.GetKeyCode() == ORCHID_KEY_LEFT && mPlayer.GetXCoord() != 100 && mPlayer.GetState() != 1) {
		mPlayer.UpdateXCoord(-200);
	}
	else if (e.GetKeyCode() == ORCHID_KEY_UP && mPlayer.GetYCoord() != 500 && mPlayer.GetState() != 1) {
		mPlayer.UpdateYCoord(200);
	}
	else if (e.GetKeyCode() == ORCHID_KEY_DOWN && mPlayer.GetYCoord() != 100 && mPlayer.GetState() != 1) {
		mPlayer.UpdateYCoord(-200);
	}
	else if (e.GetKeyCode() == ORCHID_KEY_SPACE) {
		mPlayer.SetState(1);
		mUnwhack = std::chrono::steady_clock::now() + mWhackLength;
		
	}
}


