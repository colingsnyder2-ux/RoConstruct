// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

struct T;
typedef T* E;

extern "C" int __fastcall fn_004c7a90(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: layout of the checked std::vector<T*> (secure-SCL iterators hold container ptr + element ptr)
struct VecLayout {
    VecLayout* cont;   // +0x00 : container proxy / self reference used by checked iterators
    int pad[2];        // +0x04
    E* first;          // +0x0c
    E* last;           // +0x10
};

struct IterLayout {
    VecLayout* cont;
    E* ptr;
};

// INFERRED: std::vector<T*>::insert(const_iterator where, const value_type& val)
// returning an 8-byte checked iterator through a hidden return pointer; the
// inner insert(where, 1, val) (_Insert_n) is the out-of-line fn_004c7a90.
extern "C" IterLayout* __fastcall fn_00679120(VecLayout* self, int unusedEdx,
                                              IterLayout* ret,
                                              VecLayout* whereCont,
                                              E* wherePtr,
                                              const E* val)
{
    E* first = self->first;
    E* last = self->last;
    int off;
    if ((((char*)last - (char*)first) & 0xfffffffc) == 0) {
        off = 0;
    } else {
        if (first > last)
            _invalid_parameter_noinfo();
        if (!whereCont || whereCont != self->cont)
            _invalid_parameter_noinfo();
        off = (int)((char*)wherePtr - (char*)first) >> 2;
    }

    fn_004c7a90(self, 0, (int)whereCont, (int)wherePtr, 1, (int)val);

    E* nfirst = self->first;
    if (nfirst > self->last)
        _invalid_parameter_noinfo();
    VecLayout* cont = self->cont;
    VecLayout* c = cont;
    if (!c)
        _invalid_parameter_noinfo();
    E* p = nfirst + off;
    if (p > c->last || p < (c ? c->first : ((VecLayout*)0)->first))
        _invalid_parameter_noinfo();

    ret->ptr = p;
    ret->cont = cont;
    return ret;
}
