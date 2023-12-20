#pragma once
#include "utilities.h"
#include "Picture.h"

namespace oc {
	class OC_API Unit {
	public:
		Unit(const std::string& image, int x, int y, float scale=1.0);
		Unit(std::string&& image, int x, int y, float scale=1.0);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;
		void SetCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);

		void Bind(); //calls the picture's bind
	private:
		Picture mImage;
		int mXPos;
		int mYPos;
		float mScale{ 1.0 };

		template<typename T> friend class BeaverApp;
		friend OC_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	OC_API bool UnitsOverlap(const Unit& a, const Unit& b);
}