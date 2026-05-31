#pragma once

#include "Patient.h"
#include "Observer.h"

class GPNotificationSystemFacade: public Observer {
public:
	void update(Patient* p) override;
};

