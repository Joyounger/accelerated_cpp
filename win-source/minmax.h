#ifndef GUARD_minmax_h
#define GUARD_minmax_h

#ifdef _MSC_VER
// needed (only) to cope with bug in MS library:
// it fails to define min/max

template <class T> T max(const T& a, const T& b)
{
	return (a > b) ? a : b; 
}

template <class T> T min(const T& a, const T& b)
{
	return (a < b) ? a : b;; 
}
#endif

#endif
