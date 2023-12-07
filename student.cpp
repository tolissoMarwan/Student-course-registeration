#include "student.h"

Student::Student(const std::string& matriculationNumber, const std::string& university, const std::string& surname, const std::string& firstName, const std::string& email)
	: Person(surname, firstName, email), matriculationNumber(matriculationNumber), university(university) {}

const std::string& Student::getMatriculationNumber() const {
	return matriculationNumber;
}

const std::string& Student::getUniversity() const {
	return university;
}
