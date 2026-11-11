// >>> native-status (generated) -- do not edit >>>
// scopedassign | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e78e76bf | roc native-status --write
#ifndef UTIL_SCOPEDASSIGN_H
#define UTIL_SCOPEDASSIGN_H


namespace RBX {

// SIZE 0x8
template <class T>
class ScopedAssign
{
public:
	ScopedAssign(T& value, const T& newValue) : value(&value), oldValue(value) { value = newValue; }

	~ScopedAssign() { *value = oldValue; }

private:
	T* value;   // 0x00
	T oldValue; // 0x04
};

// clang-format off
// TEMPLATE: WEBSERVICE 0x1019bf50
// RBX::ScopedAssign<int>::~ScopedAssign<int>
// clang-format on

} // namespace RBX

#endif // UTIL_SCOPEDASSIGN_H
