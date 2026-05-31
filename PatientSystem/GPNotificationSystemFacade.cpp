#include "GPNotificationSystemFacade.h"
#include "Patient.h"
#include <iostream>


void GPNotificationSystemFacade::update(Patient* p)
{
	// This is a simple implementation of the GP notification system. 
    // In a real system, this would likely involve sending an email or SMS to the GP,
    // or updating a dashboard that the GP can access. 

    if (p->alertLevel() > AlertLevel::Orange) {
        std::cout << "\nThis is a notification to the GPs:\n";
        std::cout << "Patient: " << p->humanReadableID() << " should be followed up\n";
    }
}