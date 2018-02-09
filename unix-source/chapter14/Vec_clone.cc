#include "Vec.h"

template <class T> T* clone(const T* tp);
// the key to making `Ptr< Vec<char> >' work
template<>
Vec<char>* clone(const Vec<char>* vp)
{
	return new Vec<char>(*vp);
}

