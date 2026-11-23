// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: the CRT header did not declare this, so declare it as a dllimport (the call goes through an IAT slot).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: this is a checked-iterator operator++ (element size 0x28).
// Layout: [0] = container pointer, [4] = current element pointer.
struct FnCont_00542930 {
    int pad[4];
    char* endPtr; // +0x10
};

struct FnIter_00542930 {
    void* cont;
    char* ptr;
};

// INFERRED: the call-site pushes no stack args, so the declared stack params are dropped.
extern "C" unsigned char __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" FnCont_00542930* __fastcall fn_00402400(void* self, int unusedEdx);

extern "C" FnIter_00542930* __fastcall fn_00542930(FnIter_00542930* self, int unusedEdx)
{
    if (!fn_00402410(self, 0)) {
        _invalid_parameter_noinfo();
    }
    if (!(self->ptr < fn_00402400(self, 0)->endPtr)) {
        _invalid_parameter_noinfo();
    }
    self->ptr += 0x28;
    return self;
}
