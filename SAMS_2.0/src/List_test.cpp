#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	List list;
	string filename{ "student_data.csv" };
	try {		
		Student::set_iMode(Student::iMode::less);
		list.import_file(filename);
		list.print_list();

		// add student data by string
		list.push_back(Student{ "10170437, Mark J. Taylor, 83, 91.5, 87" });

		// bad: memory leak (anonymous allocated memory cannot be freed. Of course, OS can...)
		//list.push_back(Student(10170438, "John A. Smith", new float[3]{ 90.f, 72.5f, 93.f }));

		// inconvenient, have to create a local array or dynamicly create one (then free it)
		float score[3] = { 90.f, 72.5f, 93.f };
		list.push_back(Student(10170438, "John A. Smith", score));

		// add student data by initialier_list
		list.push_back(Student(10170439, "Joey Trribiani", { 96.5,87.f }));

		Student::set_oMode(Student::oMode::more);
		list.save_as("new_data.csv", list.begin(), list.end());

		List list2;
		//Student::set_iMode(Student::iMode::more);
		ifstream ifs{ "new_data.csv" };
		ifs >> Student::iMode::more;

		list2.import_file( "new_data.csv");
		cout << "\n\n\n";
		list2.print_list();

		ifs.close();
	}
	catch (exception & e) {
		cout << e.what();
	}

	return 0;
}