#include "Orchid.h"
#include <iostream>

class MyGame : public oc::OrchidApp<MyGame> {
public:
	virtual void OnUpdate() override {
		//std::cout << "Orchid Running!" << std::endl;
	}
};

OC_APPLICATION_START(MyGame);

