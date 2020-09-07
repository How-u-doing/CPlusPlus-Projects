#include "Student.h"
#include <limits> // std::numeric_limits
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

void read(vector<Student>& list, const string& filename)
{
	ifstream ifs{ filename };
	if (!ifs) {
		string error_msg = "Couldn't open " + filename + " for reading.\n";
		throw runtime_error(error_msg);
	}

	// skip first line (a line as attributes)
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	Student s;

	// read from file solution 1
	/*string _csv_Line{};	
	while (std::getline(ifs, _csv_Line)) {
		s.parse_assign(_csv_Line);
		list.push_back(s);
		cout << s << endl;
	}*/

	// read from file solution 2
	while (ifs>>s) {
		list.push_back(s);
		cout << s << endl;
	}

	ifs.close();
}

void write(const vector<Student>& list, const string& filename)
{
	ofstream ofs{ filename, std::ios_base::app };
	if (!ofs) {
		string error_msg = "Couldn't open " + filename + " for writing.\n";
		throw runtime_error(error_msg);
	}

	ofs << "Student ID" << ',' << "Name" << ',' << "Math" << ',' << "English" \
		<< ',' << "Computer";

	if (Student::get_oMode() == Student::oMode::more) {
		ofs << ',' << "Sum" << ',' << "Average" << ',' << "Variance" << std::endl;
	}
	else {
		ofs << '\n';
	}


	for (auto it = list.begin(); it != list.end(); ++it)
		ofs << *it << endl;

	ofs.close();
}


int main()
{
	vector<Student> list;
	string filename{ "student_data.csv" };
	try {
		printf("Number\t  Name\t\t\t Math\tEnglish\tComputer Sum\tAverage Variance\n");
		Student::set_iMode(Student::iMode::less);
		read(list,filename);

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
		write(list, "new_data.csv");

		vector<Student> list2;
		printf("\n\n\nNumber\t  Name\t\t\t Math\tEnglish\tComputer Sum\tAverage Variance\n");
		//Student::set_iMode(Student::iMode::more);
		ifstream ifs{ "new_data.csv" };
		ifs >> Student::iMode::more;
		
		read(list2, "new_data.csv");
	}
	catch (const exception& e) {
		cout << e.what();
	}

	return 0;
}