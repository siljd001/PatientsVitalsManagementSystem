#include "Patient.h"

class Observer {
public:
    virtual void update(Patient* p) = 0;
    virtual ~Observer() = default;
};
