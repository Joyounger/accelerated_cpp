#include <algorithm>
#include <iomanip>

#ifndef __GNUC__
#include <ios>
#endif

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

#include "Student_info.h"
#include "median.h"

using std::cin;                    using std::cout;
using std::domain_error;           using std::endl;
using std::setprecision;           using std::setw;
using std::sort;                   using std::streamsize;
using std::string;                 using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {                           // changed
		maxlen = max(maxlen, record.name().size());      // changed
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
#ifdef _MSC_VER
	for (std::vector<Student_info>::size_type i = 0;
#else
	for (vector<Student_info>::size_type i = 0;
#endif
	     i != students.size(); ++i) {
		cout << students[i].name()   // this and the next line changed
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();   // changed
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

