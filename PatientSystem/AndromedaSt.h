#pragma once
#include "AlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
class AndromedaAlertStrategy : public AlertStrategy {
public:
    AlertLevel calculate(const Patient* p, const Vitals* v) const override {
		// For patients with a diagnosis of "Andromeda Strain", 
        // the alert level is determined by the blood pressure (BP) from their vitals, with specific thresholds for each alert level.
        int bp = v->BP();

		// For patients with a diagnosis of "Andromeda Strain", the alert level is determined by the blood pressure (BP) from their vitals, 
        // with specific thresholds for each alert level.
        if (bp > 140) return AlertLevel::Red;
        if (bp > 130) return AlertLevel::Orange;
        if (bp > 110) return AlertLevel::Yellow;

        return AlertLevel::Green;
    }
};
