#include <iostream>
#include <vector>
#include <algorithm>

#include "course.h"

int getMenuChoice() {
	int choice;
	std::cout << "\nEnter your choice: ";
	std::cin >> choice;

	while (std::cin.fail()) {
		// If the input is not an integer
		std::cin.clear(); // clear input buffer to restore cin to a usable state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
		std::cout << "Invalid input. Please enter a number!\n";
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
	}

	return choice;
}

int getCourseChoice() {
	int choice;
	std::cout << "\nEnter the number of the course: ";
	std::cin >> choice;

	while (std::cin.fail()) {
		// If the input is not an integer
		std::cin.clear(); // clear input buffer to restore cin to a usable state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
		std::cout << "Invalid input. Please enter a number!\n";
		std::cout << "Enter the number of the course: ";
		std::cin >> choice;
	}

	return choice;
}

void displayCourseMenu() {
	std::cout << "\nAvailable Courses:\n";
	std::cout << "1. Programming\n";
	std::cout << "2. Databases\n";
	std::cout << "3. Software Engineering\n";
}

int main()
{
	std::vector<std::shared_ptr<Course>> courses;
	std::vector<std::shared_ptr<Person>> students;

	// Creating Lecturers
	auto lecturer1 = std::make_shared<Lecturer>("Dr.", "Smith", "John", "smith@example.com");
	auto lecturer2 = std::make_shared<Lecturer>("Prof.", "Johnson", "Alice", "johnson@example.com");
	auto lecturer3 = std::make_shared<Lecturer>("Dr.", "Miller", "Robert", "miller@example.com");

	// Creating Courses
	auto course1 = std::make_shared<Course>("Programming", lecturer1);
	auto course2 = std::make_shared<Course>("Databases", lecturer2);
	auto course3 = std::make_shared<Course>("Software Engineering", lecturer3);

	courses.push_back(course1);
	courses.push_back(course2);
	courses.push_back(course3);

	// Menu
	int choice;
	do
	{
		std::cout << "\nMenu:\n";
		std::cout << "1. Register for a course\n";
		std::cout << "2. Display participants for a course\n";
		std::cout << "3. Display courses not fully booked\n";
		std::cout << "4. End program\n";

		choice = getMenuChoice();

		switch (choice) {
		case 1: {
			// Registration for a course
			std::string matriculationNumber, university, surname, firstName, email, courseName;
			std::cout << "Enter matriculation number: ";
			std::cin >> matriculationNumber;
			std::cout << "Enter university: ";
			std::cin >> university;
			std::cout << "Enter surname: ";
			std::cin >> surname;
			std::cout << "Enter first name: ";
			std::cin >> firstName;
			std::cout << "Enter email: ";
			std::cin >> email;

			auto student = std::make_shared<Student>(matriculationNumber, university, surname, firstName, email);
			bool isRegistered = false;

			int courseNumber;
			displayCourseMenu();
			courseNumber = getCourseChoice();

			bool courseFound = false;
			switch (courseNumber)
			{
			case 1:
				courseName = "Programming";
				courseFound = true;
				break;
			case 2:
				courseName = "Databases";
				courseFound = true;
				break;
			case 3:
				courseName = "Software Engineering";
				courseFound = true;
				break;
			default:
				std::cout << "Course not found.\n";
				break;
			}

			if (courseFound)
			{
				auto it = std::find_if(courses.begin(), courses.end(), [&courseName](const std::shared_ptr<Course>& c) {
					return c->getCourseName() == courseName;
					});

				if (it != courses.end()) {
					if ((*it)->registerStudent(student))
					{
						students.push_back(student);
					}
				}
			}
			break;
		}
		case 2: {
			// Display participants for a course
			std::string courseName;
			int courseNumber;
			displayCourseMenu();
			courseNumber = getCourseChoice();

			bool courseFound = false;
			switch (courseNumber)
			{
			case 1:
				courseName = "Programming";
				courseFound = true;
				break;
			case 2:
				courseName = "Databases";
				courseFound = true;
				break;
			case 3:
				courseName = "Software Engineering";
				courseFound = true;
				break;
			default:
				std::cout << "Course not found.\n";
				break;
			}

			if (courseFound)
			{
				auto it = std::find_if(courses.begin(), courses.end(), [&courseName](const std::shared_ptr<Course>& c) {
					return c->getCourseName() == courseName;
					});

				(*it)->displayCourseInfo();
				(*it)->displayParticipants();
			}
			break;
		}
		case 3: {
			// Display courses not fully booked
			for (const auto& course : courses) {
				int freePlaces = course->getMaxParticipants() - static_cast<int>(course->getParticipantsCount());
				if (course->getParticipantsCount() < course->getMaxParticipants()) {
					course->displayCourseInfo();
					std::cout << "Free places: " << freePlaces << "\n";
				}
				else
				{
					std::cout << "course " << course->getCourseName() << " is fully booked!\n";
				}
			}
			break;
		}
		case 4:
			std::cout << "Ending program.\n\n";
			for (const auto& course : courses)
			{
				course->notifyParticipants();
			}
			return 0;
		default:
			std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
		}
	} while (choice != 4);

	return 0;
}
