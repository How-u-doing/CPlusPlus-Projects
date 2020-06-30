#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Assoc {
	vector<pair<string, int>> vec;  //vector of {name,value} pairs
	//const int& operator[] (const string&) const;
	int& operator[](const string&);
};

int& Assoc::operator[](const string& s)
  //search for s; return a reference to its value if found;
  //otherwise, make a new pair {s,0} and return a reference to its value
{
	// the author forgot '&' sign; we cannot add const before auto
	// as we need to increment the occurrences (x.second)
	for (auto& x : vec) {
		if (s == x.first)
			return x.second;
	}

	vec.push_back({ s,0 });   //initial value: 0
	return vec.back().second; //return last element
}

int main()//count the occurrences of each word on input
{
	Assoc values;
	string buf;
	while (cin >> buf) ++values[buf];
	for (auto x : values.vec)
		cout << '{' << x.first << ',' << x.second << "}\n";

	return 0;
}
