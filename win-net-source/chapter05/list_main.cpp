#include <algorithm>
#include <list>
#include <string>

#include "grade.h"
#include "Student_info.h"

using std::max;

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

list<Student_info> extract_fails(list<Student_info>& v);


int main()
{
        list<Student_info> vs;
        Student_info s;
        string::size_type maxlen = 0;
        while (read(cin, s)) {
                maxlen = max(maxlen, s.name.size());
                vs.push_back(s);
        }

        vs.sort(compare);

	list<Student_info> fails = extract_fails(vs);

	list<Student_info>::iterator i;

	for (i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;

	return 0;
}
