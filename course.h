#pragma once

#include "person.h"
#include <vector>
#include <memory>

class Lecturer;

class Course {
public:
	Course(const std::string& name, std::shared_ptr<Lecturer> lecturer);
	~Course();

	bool registerStudent(std::shared_ptr<Person> student);
	void displayParticipants() const;
	void displayCourseInfo() const;
	bool isStudentRegistered(const std::string& studentEmail) const;

	size_t getParticipantsCount() const;
	int getMaxParticipants() const;
	const std::string& getCourseName() const;
	void notifyParticipants() const;

private:
	std::string name;
	std::shared_ptr<Lecturer> lecturer;
	std::vector<std::shared_ptr<Person>> participants;
	static const int maxParticipants;
	static const int minParticipants;
};
