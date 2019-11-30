// BigInt.cpp, implementation of BigInt.h
#include"BigInt.h"

std::string operator+(const BigInt& A, const BigInt& B) {

	int szA = A.str.size(), szB = B.str.size();
	// make C & D have the same length for the convenience of addition	
	std::string C(abs(szA - szB), '0'), D{};
	if (szA < szB) { C += A.str;	D = B.str; }
	if (szA > szB) { C += B.str;	D = A.str; }
	if (szA == szB) { C = A.str;	D = B.str; }

	int carry = 0;		// to add a number to next column on the left	
	std::string sum;	// store the result of the addition

	auto p1 = C.rbegin(), p2 = D.rbegin();
	while (p1 != C.rend()) {
		int tmp = *p1++ + *p2++ - 2 * '0' + carry;
		if (tmp > 9) {
			sum += char(tmp - 10 + '0');
			carry = 1;
		}
		else {
			sum += char(tmp + '0');
			carry = 0;
		}
	}

	// reverse the sum string
	std::string result(sum.rbegin(), sum.rend());

	if (carry == 1) { // max length add one
		result = '1' + result;	// pay attention to the order of '1' & result
	}
	return result;
}

std::string operator*(const BigInt& A, const BigInt& B) {

	int szA = A.str.size(), szB = B.str.size();
	int* prod = new int[szA + szB - 1]{};	// array for product

	for (int i = 0; i < szA; ++i)
		for (int j = 0; j < szB; ++j)
			prod[i + j] += (A.str[i] - '0') * (B.str[j] - '0');

	int carry = 0;
	std::string result(szA + szB - 1, '0');
	for (int k = szA + szB - 2; k >= 0; --k) {
		result[k] = (prod[k] + carry) % 10 + '0';
		carry = (prod[k] + carry) / 10;	// carry can be digit, tens, humdreds, ...
	}

	if (carry >= 1)
		result = char(carry + '0') + result;

	return result;
}
