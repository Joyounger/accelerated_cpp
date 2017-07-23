#include <algorithm>

#include <ios>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Core.h"

using std::cout;           using std::cin;
using std::endl;           using std::domain_error;
using std::setprecision;   using std::setw;
using std::sort;           using std::streamsize;
using std::string;         using std::vector;

using std::max;

int main()
{
	vector<Core> students;          // read and process `Core' records
	Core record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade(); // `Core::grade'
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

