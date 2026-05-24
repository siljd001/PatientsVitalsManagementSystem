#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include <vector>
#include <memory>

class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
    // loaders and database connections soon :)

private:
    std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> _loaders;
};