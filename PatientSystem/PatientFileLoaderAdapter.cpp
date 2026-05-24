#include "PatientFileLoaderAdapter.h"
#include "PatientFileLoader.h"
#include "Patient.h"

void PatientFileLoaderAdapter::initialiseConnection()
{
	// no connection to initialise for file loading
}
void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
	// create a file loader to load the patients from the file
    PatientFileLoader fileLoader;

    // Load patients from the file
    std::vector<Patient*> loadedPatients = fileLoader.loadPatientFile("patients.txt");

	// push the loaded patients into the patientIn vector
    for (Patient* p : loadedPatients) {
        patientIn.push_back(p);
    }
}
void PatientFileLoaderAdapter::closeConnection()
{
	// no connection to close for file loading
}