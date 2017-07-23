#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "urls.h"

using std::cout;
using std::cin;
using std::endl;
using std::find_if;
using std::getline;
using std::string;
using std::vector;


int main() {
        string s;
        while (getline(cin, s)) {
                vector<string> v = find_urls(s);
                for (vector<string>::const_iterator i = v.begin();
                        i != v.end(); ++i)
                        cout << *i << endl;
        }
        return 0;
}
