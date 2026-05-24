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

            // Split name "Last,First"
            std::string lastName, firstName;
            {
                std::stringstream ns(name);
                std::getline(ns, lastName, ',');
                std::getline(ns, firstName, ',');
            }

            // Parse birthday
            std::tm birthday{};
            std::istringstream bd(patientBirthday);
            bd >> std::get_time(&birthday, "%d-%m-%Y");

            // Create patient
            Patient* p = new Patient(firstName, lastName, birthday);
            p->addDiagnosis(diagnosis);

            // Parse vitals (may be empty)
			// Skips if there are no vitals, otherwise splits by ';' and then by ',' to get each vital sign
            if (!patientVitals.empty()) {

                std::stringstream vs(patientVitals);
                std::string everyVital;

                // Split by ';'
                while (std::getline(vs, everyVital, ';')) {

                    if (everyVital.empty()) continue;

                    std::stringstream ve(everyVital);
                    std::string bodyTemperature, bloodPressure, heartRate, respiratoryRate;

                    // Split by ','
                    std::getline(ve, bodyTemperature, ',');
                    std::getline(ve, bloodPressure, ',');
                    std::getline(ve, heartRate, ',');
                    std::getline(ve, respiratoryRate, ',');

					// Vitals are in the format: bodyTemperature,bloodPressure,heartRate,respiratoryRate
                    float bt = std::stof(bodyTemperature);
                    int bp = std::stoi(bloodPressure);
                    int hr = std::stoi(heartRate);
                    int rr = std::stoi(respiratoryRate);

					// create a new vitals record and add it to the patient
                    Vitals* v = new Vitals(bt, bp, hr, rr);
                    p->addVitals(v);
                }
            }
            
			// add the patient to the list of patients
            patients.push_back(p);
        }
    }

    return patients;
}
