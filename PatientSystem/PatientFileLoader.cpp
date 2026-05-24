#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
    vector<Patient*> patients{};

    std::ifstream inFile(file);
	// check if the file was opened successfully
    if (inFile.is_open()) {
        std::string line;
		// read the file line by line
        while (std::getline(inFile, line)) {

            // checks if line is empty if it is continue
            if (line.empty()) continue;

            // Split by '|'
            std::stringstream ss(line);
            std::string patientId, name, patientBirthday, diagnosis, patientVitals;

			// the format analysed is: patientId, name, birthday, diagnosis, vitals
            std::getline(ss, patientId, '|');
            std::getline(ss, name, '|');
            std::getline(ss, patientBirthday, '|');
            std::getline(ss, diagnosis, '|');
            std::getline(ss, patientVitals, '|');
        }
    }

    return patients;
}
