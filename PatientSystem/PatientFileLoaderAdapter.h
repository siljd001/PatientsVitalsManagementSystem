#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader {
private:
    PatientFileLoader _fileLoader;
public:
    void initialiseConnection() override;
    void loadPatients(std::vector<Patient*>& patientIn) override;
    void closeConnection() override;
};