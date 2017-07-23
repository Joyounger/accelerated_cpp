#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

using std::isspace;

int main()
{
	string s;

	// read and split each line of input
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// write each word in `v'
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}

