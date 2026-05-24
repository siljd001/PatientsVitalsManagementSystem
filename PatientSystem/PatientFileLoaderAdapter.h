#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {
private:
    PatientFileLoader _fileLoader;
public:
    
};