#include <algorithm>
#include <iomanip>

#ifndef __GNUC__
#include <ios>
#endif

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), Student_info::compare);

	// write the names and grades
#ifdef _MSC_VER
	for (std::vector<Student_info>::size_type i = 0;
#else
	for (vector<Student_info>::size_type i = 0;
#endif
	     i != students.size(); ++i) {
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

