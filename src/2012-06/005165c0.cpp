// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_SECURE_SCL=0
#include <algorithm>
struct T { int x; T& operator=(const T&); };
T* f(T* first, T* last, T* dest) { return std::copy_backward(first, last, dest); }
