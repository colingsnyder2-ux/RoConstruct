// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// The CRT import is declared locally because the headers did not provide it.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: the target is a checked-iterator dereference (_SECURE_SCL style),
// i.e. operator* / operator-> on a vector-like iterator.
// The iterator holds a pointer at +4.
struct CheckedIter {
    void* proxy;        // +0
    unsigned char* ptr; // +4
};

// INFERRED: the callee takes no stack args in the actual call (no pushes in the
// disassembly), so it is declared with none. It most likely returns a bool, such
// as a "has container" check.
extern "C" unsigned char __fastcall fn_00402410(void* self, int unusedEdx);

// INFERRED: returns a container-like pointer whose field at +0x10 is the end pointer.
struct ContainerLike {
    int pad[4];
    unsigned char* end; // +0x10
};
extern "C" ContainerLike* __fastcall fn_00402400(void* self, int unusedEdx);

extern "C" unsigned char* __fastcall fn_00542990(CheckedIter* self, int unusedEdx)
{
    if (!fn_00402410(self, 0))
        _invalid_parameter_noinfo();
    if (!(self->ptr < fn_00402400(self, 0)->end))
        _invalid_parameter_noinfo();
    return self->ptr;
}
