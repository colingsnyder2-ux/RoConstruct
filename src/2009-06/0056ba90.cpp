// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <stdlib.h>
inline void alignedFree(void* p) {
    if (p) free(((void**)p)[-1]);
}
template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    ~Array();
};
template<class T> Array<T>::~Array() {
    for (int i = 0; i < num; ++i) {
        (data + i)->~T();
    }
    alignedFree(data);
    data = 0;
    num = 0;
    numAllocated = 0;
}
template class Array<std::string>;
