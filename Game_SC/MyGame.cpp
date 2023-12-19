#include "MyGame.h"

MyGame::MyGame() {
	SetKeyPressedCallback([this](const oc::KeyPressed& e) {OnKeyPress(e); });
}

void MyGame::OnUpdate() {
	//DrawScaled(mXPos, mYPos, 0.5, mPic);
	Draw(mUnit);
}

void MyGame::OnKeyPress(const oc::KeyPressed& e) {
	if (e.GetKeyCode() == ORCHID_KEY_RIGHT) {
		//mXPos += 50;
		mUnit.UpdateXCoord(50);
	}
	else if (e.GetKeyCode() == ORCHID_KEY_LEFT) {
		//mXPos -= 50;
		mUnit.UpdateXCoord(-50);
	}
}


