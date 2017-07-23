#include <list>
#include "Student_info.h"
#include "grade.h"

using std::list;
// version 4: use `list' instead of `vector'
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
}

