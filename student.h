#pragma once

#include "person.h"

class Student : public Person {

public:
	Student(const std::string& matriculationNumber, const std::string& university, const std::string& surname, const std::string& firstName, const std::string& email);

	const std::string& getMatriculationNumber() const;
	const std::string& getUniversity() const;

private:
	std::string matriculationNumber;
	std::string university;
};