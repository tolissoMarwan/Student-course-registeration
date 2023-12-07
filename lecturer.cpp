#include "lecturer.h"

Lecturer::Lecturer(const std::string& academicTitle, const std::string& surname, const std::string& firstName, const std::string& email)
	: Person(surname, firstName, email), academicTitle(academicTitle) {}

const std::string& Lecturer::getAcademicTitle() const {
	return academicTitle;
}
