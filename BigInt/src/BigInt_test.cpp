#include<iostream>
#include<string>

#include"BigInt.h"

using namespace std;

int main()
{
	cout << "|===========================|\n";
	cout << "|  Big integer computation  |\n";
	cout << "|       1: addition         |\n";
	cout << "|     2: multiplication     |\n";
	cout << "|===========================|\n\n";
	
	BigInt A, B;
	char doAgain='y';	
	while (doAgain == 'y' || doAgain == 'Y') {
		cout << "Please input your option (1 or 2): ";
		char option, kill;
				
		cin >> option;
		if (option == '1') {
			cout << "Please input one (big) integer:\n";
			cin >> A;
			cout << "Please input another (big) integer:\n";
			cin >> B;
			cout << "The sum is:\n" << A + B << '\n';
		}
		else if (option == '2'){
			cout << "Please input one (big) integer:\n";
			cin >> A;
			cout << "Please input another (big) integer:\n";
			cin >> B;
			cout << "The product is:\n" << A * B << '\n';
		}
		else {
			cerr << "Invalid input! Please input 1 or 2" << endl;
			continue;
		}

		cout << "Would you like to do it again (y or n)?\n";
		//while (kill = getchar() != '\n');
		cin >> doAgain;
	}



	return 0;
}