#pragma once
#include "utilities.h"
#include "Unit.h"

namespace oc {
	class OC_API UnitSet {
		//this will be used for animation-type stuff!
	public:
		UnitSet(const std::string& image, int x, int y, float scale = 1.0);
		UnitSet(std::string&& image, int x, int y, float scale = 1.0);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;
		int GetState() const;
		void SetCoords(int x, int y);
		bool SetScale(int pos, float s);
		bool SetState(int state);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
		void JumpState(int amount);

		void AddState(Unit& add);
		void InsertState(int pos, Unit& add);
		void AddState(const std::string& add);
		void InsertState(int pos, const std::string& add);
		void AddState(std::string&& add);
		void InsertState(int pos, std::string&& add);
		void RemState(int pos);

		void Bind(); //calls current state's bind
	private:
		std::vector<Unit> mImages;
		int mXPos{ 0 };
		int mYPos{ 0 };
		int mState{ 0 };

		template<typename T> friend class BeaverApp;
		Unit& GetUnit(); //gets current Unit if needed, hopefully never used

		template<typename T> friend class BeaverApp;
		friend OC_API bool UnitsOverlap(const UnitSet& a, const UnitSet& b); //same units overlap
	};

	OC_API bool UnitsOverlap(const UnitSet& a, const UnitSet& b);
}