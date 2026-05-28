#include "PatientAlertLevels.h"
#include "AlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
class CordycepsAlertStrategy : public AlertStrategy {
public:
    AlertLevel calculate(const Patient* p, const Vitals* v) const override {
		// For patients with a diagnosis of "Cordyceps", the alert level is determined solely by the respiratory rate (RR) from their vitals.
        int rr = v->RR();

        if (rr > 40) return AlertLevel::Red;
        if (rr > 30) return AlertLevel::Orange;
        if (rr > 20) return AlertLevel::Yellow;
        return AlertLevel::Green;
    }
};
