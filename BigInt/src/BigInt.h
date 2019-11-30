#pragma once
#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include<string>

class BigInt {
public:
	BigInt(const std::string& s = "") { str = s; }
	inline void print() { std::cout << str; }
	friend std::string operator+ (const BigInt& A, const BigInt& B);
	friend std::string operator* (const BigInt& A, const BigInt& B);
	friend std::ostream& operator<< (std::ostream& os, const BigInt& A) {
		os << A.str;
		return os;
	}
	friend std::istream& operator>> (std::istream& is, BigInt& A) {
		is >> A.str;
		return is;
	}
private:
	std::string str;
};

#endif // !BIGINT_H