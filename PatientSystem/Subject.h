#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers(Patient* p) = 0;
    virtual ~Subject() = default;
};
