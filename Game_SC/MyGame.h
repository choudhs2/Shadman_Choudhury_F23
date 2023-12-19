#pragma once
#include "Orchid.h"

class MyGame : public oc::OrchidApp<MyGame> {
public:
	MyGame();
	virtual void OnUpdate() override;
	void OnKeyPress(const oc::KeyPressed& e);
private:
	oc::Picture mPic{ "../Assets/Pictures/test.png" };
	oc::Unit mUnit{"../Assets/Pictures/test.png", 100, 500, 0.5};
	//int mXPos{ 100 };
	//int mYPos{ 200 };
};