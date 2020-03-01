#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
public:
	using numTy = int;	// may change to "long long" when it is a large number

	Student();
	Student(const std::string& _csv_Line);
	Student(numTy num, const char* name, const float score[3]);
	Student(numTy num, const char* name, std::initializer_list<float> scoreList);
	Student(const Student& _Stu);
	~Student();
	Student& parse_assign(const std::string& _csv_Line);
	Student& assign(const Student& _Stu);
	Student& operator=(const std::string& _csv_Line);
	Student& operator=(const Student& _Stu);

	// output via console, file, string streams
	template <typename OstreamTy>
	friend OstreamTy& operator<<(OstreamTy& _Os, const Student& _Stu);
	void print()const;	// specialization output (formatted: align...) from console
	
	// input via console, file, string streams
	template <typename IstreamTy>
	friend IstreamTy& operator>>(IstreamTy& _Is, Student& _Stu);
		
	// get attribute values
	numTy number()const;
	const char* name()const;
	float math_score()const;
	float english_score()const;
	float computer_score()const;
	float sum();
	float average()const;
	float variance()const;
	float calc_sum()const;
	float calc_ave()const;
	float calc_var()const;
	float _sum_(const float a[], int n)const;
	float aver(const float a[], int n)const;
	float vari(const float a[], int n)const;

	// modify attribute values, modify all to use @assign(_csv_Line)
	void modify_number(const numTy _Newnum);
	void modify_name(const char* _Newname);
	void modify_math(const float _Newmath);
	void modify_english(const float _Newenglish);
	void modify_computer(const float _Newcomputer);

public:
	// input/output mode (whether to input/output average & variance)
	enum class iMode { less, more };
	enum class oMode { less, more };

	// Use it like  standard manipulators, e.g. s << Student::oMode::more (i.e. export all, including ave, var);
	// Note that this can be deceptive, especially when different kinds of streams invoke it, since the 
	// implementation provides only two options for all streams, instead of allowing each stream to possess
	// their own modes. For example, ifs << Student::iMode::less, then another stream changed it, say 
	// iss << Student::iMode::more, when ifs wants import again. Oops! Mode's changed. So, best practice is 
	// to reset i/o mode every time before reading/writing.  So as @set_ioMode().
	// Tips: imagine it as c++ union.
	template <typename IstreamTy>
	friend IstreamTy& operator>>(IstreamTy& _Is, const Student::iMode& _Mode);
	template <typename OstreamTy>
	friend OstreamTy& operator<<(OstreamTy& _Os, const Student::oMode& _Mode);

	/// also provide class-level ioMode setting functions
	static void set_iMode(const Student::iMode& _Mode);
	static void set_oMode(const Student::oMode& _Mode);

	/// add interfaces for getting ioMode state
	static iMode& get_iMode();
	static oMode& get_oMode();

private:
	void strcpymost(char* _Destination, const char* _Source, size_t _Count);
	
	static constexpr int _name_length = 10;	// or need to add an interface to render it variable

	static iMode _iMode;
	static oMode _oMode;

	// optional (though, but it's safe) to assign data members default values within class
	numTy _num = { 0 };
	char _name[_name_length] = { "" };
	float _score[3] = { 0.0f,0.0f,0.0f };
	float _sum = { 0.0f };
	float _ave = { 0.0f };
	float _var = { 0.0f };
};

#endif // !STUDENT_H
