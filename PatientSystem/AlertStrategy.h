
#pragma once
#include "PatientAlertLevels.h"
#include "Patient.h"

class AlertStrategy {
public:
	// calculate the alert level for a patient based on their diagnosis and vitals
    virtual AlertLevel calculate(const Patient* p, const Vitals* v) const = 0;
    virtual ~AlertStrategy() = default;
};
