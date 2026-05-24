#include "PatientManagementSystem.h"

#include <iostream>
#include <map>
#include <tuple>

#include "Patient.h"
#include "PatientDatabaseLoader.h"
#include "Vitals.h"

#include "CompositePatientLoader.h"

#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"
#include "PatientFileLoaderAdapter.h"
using namespace std;


PatientManagementSystem::PatientManagementSystem()
{
	// create a composite loader to load patients from multiple sources. 
	// This is an example of the composite design pattern, and allows us to easily 
	// add new patient loaders in the future without changing the rest of the system.
	auto composite = std::make_unique<CompositePatientLoader>();

	// Add database loader
	composite->addLoader(std::make_unique<PatientDatabaseLoader>());

	// Add file loader (adapter)
	composite->addLoader(std::make_unique<PatientFileLoaderAdapter>());

	// Assign composite to the system loader
	_patientDatabaseLoader = std::move(composite);

	// The constructor's design changed due to the new File loader + DB loader combined using Composite pattern. 
	// The constructor is now responsible for creating the composite loader and adding the individual loaders to it, 
	// as well as initialising the notification systems. This design allows for greater flexibility and extensibility in the future, 
	// as new loaders can be added to the composite without needing to modify the rest of the system.

	// Initialise all loaders inside composite
	_patientDatabaseLoader->initialiseConnection();

	// Initialise notification systems
	_hospitalAlertSystem = std::make_unique<HospitalAlertSystemFacade>();
	_gpNotificationSystem = std::make_unique<GPNotificationSystemFacade>();
}

PatientManagementSystem::~PatientManagementSystem()
{
	_patientDatabaseLoader->closeConnection();

	// clear patient memory
	for (Patient* p : _patients) {
		delete p;
	}
}

void PatientManagementSystem::init()
{
	_patientDatabaseLoader->loadPatients(_patients);
	for (Patient* p : _patients) {
		_patientLookup[p->uid()] = p;
	}

	for (Patient* p : _patients) {
		// TODO: do any processing you need here
	}
}

void PatientManagementSystem::run()
{
	printWelcomeMessage();

	bool running = true;
	while (running) {
		printMainMenu();
		int option = 0;
		cin >> option;

		// handle basic errors
		if (cin.bad()) {
			cin.clear();
			cin.ignore();
			continue;
		}

		// switch based on the selected option
		switch (option) {
		case 1:
			printPatients();
			break;
		case 2:
			addVitalsRecord();
			break;
		case 3:
			running = false;
			break;
		}
	}
}

void PatientManagementSystem::addVitalsRecord()
{
	cout << "Patients" << endl;
	printPatients();
	cout << endl;
	cout << "Enter the patient ID to declare vitals for > ";
	
	string pid { "" };
	cin >> pid;
	if (_patientLookup.count(pid)) {
		float bodyTemperature;
		int bloodPressure;
		int heartRate;
		int respitoryRate;

		cout << "enter body temperature: ";
		cin >> bodyTemperature;
		cout << "enter blood pressure: ";
		cin >> bloodPressure;
		cout << "enter heart rate: ";
		cin >> heartRate;
		cout << "enter respitory rate: ";
		cin >> respitoryRate;

		Vitals* v = new Vitals(bodyTemperature, bloodPressure, heartRate, respitoryRate);
		_patientLookup[pid]->addVitals(v);
	}
	else {
		cout << "Patient not found" << endl;
	}
}

void PatientManagementSystem::printWelcomeMessage() const
{
	cout << "WELCOME TO HEALTHCO 3000" << endl;
	cout << "------------------------" << endl;
}

void PatientManagementSystem::printMainMenu() const
{
	cout << endl << "Select an option:" << endl;
	cout << "1. List patients" << endl;
	cout << "2. Add vitals record" << endl;
	cout << "3. Quit" << endl;
	cout << "> ";
}

void PatientManagementSystem::printPatients() const
{
	for (Patient* p : _patients) {
		std::cout << *p << std::endl;
	}
}
