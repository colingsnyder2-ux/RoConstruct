// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: MSVCR90 import (called via indirect [0x802890]); not declared by the headers used here.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: this is std::vector<T*>::resize(n, val) with MSVC 2008 checked iterators.
// Layout: +0 proxy/container, +0xc _Myfirst, +0x10 _Mylast.
struct VecIter {
    void* proxy;
    int*  ptr;
};

struct PtrVector {
    void* proxy;      // +0
    int   pad[2];     // +4, +8
    int*  first;      // +0xc
    int*  last;       // +0x10
};

extern "C" int __fastcall fn_004c7a90(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
// INFERRED: iterator operator+(ptrdiff_t)
extern "C" VecIter* __fastcall fn_0064a900(VecIter* self, int unusedEdx, VecIter* ret, int n);
// INFERRED: vector::erase(first, last)
extern "C" void __fastcall fn_00445dc0(PtrVector* self, int unusedEdx, VecIter* ret, VecIter f, VecIter l);

extern "C" void __fastcall fn_004c7d20(PtrVector* self, int unusedEdx, unsigned int newSize, int val)
{
    int* first = self->first;
    int* last = self->last;
    unsigned int size = (unsigned int)(last - first);

    if (newSize > size) {
        if (first > last)
            _invalid_parameter_noinfo();
        fn_004c7a90(self, 0, (int)self->proxy, (int)last,
                    (int)(newSize - (unsigned int)(self->last - self->first)), (int)&val);
        return;
    }
    if (newSize < size) {
        if (first > last)
            _invalid_parameter_noinfo();
        void* proxy = self->proxy;
        int* b = self->first;
        if (b > self->last)
            _invalid_parameter_noinfo();
        VecIter it;
        it.proxy = self->proxy;
        it.ptr = b;
        VecIter tmp;
        VecIter* r = fn_0064a900(&it, 0, &tmp, (int)newSize);
        VecIter lastIt;
        lastIt.proxy = proxy;
        lastIt.ptr = last;
        VecIter out;
        fn_00445dc0(self, 0, &out, *r, lastIt);
    }
}
