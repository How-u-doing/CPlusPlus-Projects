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
		cout << "Original data\n";
		list.print_list();

		// add student data by string
		list.push_back(Student{ "10170437, Mark J. Taylor, 83, 91.5, 87" });

		// bad: memory leak (anonymous allocated memory cannot be freed. Of course, OS can...)
		//list.push_back(Student(10170438, "John A. Smith", new float[3]{ 90.f, 72.5f, 93.f }));

		// inconvenient, have to create a local array or dynamicly create one (then free it)
		float score[3] = { 90.f, 72.5f, 93.f };
		list.push_back(Student(10170438, "John A. Smith", score));

		// add student data by initializer_list
		list.push_back(Student(10170439, "Joey Trribiani", { 96.5,87.f }));

		list.modify(10170492, Student("10170402, Monica Geller , 93, 81.5, 87"));
		
		list.sort(List::sortMode::stu_id, List::sortOrder::ascending); 
		cout << "\n\n\nSorted by number\n";
		list.print_list();
		Student::set_oMode(Student::oMode::more);
		list.save_as("sorted_by_number.csv", list.begin(), list.end());

		List list2;
		//Student::set_iMode(Student::iMode::more);
		ifstream ifs{ "sorted_by_number.csv" };
		ifs >> Student::iMode::more;
		ifs.close();
		
		list2.import_file( "sorted_by_number.csv");
		list2.sort();
		cout << "\n\n\nSort by sum\n";

		auto it = list2.search(10170409);
		// Can't find, return list2.end(), won't modify anything.
		//auto it = list2.search(10170499);
		list2.modify(it, Student(10170409, "Chandler Bing", { 96.5,100 ,87 }));
		
		// Can't find, return list.end(), incompatible & call abort()
		//auto it = list2.search(10170499);
		//list2.modify(it, Student(10170409, "Chandler Bing", { 96.5,100 ,87 }));

		list2.sort();
		list2.print_list();

		list2.save_as("sorted_by_sum.csv", list.begin(), list.end());

		list2.sort(List::sortMode::name, List::sortOrder::ascending);
		cout << "\n\n\nSort by name\n";
		list2.print_list();
		list2.save_as("sorted_by_name.csv", list.begin(), list.end());
	}
	catch (exception & e) {
		cout << e.what();
	}

	cout << "\nPress any key to leave...\n";
	char wait;
	cin >> noskipws >> wait;
	return 0;
}