#pragma once
#include <memory>
#include "AlertStrategy.h"
#include "CordycepsSt.h"
#include "KepralsSt.h"
#include "AndromedaSt.h"
#include "Patient.h"

class AlertStrategyFactory {
public:
	// create an alert strategy based on the patient's diagnosis. 
    // This is an example of the factory design pattern, and allows us to easily add new alert strategies 
    // in the future without changing the rest of the system.
    static std::unique_ptr<AlertStrategy> create(const std::string& diagnosis) {
        // create a new alert strategy based on the patient's diagnosis.

        if (diagnosis == Diagnosis::CORDYCEPS_BRAIN_INFECTION) { 
            return std::make_unique<CordycepsAlertStrategy>();
        } 

        if (diagnosis == Diagnosis::KEPRALS_SYNDROME) {
            return std::make_unique<KepralsAlertStrategy>();
        } 

        if (diagnosis == Diagnosis::ANDROMEDA_STRAIN) {
            return std::make_unique<AndromedaAlertStrategy>();
        } 

        return nullptr;
    }
};
