#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "List.h"
#define Fast3way_partition	// define quicksort method
#include "mySort.h"

#define use_mySort

void List::print_atrributes() {
	printf("Number\t  Name\t\t\t Math\tEnglish\tComputer Sum\tAverage Variance\n");
}
void List::print(iterator _From, iterator _To) {
	for (auto it = _From; it != _To; ++it)
		std::cout << *it << std::endl;
}
void List::print_list() {
	print_atrributes();
	print(begin(), end());
}

// return end() if not found
List::iterator List::search(Student::numTy _Stu_id) {
	auto it = begin();
	for (; it != end(); ++it)
		if (it->number() == _Stu_id) {
			return it;
		}
	return it;
}
List::iterator List::search(const_iterator& _Where) {
	auto it = begin();
	for (; it != end(); ++it) {
		if (it == _Where) {
			return it;
		}
	}
	return it;
}

void List::remove(Student::numTy _Stu_id) {
	auto it = search(_Stu_id);
	if (it != end()) {
		erase(it);
	}
	else {
		std::cout << "Student with id " << _Stu_id << " does NOT exist." << std::endl;
	}
}

void List::modify(Student::numTy _Stu_id, const Student& _Newdata) {
	auto it = search(_Stu_id);
	if (it != end()) {
		*it = _Newdata;
	}
	else {
		std::cout << "Student with id " << _Stu_id << " does NOT exist." << std::endl;
	}
	
}

void List::modify(const_iterator& _Where, const Student& _Newdata) {
	auto it = search(_Where);	// check _Where is valid in this list (if it points to another
								// list element, it should have no access to modify it)
	if (it != end()) {
		*it = _Newdata;
	}
}


void List::sort(sortMode _Mode, sortOrder _Order) {
#if defined use_mySort
	mySortingAlgo::
#else
	std::
#endif // defined use_mySort 
	sort(begin(), end(), [&_Mode, &_Order](const Student& a, const Student& b) {
		switch (_Mode)
		{
		case List::sortMode::stu_id:
			return (_Order == sortOrder::ascending) ? (a.number() < b.number()) : (a.number() > b.number());
			break;
		case List::sortMode::name:
			return (_Order == sortOrder::ascending) ? strcmp(a.name(), b.name()) <= 0 : strcmp(a.name(), b.name()) > 0;
			break;
		case List::sortMode::sum:
			return (_Order == sortOrder::ascending) ? (a.sum() < b.sum()) : (a.sum() > b.sum());
			break;
		case List::sortMode::ave:
			return (_Order == sortOrder::ascending) ? (a.average() < b.average()) : (a.average() > b.average());
			break;
		case List::sortMode::math:
			return (_Order == sortOrder::ascending) ? (a.math_score() < b.math_score()) : (a.math_score() > b.math_score());
			break;
		case List::sortMode::english:
			return (_Order == sortOrder::ascending) ? (a.english_score() < b.english_score()) : (a.english_score() > b.english_score());
			break;
		case List::sortMode::computer:
			return (_Order == sortOrder::ascending) ? (a.computer_score() < b.computer_score()) : (a.computer_score() > b.computer_score());
			break;
		case List::sortMode::var:
			return (_Order == sortOrder::ascending) ? (a.variance() < b.variance()) : (a.variance() > b.variance());
			break;
		}
		});
}

void List::import_file(const std::string& _Filename){
	std::ifstream ifs{ _Filename };
	if (!ifs) {
		std::string error_msg = "Couldn't open file " + _Filename + " for reading.\n";
		throw std::exception(error_msg.c_str());
	}

	// skip first line/header (a line as attributes)
#if defined _WIN32 || defined _WIN64
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#else  // on Linux/Unix
	ifs.ignore(1024, '\n');
#endif // defined _WIN32 || defined _WIN64

	Student s;
	while (ifs >> s) {
		push_back(s);
	}

	ifs.close();
}

void List::save_as(const std::string& _Filename, const_iterator _From, const_iterator _To,
	std::ios_base::openmode _Mode)
{
	std::ofstream ofs{ _Filename, _Mode };
	if (!ofs) {
		std::string error_msg = "Couldn't open file " + _Filename + " for writing.\n";
		throw std::exception(error_msg.c_str());
	}

	ofs << "Student ID" << ',' << "Name" << ',' << "Math" << ',' << "English" \
		<< ',' << "Computer";

	if (Student::get_oMode() == Student::oMode::more) {
		ofs << ',' << "Sum" << ',' << "Average" << ',' << "Variance" << std::endl;
	}
	else {
		ofs << '\n';
	}

	
	for (auto it = begin(); it != end(); ++it)
		ofs << *it << std::endl;

	ofs.close();
}
