#ifndef UTIL_SCOPEDASSIGN_H
#define UTIL_SCOPEDASSIGN_H

// PORT: omit donor metadata include; template body is unchanged.

namespace RBX {

// SIZE 0x8
template <class T>
class ScopedAssign
{
public:
	ScopedAssign(T& value, const T& newValue) : value(&value), oldValue(value) { *this->value = newValue; }

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
