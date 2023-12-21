#pragma once
#include "Orchid.h"
#include <chrono>

constexpr int whackTime{ 500 }; //how long whacking takes
constexpr int popUpTime{ 2000 };//how long between whackas popping up

class MyGame : public oc::OrchidApp<MyGame> {
public:
	MyGame();
	virtual void OnUpdate() override;
	void OnKeyPress(const oc::KeyPressed& e);
private:
	oc::Unit mBG{ "../Assets/Pictures/whackaBG.png", 0, 0, 1.0};
	std::vector<oc::UnitSet*> mWhackas{
		new oc::UnitSet{"../Assets/Pictures/whacka_down.png", 100, 100, 1.0},
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 300, 100, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 500, 100, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 100, 300, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 300, 300, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 500, 300, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 100, 500, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 300, 500, 1.0 },
		new oc::UnitSet{ "../Assets/Pictures/whacka_down.png", 500, 500, 1.0 } 
	};
	oc::UnitSet mPlayer{ "../Assets/Pictures/hammer.png", 100, 100, 1.0 };
	std::chrono::milliseconds mWhackLength{ std::chrono::milliseconds{whackTime} };
	std::chrono::steady_clock::time_point mUnwhack;
	std::chrono::milliseconds mPopTime{ std::chrono::milliseconds{popUpTime} };
	std::chrono::steady_clock::time_point mNextPop;
};