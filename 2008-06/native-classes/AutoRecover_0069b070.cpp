// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: the CRT import is declared by hand because the headers do not declare it (called via [0x802890]).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: CRobloxControlColorSelector::CColorInfo is a 12-byte POD (the 0x2aaaaaab divide-by-12 pattern).
struct CColorInfo {
    int a, b, c;
};

// INFERRED: std::vector<CColorInfo> with checked-iterator proxy at +0, _Myfirst at +0xc, _Mylast at +0x10.
struct ColorInfoVector {
    void* proxy;
    int   alloc[2];
    CColorInfo* first;
    CColorInfo* last;
};

struct VecIter {
    void* proxy;
    CColorInfo* ptr;
};

extern "C" int __fastcall fn_00699c60(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_00697c10(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
// _Vector_iterator::operator+(n), returns result through hidden pointer
extern "C" VecIter* __fastcall fn_006900d0(VecIter* self, int unusedEdx, VecIter* ret, unsigned n);

// INFERRED: std::vector<CColorInfo>::resize(size_type n, CColorInfo val)
extern "C" int __fastcall fn_0069b070(ColorInfoVector* self, int unusedEdx, unsigned n, CColorInfo val)
{
    CColorInfo* last = self->last;
    CColorInfo* first = self->first;
    unsigned size = (unsigned)(((int)last - (int)first) / 12);

    if (n > size) {
        if (first > last)
            _invalid_parameter_noinfo();
        unsigned count = n - (unsigned)(((int)self->last - (int)self->first) / 12);
        return fn_00699c60(self, 0, (int)self->proxy, (int)last, (int)count, (int)&val);
    }
    if (n < size) {
        if (first > last)
            _invalid_parameter_noinfo();
        CColorInfo* f = self->first;
        void* proxy = self->proxy;
        if (f > self->last)
            _invalid_parameter_noinfo();
        VecIter begin;
        begin.proxy = self->proxy;
        begin.ptr = f;
        VecIter tmp;
        VecIter* p = fn_006900d0(&begin, 0, &tmp, n);
        VecIter out;
        return fn_00697c10(self, 0, (int)&out, (int)p->proxy, (int)p->ptr, (int)proxy, (int)last);
    }
    return size;
}
