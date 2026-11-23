// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>
#include <new>

// INFERRED: StatsService is an opaque 0x130-byte object here; the ctor is an extern thiscall helper.
extern "C" void __fastcall fn_00458520(void* self, int unusedEdx);
// INFERRED: 0x456f10 is shared_ptr<T>::shared_ptr(T*, Deleter) (thiscall, two stack args). The empty Deleter is passed by value as a byte-sized dummy.
extern "C" void __fastcall fn_00456f10(void* self, int unusedEdx, void* p, int deleter);

struct StatsServicePtr;

extern "C" StatsServicePtr* fn_00458590(StatsServicePtr* out)
{
    void* p = malloc(0x130);
    void* obj = 0;
    if (p) {
        fn_00458520(p, 0);
        obj = p;
    }
    int deleter = 0;
    fn_00456f10(out, 0, obj, deleter);
    return out;
}
