#pragma once
#ifndef LIST_H
#define LIST_H
#include "Student.h"
#include <vector>
#include <cassert>

class List : std::vector<Student> {
public:
	void print_list();
	void read(const std::string& filename);
	void write(const std::string& filename);
	void sort();
	void search(const Student& key);
	void size();

private:
	static size_t _count;

};

#endif // !LIST_H
