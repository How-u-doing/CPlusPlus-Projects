#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

// definition of static data members
Student::iMode Student::_iMode = Student::iMode::more;
Student::oMode Student::_oMode = Student::oMode::more;

Student::iMode& Student::get_iMode() { return _iMode; }
Student::oMode& Student::get_oMode() { return _oMode; }

void Student::set_iMode(const Student::iMode& _Mode) {
	Student::_iMode = _Mode;
}
void Student::set_oMode(const Student::oMode& _Mode) {
	Student::_oMode = _Mode;
}

template <typename IstreamTy>
IstreamTy& operator>>(IstreamTy& _Is, const Student::iMode& _Mode) {
	Student::_iMode = _Mode;
	return _Is;
}
template <typename OstreamTy>
OstreamTy& operator<<(OstreamTy& _Os, const Student::oMode& _Mode) {
	Student::_oMode = _Mode;
	return _Os;
}
// instantiation
template std::istream& operator>>(std::istream& _Os, const Student::iMode& _Mode);
template std::ifstream& operator>>(std::ifstream& _Os, const Student::iMode& _Mode);
template std::istringstream& operator>>(std::istringstream& _Os, const Student::iMode& _Mode);
template std::ostream& operator<<(std::ostream& _Os, const Student::oMode& _Mode);
template std::ofstream& operator<<(std::ofstream& _Os, const Student::oMode& _Mode);
template std::ostringstream& operator<<(std::ostringstream& _Os, const Student::oMode& _Mode);


Student::Student() :_num(0), _name(""), _ave(0.f), _var(0.f) {
	for (int i = 0; i < 3; ++i)
		_score[i] = 0.f;
}

Student::Student(numTy num, const char* name, std::initializer_list<float> scoreList)
	: _num{ num }
{
	strcpymost(_name, name, _name_length);
	// scoreList examples: {68,72.5,89}, {77,56}, {92}
	int i = 0;
	for (auto it = scoreList.begin(); it != scoreList.end() && i < 3; ++it)
		_score[i++] = *it;
	// complete omitted list (binary or unary)
	while (i < 3) {
		_score[i++] = 0.f;
	}

	_ave = calc_ave();
	_var = calc_var();
}

Student::Student(numTy num, const char* name, const float score[3])
	: _num{ num }
{
	strcpymost(_name, name, _name_length);
	for (int i = 0; i < 3; ++i)
		_score[i] = score[i];

	_ave = calc_ave();
	_var = calc_var();
}

Student::Student(const Student& _Stu) : _num(_Stu._num) {
	strncpy_s(_name, _Stu._name, _name_length - 1);
	_name[_name_length - 1] = '\0';
	for (int i = 0; i < 3; ++i)
		_score[i] = _Stu._score[i];

	_ave = _Stu._ave;
	_var = _Stu._var;
}

Student::Student(const std::string& _csv_Line){
	parse_assign(_csv_Line);
}

Student::~Student() {}


template <typename IstreamTy>
IstreamTy& operator>>(IstreamTy& _Is, Student& _Stu) {
	_Is >> _Stu._num;
	_Is.ignore(1024, ',');	 // get rid of first comma (after number)
	std::string s{};
	char ch;
	// kill extra whitespaces between first comma and first latter of name
	_Is >> ch; s += ch;

	_Is >> std::noskipws;	// remain the whitespaces among name segments
	while (_Is >> ch && ch != ',')
		s += ch;

	// assign string to char array _Stu._name <-> strcpymost(_Stu._name, s.c_str(), Student::_name_length);
	int i = 0;
	for (; i < _Stu._name_length - 1 && s[i]; ++i)
		_Stu._name[i] = s[i];
	//while (i < _name_length)	// optional, to assign all rest chars with value '\0'
	_Stu._name[i++] = '\0';		// may be truncated when s.size() > _name_length

	_Is >> std::skipws;
	_Is >> _Stu._score[0];	_Is.ignore(1024, ',');
	_Is >> _Stu._score[1];	_Is.ignore(1024, ',');
	_Is >> _Stu._score[2];

	// less: "10170437, Mark J. Taylor, 83, 91.5, 87"
	// more: "10170437, Mark J. Taylor, 83, 91.5, 87, 87.2, 12.1"
	// also need to read ",ave,var"
	if (Student::_iMode == Student::iMode::more) {
		_Is.ignore(1024, ',');	_Is >> _Stu._ave;
		_Is.ignore(1024, ',');	_Is >> _Stu._var;
	}
	else //if (Student::_iMode == Student::iMode::less)
	{
		_Stu._ave = _Stu.calc_ave();
		_Stu._var = _Stu.calc_var();
	}

	return _Is;
}

// Explicit instantiation for input streams
template std::istream& operator>>(std::istream& _Is, Student& _Stu);
template std::ifstream& operator>>(std::ifstream& _Ifs, Student& _Stu);
// optional, anyway we'll implicitly instantiate it in function @parse_assign(_csv_Line)
//template std::istringstream& operator>>(std::istringstream& _Iss, Student& _Stu);	

