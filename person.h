#pragma once

#include <string>

class Person {
public:
	Person(const std::string& surname, const std::string& firstName, const std::string& email);
	virtual ~Person() = default;

	const std::string& getSurname() const;
	const std::string& getFirstName() const;
	const std::string& getEmail() const;

private:
	std::string surname;
	std::string firstName;
	std::string email;
};
