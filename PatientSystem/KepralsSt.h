#include "AlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"
class KepralsAlertStrategy : public AlertStrategy {
public:
    AlertLevel calculate(const Patient* p, const Vitals* v) const override {
		// For patients with a diagnosis of "Kepral's Syndrome", 
        // the alert level is determined by the heart rate (HR) from their vitals, with different thresholds for children and adults.
        int hr = v->HR();
        int age = p->age();

		// For patients under 12 years old, a heart rate above 120 is considered red. For patients 12 years old and above, a heart rate above 100 is considered red.
        if (age < 12 && hr > 120) return AlertLevel::Red;
        if (age >= 12 && hr > 100) return AlertLevel::Red;

        return AlertLevel::Green;
    }
};
