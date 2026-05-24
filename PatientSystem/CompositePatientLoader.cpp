#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader)
{
	// Add the loader to the vector of loaders.
    _loaders.push_back(std::move(loader));
}

void CompositePatientLoader::initialiseConnection()
{
	// initialise the connection for each loader in the composite loader using unique pointer (auto)
    for (auto& eachCompositeLoader : _loaders) {
		// initialise the connection for each loader in the composite loader
        eachCompositeLoader->initialiseConnection();
    }
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
   
}

void CompositePatientLoader::closeConnection()
{
    
}