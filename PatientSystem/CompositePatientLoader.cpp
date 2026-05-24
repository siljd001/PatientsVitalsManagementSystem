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
        eachCompositeLoader->initialiseConnection();
    }
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
	// load patients from each loader in the composite loader
    for (auto& loader : _loaders) {
        loader->loadPatients(patientIn);
    }
}

void CompositePatientLoader::closeConnection()
{
	// close the connection for each loader in the composite loader
    for (auto& eachCompositeLoader : _loaders) {
        eachCompositeLoader->closeConnection();
	}
}