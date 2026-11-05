// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
namespace G3D {
#define DONT_SHRINK_UNDERLYING_ARRAY false
template <class T>
class Array {
	T* data;
	int num;
	int numAllocated;
	inline bool inArray(const T* address) {
		return (address >= data) && (address < data + num);
	}
public:
	void resize(int n, bool shrinkIfNecessary);
	void append(const T& value);
};
template <class T>
void Array<T>::append(const T& value) {
	if (num < numAllocated) {
		new (data + num) T(value);
		++num;
	} else if (inArray(&value)) {
		T tmp = value;
		append(tmp);
	} else {
		resize(num + 1, DONT_SHRINK_UNDERLYING_ARRAY);
		data[num - 1] = value;
	}
}
template void Array<float>::append(const float&);
}
