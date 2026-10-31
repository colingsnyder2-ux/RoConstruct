// from server: 100% by EspClaude
// roc 2009-06 004e59b0  unit: CRobloxWnd::UserInputJob  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e59b0
//
// 004e59b0  51                   push ecx
// 004e59b1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e59b5  8d0424               lea eax, [esp]
// 004e59b8  50                   push eax
// 004e59b9  51                   push ecx
// 004e59ba  e8d179ffff           call 0x4dd390
// 004e59bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004e59c3  83c408               add esp, 8
// 004e59c6  83790400             cmp dword ptr [ecx + 4], 0
// 004e59ca  7409                 je 0x4e59d5
// 004e59cc  8d1424               lea edx, [esp]
// 004e59cf  52                   push edx
// 004e59d0  e8fbf6ffff           call 0x4e50d0
// 004e59d5  59                   pop ecx
// 004e59d6  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX0000a5@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000a5 {
struct S {
    unsigned int reserved;
    unsigned int count;
    void apply(unsigned int*);
};

extern void __cdecl prepare(void*, unsigned int*);

void __cdecl f(S* object, void* source)
{
    unsigned int value;
    prepare(source, &value);
    if (object->count != 0)
        object->apply(&value);
}
}
