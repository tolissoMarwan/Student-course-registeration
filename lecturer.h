#pragma once

#include "person.h"

class Lecturer : public Person {
public:
	Lecturer(const std::string& academicTitle, const std::string& surname, const std::string& firstName, const std::string& email);

	const std::string& getAcademicTitle() const;

private:
	std::string academicTitle;
};
