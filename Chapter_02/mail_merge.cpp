#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string ordinalSuffix(int day)
{
	if (day % 100 >= 11 && day % 100 <= 13)
	{
		return "th";
	}

	switch (day % 10)
	{
	case 1:
		return "st";
	case 2:
		return "nd";
	case 3:
		return "rd";
	default:
		return "th";
	}
}

int main()
{
	string firstName;
	string lastName;
	string studyProgram;
	string academicYear;

	cout << "Enter your first name: ";
	getline(cin, firstName);

	cout << "Enter your last name: ";
	getline(cin, lastName);

	cout << "Enter your study program: ";
	getline(cin, studyProgram);

	cout << "Enter the academic year: ";
	getline(cin, academicYear);

	const time_t currentTime = chrono::system_clock::to_time_t(
		chrono::system_clock::now());
	const tm* currentDate = localtime(&currentTime);

	if (currentDate == nullptr)
	{
		cerr << "Unable to determine the current date.\n";
		return 1;
	}

	ostringstream date;
	date << currentDate->tm_mday << ordinalSuffix(currentDate->tm_mday) << ' '
		 << put_time(currentDate, "%B %Y");

	cout << "\nDate: " << date.str() << "\n\n"
			  << "To: " << firstName << ' ' << lastName << ",\n\n"
			  << "Dear " << firstName << ",\n\n"
			  << "CONGRATULATIONS! I am pleased to inform you that the Makerere "
				 "University Admissions Board has approved your application for "
				 "admission to the "
			  << academicYear << " academic year.\n\n"
			  << "You have been offered a place for the following course:\n"
			  << "PROGRAM: " << studyProgram << "\n\n"
			  << "As a student of Makerere University, you will be part of a "
				 "historic institution dedicated to academic excellence and "
				 "innovation. Please ensure that you report to the Academic "
				 "Registrar's office with your original academic documents for "
				 "verification during the orientation week.\n\n"
			  << "We look forward to welcoming you to Makerere University.\n\n"
			  << "Yours sincerely,\n\n"
			  << "John Doe\n"
			  << "Registrar\n";

	return 0;
}