// from server: 100% by EspClaude
// roc 2009-06 004e4c20  unit: CRobloxWnd::UserInputJob  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4c20
//
// 004e4c20  83ec0c               sub esp, 0xc
// 004e4c23  d9ee                 fldz 
// 004e4c25  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e4c29  8d0424               lea eax, [esp]
// 004e4c2c  d91424               fst dword ptr [esp]
// 004e4c2f  50                   push eax
// 004e4c30  d9542408             fst dword ptr [esp + 8]
// 004e4c34  51                   push ecx
// 004e4c35  d95c2410             fstp dword ptr [esp + 0x10]
// 004e4c39  e85290ffff           call 0x4ddc90
// 004e4c3e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e4c42  83c408               add esp, 8
// 004e4c45  83790400             cmp dword ptr [ecx + 4], 0
// 004e4c49  7409                 je 0x4e4c54
// 004e4c4b  8d1424               lea edx, [esp]
// 004e4c4e  52                   push edx
// 004e4c4f  e86cffffff           call 0x4e4bc0
// 004e4c54  83c40c               add esp, 0xc
// 004e4c57  c3                   ret 
// copied from an identical function in another client (function ?initialize@ns_ROCX0000a0@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000a0 {
extern void __cdecl transfer(void *destination, const float *source);

struct S {
    char padding[4];
    int enabled;
    void apply(const float *source);
};

void __cdecl initialize(S *object, void *destination)
{
    float value[3] = { 0.0f, 0.0f, 0.0f };
    transfer(destination, value);
    if (object->enabled != 0)
        object->apply(value);
}
}