// Alternative approach to instantiate op>>
//void implicit_instantiation() {
//	Student s;
//
//	std::cin >> s;	// implicitly instantiate istream (console)
//
//	std::ifstream ifs;
//	ifs >> s;		// implicitly instantiate ifstream
//
//	// unnecessary, since we have implicitly initialized it in function @parse_assign(_csv_Line)
//	//std::istringstream iss;
//	//iss >> s;
//}


void Student::print()const {
	printf("%-10d%-20s\t%5.1f\t%5.1f\t%5.1f\t%5.1f\t%6.1f", _num, _name, \
		_score[0], _score[1], _score[2], average(), variance());
}

// primary template for output to file & string
template <typename OstreamTy>
OstreamTy& operator<<(OstreamTy& _Os, const Student& _Stu) {
	_Os << _Stu._num << ',' << _Stu._name << ',' << _Stu._score[0] \
		<< ',' << _Stu._score[1] << ',' << _Stu._score[2];

	if (Student::_oMode == Student::oMode::more) {
		_Os << ',' << _Stu._ave << ',' << _Stu._var;
	}

	return _Os;
}

// (implicit) specialization output via console, meanwhile being instantiated (i.e. is an actual function)
template<> std::ostream& operator<<(std::ostream& _Os, const Student& _Stu)
{
	_Stu.print();
	return _Os;
}

// Explicit instantiation for output streams
//template std::ostream& operator<<(std::ostream& _Os, const Student& _Stu);// optional, already instantiated in specialization
template std::ofstream& operator<<(std::ofstream& _Os, const Student& _Stu);
template std::ostringstream& operator<<(std::ostringstream& _Os, const Student& _Stu);


// parse a comma-separated values (CSV) line & assign.
// a record example: "10170437, Mark J. Taylor, 83, 91.5, 87"
Student& Student::parse_assign(const std::string& _csv_Line) {
	std::istringstream iss{ _csv_Line };
	if (!iss) {
		std::string error_msg = "Couldn't link to string \"" + _csv_Line + "\" for parsing.\n";
		throw std::exception(error_msg.c_str());
	}

	iss >> *this;	// meanwhile implicitly instantiated operator>> for istringstream
	return *this;
}

Student& Student::assign(const Student& _Stu) {
	_num = _Stu._num;
	strncpy_s(_name, _Stu._name, _name_length - 1);
	_name[_name_length - 1] = '\0';
	for (int i = 0; i < 3; ++i)
		_score[i] = _Stu._score[i];
	return *this;
}

Student& Student::operator=(const Student& _Stu) {
	return assign(_Stu);
}

Student& Student::operator=(const std::string& _csv_Line) {
	return parse_assign(_csv_Line);
}

// get attribute values
Student::numTy Student::number()const { return _num; }
inline const char* Student::name()const { return _name; }
inline float Student::math_score()const { return _score[0]; }
inline float Student::english_score()const { return _score[1]; }
inline float Student::computer_score()const { return _score[2]; }
float Student::average()const { return _ave; }
float Student::variance()const { return _var; }
float Student::calc_ave()const { return aver(_score, 3); }
float Student::calc_var()const { return vari(_score, 3); }

float Student::aver(const float a[], int n)const {
	float ret = 0;
	for (int i = 0; i < n; ++i)
		ret += a[i];
	return ret / n;
}
float Student::vari(const float a[], int n)const {
	float ret = 0;
	float ave = aver(a, n);
	for (int i = 0; i < n; ++i)
		ret += (a[i] - ave) * (a[i] - ave);
	return ret / n;
}

// modify attribute values, modify all to use @parse_assign(_csv_Line)
inline void Student::modify_number(const numTy _Newnum) { _num = _Newnum; }
inline void Student::modify_math(const float _Newmath) { _score[0] = _Newmath; _ave = calc_ave(); _var = calc_var(); }
inline void Student::modify_english(const float _Newenglish) { _score[1] = _Newenglish; _ave = calc_ave(); _var = calc_var(); }
inline void Student::modify_computer(const float _Newcomputer) { _score[2] = _Newcomputer; _ave = calc_ave(); _var = calc_var(); }

void Student::strcpymost(char* _Destination, const char* _Source, size_t _Count) {
	auto srcptr = _Source;
	auto desptr = _Destination;
	size_t i = 0;
	// Note that the parentheses for *desptr++ = *srcptr++ are necessary, as precendence && > =. 
	// see <https://en.cppreference.com/w/cpp/language/operator_precedence>
	while ((*desptr++ = *srcptr++) && ++i < _Count);
	--desptr;
	if (*desptr) {
		*desptr++ = '\0';			// reset last char for safety

		std::string warnning_msg = "Warnning: copy truncated, as source string \"";
		warnning_msg += _Source;
		warnning_msg += "\" length exceeded.";
		std::cout << warnning_msg << std::endl;
	}
}

void Student::modify_name(const char* _Newname) {// strncpy(_name, _Newname, _name_length - 1); _name[_name_length-1]='\0';
	strcpymost(_name, _Newname, _name_length);
}