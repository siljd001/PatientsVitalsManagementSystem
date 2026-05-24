#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader)
{
	// Add the loader to the vector of loaders.
    _loaders.push_back(std::move(loader));
}

void CompositePatientLoader::initialiseConnection()
{

}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
   
}

void CompositePatientLoader::closeConnection()
{
    
}