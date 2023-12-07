#include "Person.h"

Person::Person(const std::string& surname, const std::string& firstName, const std::string& email)
	: surname(surname)
	, firstName(firstName)
	, email(email) {}

const std::string& Person::getSurname() const {
	return surname;
}

const std::string& Person::getFirstName() const {
	return firstName;
}

const std::string& Person::getEmail() const {
	return email;
}
