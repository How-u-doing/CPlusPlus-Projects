#include "List.h"
#include <limits> //std::numeric_limits
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#define USE_MYSORT

#if defined USE_MYSORT
#define FAST3WAY_PARTITION	// define quicksort method
#include "mySort.h"
#else
#include <algorithm>	// using std::sort()
#endif // defined USE_MYSORT

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
List::iterator List::search(iterator& _Where) {
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

void List::modify(iterator& _Where, const Student& _Newdata) {
	auto it = search(_Where);	// check _Where is valid in this list (if it points to another
								// list element, it should have no access to modify it)
	if (it != end()) {
		*it = _Newdata;
	}
}


void List::sort(sortMode _Mode, sortOrder _Order) {
#if defined USE_MYSORT
	mySortingAlgo::
#else
	std::
#endif // defined USE_MYSORT 
		sort(begin(), end(), [&_Mode, &_Order](const Student& a, const Student& b) {
		switch (_Mode) {
		case List::sortMode::stu_id:
			return (_Order == sortOrder::ascending) ? (a.number() < b.number()) : (a.number() > b.number());
		case List::sortMode::name:
			return (_Order == sortOrder::ascending) ? strcmp(a.name(), b.name()) <= 0 : strcmp(a.name(), b.name()) > 0;
		case List::sortMode::sum:
			return (_Order == sortOrder::ascending) ? (a.sum() < b.sum()) : (a.sum() > b.sum());
		case List::sortMode::ave:
			return (_Order == sortOrder::ascending) ? (a.average() < b.average()) : (a.average() > b.average());
		case List::sortMode::math:
			return (_Order == sortOrder::ascending) ? (a.math_score() < b.math_score()) : (a.math_score() > b.math_score());
		case List::sortMode::english:
			return (_Order == sortOrder::ascending) ? (a.english_score() < b.english_score()) : (a.english_score() > b.english_score());
		case List::sortMode::computer:
			return (_Order == sortOrder::ascending) ? (a.computer_score() < b.computer_score()) : (a.computer_score() > b.computer_score());
		case List::sortMode::var:
			return (_Order == sortOrder::ascending) ? (a.variance() < b.variance()) : (a.variance() > b.variance());
		}
			});
}

void List::import_file(const std::string& _Filename){
	std::ifstream ifs{ _Filename };
	if (!ifs) {
		std::string error_msg = "Couldn't open file " + _Filename + " for reading.\n";
		throw std::runtime_error(error_msg);
	}

	// skip first line/header (a line as attributes)
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
		throw std::runtime_error(error_msg);
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
