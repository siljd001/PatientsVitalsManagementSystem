#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include <vector>
#include <memory>

class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
	// Add a loader to the composite loader. The composite loader will take ownership of the loader and will be responsible for deleting it.
    void addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader);

	// Inherit from AbstractPatientDatabaseLoader
    void initialiseConnection() override;
    void loadPatients(std::vector<Patient*>& patientIn) override;
    void closeConnection() override;

private:
    std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> _loaders;
};