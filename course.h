#pragma once

#include <vector>
#include <memory>
#include <string>

class Person {
private:
	std::string surname;
	std::string firstName;
	std::string email;

public:
	Person(const std::string& surname, const std::string& firstName, const std::string& email)
		: surname(surname)
		, firstName(firstName)
		, email(email) {}

	virtual ~Person() = default;

	const std::string& getSurname() const {
		return surname;
	}

	const std::string& getFirstName() const {
		return firstName;
	}

	const std::string& getEmail() const {
		return email;
	}
};

class Lecturer : public Person {
private:
	std::string academicTitle;

public:
	Lecturer(const std::string& academicTitle,
		const std::string& surname,
		const std::string& firstName,
		const std::string& email)
		: Person(surname, firstName, email), academicTitle(academicTitle) {}

	virtual ~Lecturer() = default;

	const std::string& getAcademicTitle() const
	{
		return academicTitle;
	}
};

class Student : public Person {
private:
	std::string matriculationNumber;
	std::string university;

public:
	Student(const std::string& matriculationNumber, const std::string& university, const std::string& surname, const std::string& firstName, const std::string& email)
		: Person(surname, firstName, email), matriculationNumber(matriculationNumber), university(university) {}

	virtual ~Student() = default;

	const std::string& getMatriculationNumber() const {
		return matriculationNumber;
	}
	const std::string& getUniversity() const {
		return university;
	}
};

class Course {
private:
	std::string name;
	std::shared_ptr<Lecturer> lecturer;
	std::vector<std::shared_ptr<Person>> participants;
	static const int maxParticipants = 10;
	static const int minParticipants = 3;

public:
	Course(const std::string& name, std::shared_ptr<Lecturer> lecturer)
		: name(name), lecturer(lecturer) {};

	~Course() {
		participants.clear();
	};

	bool registerStudent(std::shared_ptr<Person> student) {
		if (participants.size() < maxParticipants) {
			// Check if the student is already registered
			if (isStudentRegistered(student->getEmail())) {
				return false;
			}
			else {
				participants.push_back(student);
				std::cout << "Student registered for the course.\n";
				return true;
			}
		}
		else {
			std::cout << "Course is fully booked. Cannot register more students.\n";
			return false;
		}
	}

	void displayParticipants() const
	{
		std::cout << "Participants in " << name << ":\n";
		if (participants.size() > 0)
		{
			for (const auto& participant : participants) {
				std::cout << participant->getFirstName() << " " << participant->getSurname() << " (" << participant->getEmail() << ")\n";
			}

		}

		if (participants.size() < minParticipants) {
			std::cout << "Course will not take place. Insufficient participants.\n";
		}
	}

	void displayCourseInfo() const
	{
		std::cout << "Course: " << name << "\n";
		std::cout << "Lecturer: " << lecturer->getAcademicTitle() << " " << lecturer->getFirstName() << " " << lecturer->getSurname() << "\n";
		std::cout << "Participants: " << participants.size() << "/" << maxParticipants << "\n";
	}

	bool isStudentRegistered(const std::string& studentEmail) const
	{
		for (const auto& participant : participants) {
			if (participant->getEmail() == studentEmail) {
				std::cout << "Student with email " << studentEmail << " is already registered for the course.\n";
				return true;
			}
		}
		return false;
	}

	size_t getParticipantsCount() const {
		return participants.size();
	}

	int getMaxParticipants() const
	{
		return maxParticipants;
	}

	const std::string& getCourseName() const
	{
		return name;
	}

	void notifyParticipants() const
	{
		std::cout << "Course " << name << " will not take place.\n";
		for (const auto& participant : participants) {
			std::cout << "Notifying participants: " << participant->getFirstName() << " " << participant->getSurname() << " (" << participant->getEmail() << ")\n";
		}
	}
};
