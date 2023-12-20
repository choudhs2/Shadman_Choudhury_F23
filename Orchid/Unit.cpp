#include "pch.h"
#include "Unit.h"
#include "Picture.h"

namespace oc {
	Unit::Unit(const std::string& image, int x, int y, float scale) : 
		mImage(image), mXPos(x), mYPos(y), mScale(scale) {}

	Unit::Unit(std::string&& image, int x, int y, float scale) :
		mImage(std::move(image)), mXPos(x), mYPos(y), mScale(scale) {}

	int Unit::GetWidth() const {
		return mImage.GetWidth() * mScale; 
	}

	int Unit::GetHeight() const {
		return mImage.GetHeight() * mScale;
	}

	int Unit::GetXCoord() const {
		return mXPos;
	}

	int Unit::GetYCoord() const {
		return mYPos;
	}

	void Unit::SetCoords(int x, int y) {
		mXPos = x;
		mYPos = y;
	}

	void Unit::UpdateXCoord(int amount) {
		mXPos += amount;
	}

	void Unit::UpdateYCoord(int amount) {
		mYPos += amount;
	}

	bool UnitsOverlap(const Unit& a, const Unit& b) {
		int left_a{ a.mXPos };
		int right_a{ a.mXPos + a.GetWidth() }; //automatically uses scaled height/width!
		int left_b{ b.mXPos };
		int right_b{ b.mXPos + b.GetWidth() };

		bool x_intersection{ (left_a <= left_b && left_b <= right_a) || (left_b <= left_a && left_a <= right_b) };

		int bot_a{ a.mYPos };
		int top_a{ a.mYPos + a.GetHeight() };
		int bot_b{ b.mYPos };
		int top_b{ b.mYPos + b.GetHeight() };

		bool y_intersection{ (bot_a <= bot_b && bot_b <= top_a) || (bot_b <= bot_a && bot_a <= top_b) };

		return x_intersection && y_intersection;
	}

}