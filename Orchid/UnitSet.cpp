#pragma once
#include "pch.h"
#include "Unit.h"
#include "UnitSet.h"

namespace oc {
	UnitSet::UnitSet(const std::string& image, int x, int y, float scale) : mXPos(x), mYPos(y) {
		mImages.emplace_back(image, x, y, scale);
	}

	UnitSet::UnitSet(std::string&& image, int x, int y, float scale) : mXPos(x), mYPos(y) {
		mImages.emplace_back((std::move(image)), x, y, scale);
	}

	int UnitSet::GetWidth() const {
		return mImages[mState].GetWidth();
	}

	int UnitSet::GetHeight() const {
		return mImages[mState].GetHeight();
	}

	int UnitSet::GetXCoord() const {
		return mXPos;
	}

	int UnitSet::GetYCoord() const {
		return mYPos;
	}

	int UnitSet::GetState() const {
		return mState;
	}

	void UnitSet::SetCoords(int x, int y) {
		mXPos = x;
		mYPos = y;
		for (auto& item : mImages) {
			item.SetCoords(x, y);
		}
	}

	bool UnitSet::SetScale(int pos, float s) {
		if (pos >= mImages.size() || pos < 0) {
			return false;
		}
		mImages[pos].SetScale(s);
		return true;
	}

	bool UnitSet::SetState(int state) {
		if (state >= mImages.size() || state < 0) {
			return false;
		}
		mState = state;
		return true;
	}

	void UnitSet::UpdateXCoord(int amount) {
		mXPos += amount;
		for (auto& item : mImages) {
			item.UpdateXCoord(amount);
		}
	}

	void UnitSet::UpdateYCoord(int amount) {
		mYPos += amount;
		for (auto& item : mImages) {
			item.UpdateYCoord(amount);
		}
	}

	void UnitSet::JumpState(int amount) {
		mState = (mState + amount) % mImages.size(); //allows loopback!
	}

	void UnitSet::AddState(Unit& add) {
		add.SetCoords(mXPos, mYPos);
		mImages.push_back(add);
	}

	void UnitSet::InsertState(int pos, Unit& add) {
		add.SetCoords(mXPos, mYPos);
		mImages.insert(mImages.begin() + pos, add);
	}

	void UnitSet::AddState(const std::string& add) {
		mImages.emplace_back(add, mXPos, mYPos);
	}

	void UnitSet::InsertState(int pos, const std::string& add) {
		Unit added{ add, mXPos, mYPos };
		mImages.insert(mImages.begin() + pos, added);
	}

	void UnitSet::AddState(std::string&& add) {
		mImages.emplace_back(std::move(add), mXPos, mYPos);
	}

	void UnitSet::InsertState(int pos, std::string&& add) {
		Unit added{ std::move(add), mXPos, mYPos };
		mImages.insert(mImages.begin() + pos, added);
	}

	void UnitSet::RemState(int pos) {
		mImages.erase(mImages.begin() + pos);
	}

	void UnitSet::Bind() {
		mImages[mState].Bind();
	}

	Unit& UnitSet::GetUnit() {
		return mImages[mState];
	}

	bool UnitsOverlap(const UnitSet& a, const UnitSet& b) {
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