#include "HospitalAlertSystemFacade.h"
#include "Patient.h"

#include <iostream>


void HospitalAlertSystemFacade::update(Patient* p)
{
    if (p->alertLevel() == AlertLevel::Red) {
        std::cout << "\nThis is an alert to the hospital:\n";
        std::cout << "Patient: " << p->humanReadableID() << " has a critical alert level\n";
    }
}
