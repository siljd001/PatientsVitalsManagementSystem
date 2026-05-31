#pragma once

#include "Patient.h"
#include "Observer.h"

class HospitalAlertSystemFacade : public Observer
{
public:
	void update(Patient* p) override;
};

