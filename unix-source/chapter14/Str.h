#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <algorithm>
#include <iostream>
#include "Ptr.h"
#include "Vec.h"

template<>
Vec<char>* clone(const Vec<char>*);

// does this version work?
class Str {
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream& getline(std::istream&, Str&);

public:
	Str& operator+=(const Str& s) {
		data.make_unique();
		std::copy(s.data->begin(), s.data->end(),
		          std::back_inserter(*data));
		return *this;
	}

	// interface as before
	typedef Vec<char>::size_type size_type;

	// reimplement constructors to create `Ptr's
	Str(): data(new Vec<char>) { }
	Str(const char* cp): data(new Vec<char>)  {
#ifdef _MSC_VER
		std::copy(cp, cp + strlen(cp),
#else
		std::copy(cp, cp + std::strlen(cp),
#endif
		          std::back_inserter(*data));
	}

	Str(size_type n, char c): data(new Vec<char>(n, c)) { }
	template <class In> Str(In i, In j): data(new Vec<char>) {
		std::copy(i, j, std::back_inserter(*data));
	}

	// call `make_unique' as necessary
	char& operator[](size_type i) {
		data.make_unique();
		return (*data)[i];
	}
	const char& operator[](size_type i) const { return (*data)[i]; }
	size_type size() const { return data->size(); }

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin() { return data->begin(); }
	const_iterator begin() const { return data->begin(); }

	iterator end() { return data->end(); }
	const_iterator end() const { return data->end(); }

private:
	// store a `Ptr' to a `vector'
	Ptr< Vec<char> > data;
};
// as implemented in 12.3.2/216 and 12.3.3/219 
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
inline bool operator<(const Str& lhs, const Str& rhs)
{
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
inline bool operator>(const Str& lhs, const Str& rhs)
{
        return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}
inline bool operator<=(const Str& lhs, const Str& rhs)
{
        return !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());

}
inline bool operator>=(const Str& lhs, const Str& rhs)
{
        return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());

}
inline bool operator==(const Str& lhs, const Str& rhs)
{
        return lhs.size() == rhs.size() &&
                std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
inline bool operator!=(const Str& lhs, const Str& rhs)
{
        return !(lhs == rhs);
}
#endif

