// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<T>::_Insert_n(where, count, val) for a 12-byte element T.
// INFERRED: the first stack argument (ebp+8) is never read by the code.
// INFERRED: 0068e350, 006901e0 and 00692520 are called with no ecx setup that matters and the
//           stack is cleaned by the caller, so they are declared cdecl here. This deviates
//           from the "thiscall" hint in the task text, but matches the disassembly.
#include <new>

struct Elem12 { int a, b, c; };

struct Vec12 {
    int pad0;
    int pad4;
    int alloc;      // +8, allocator subobject (its address is passed to helpers)
    Elem12* first;  // +0xc
    Elem12* last;   // +0x10
    Elem12* end;    // +0x14
};

extern "C" void fn_004c6d40();                       // _Xlen
extern "C" Elem12* fn_0068d4b0(unsigned count, int zero); // _Allocate
extern "C" Elem12* fn_0068e350(Elem12* first, Elem12* where, Elem12* dest, int* alloc, Elem12* val, int zero);
extern "C" int __fastcall fn_00693eb0(void* self, int unusedEdx, Elem12* p, unsigned count, Elem12* val);
extern "C" Elem12* __fastcall fn_00697ca0(void* self, int unusedEdx, Elem12* a, Elem12* b, Elem12* c);
extern "C" void fn_006901e0(Elem12* first, Elem12* last, Elem12* val);
extern "C" void fn_00692520(Elem12* first, Elem12* last, Elem12* dest);

extern "C" void __fastcall fn_00699c60(Vec12* self, int unusedEdx, int unusedArg, Elem12* where, unsigned count, const Elem12* valp)
{
    Elem12* first = self->first;
    unsigned cap = first ? (unsigned)(self->end - first) : 0;

    if (count == 0)
        return;

    Elem12* last = self->last;
    unsigned size = (unsigned)(last - first);
    if (0x15555555u - size < count)
        fn_004c6d40();

    unsigned total = size + count;
    if (cap < total) {
        unsigned newcap;
        if (0x15555555u - cap / 2 < cap)
            newcap = 0;
        else
            newcap = cap + cap / 2;
        if (newcap < total)
            newcap = total;

        Elem12* newvec = fn_0068d4b0(newcap, 0);
        Elem12* newlast;
        try {
            newlast = fn_0068e350(self->first, where, newvec, &self->alloc, (Elem12*)valp, 0);
            fn_00693eb0(self, 0, newlast, count, (Elem12*)valp);
            Elem12* r = newlast + count;
            (void)r;
            newlast = fn_0068e350(self->last, where, newlast, &self->alloc, 0, 0);
        } catch (...) {
            operator delete(newvec);
            throw;
        }
        size = (unsigned)(self->last - self->first);
        Elem12* old = self->first;
        total = size + count;
        if (old)
            operator delete(old);
        self->end = newvec + newcap;
        self->last = newvec + total;
        self->first = newvec;
    }
    else if ((unsigned)(last - where) < count) {
        Elem12 tmp = *valp;
        fn_00697ca0(self, 0, where, last, where + count);
        last = self->last;
        fn_00693eb0(self, 0, last, count - (unsigned)(last - where), &tmp);
        self->last += count;
        fn_006901e0(where, self->last - count, &tmp);
    }
    else {
        Elem12 tmp = *valp;
        Elem12* mid = last - count;
        Elem12* r = fn_00697ca0(self, 0, mid, last, last);
        self->last = r;
        fn_00692520(where, mid, last);
        fn_006901e0(where, where + count, &tmp);
    }
}
