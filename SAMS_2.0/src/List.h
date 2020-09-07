#pragma once
#ifndef LIST_H
#define LIST_H
#include "Student.h"
#include <iostream>
#include <vector>
//#include <cassert>

class List : public std::vector<Student> {
public:
	void print_atrributes();
	void print(iterator _From, iterator _To);
	void print_list();

	iterator search(Student::numTy _Stu_id);
	iterator search(iterator& _Where);
	void remove(Student::numTy _Stu_id);
	void modify(Student::numTy _Stu_id, const Student& _Newdata);
	void modify(iterator& _Where, const Student& _Newdata);

	enum class sortMode { stu_id, name, sum, ave, math, english, computer, var };
	enum class sortOrder {ascending, descending};
	void sort(sortMode _Mode = sortMode::sum, sortOrder _Order = sortOrder::descending);

	void import_file(const std::string& _Filename);
	// by default, append data to the file
	void save_as(const std::string& _Filename, const_iterator _From, const_iterator _To,
		std::ios_base::openmode _Mode = std::ios_base::app);
		
	//All the functionalities that vector possesses are also 
	//inherited by List, common operations such as:
	//push_back(), pop_back(), size(), begin(), end(),
	//swap(), at(), emplace_back(), clear(), empty()...

};

#endif // !LIST_H
