// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00709940  unit: MemoryBinder  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00709940
//
// 00709940  8b442408             mov eax, dword ptr [esp + 8]
// 00709944  83ec28               sub esp, 0x28
// 00709947  50                   push eax
// 00709948  8d4c2404             lea ecx, [esp + 4]
// 0070994c  686cfab900           push 0xb9fa6c
// 00709951  51                   push ecx
// 00709952  e819942600           call 0x972d70
// 00709957  83c40c               add esp, 0xc
// 0070995a  686c80cd00           push 0xcd806c
// 0070995f  8d542404             lea edx, [esp + 4]
// 00709963  52                   push edx
// 00709964  e8db972700           call 0x983144
// copied from an identical function in another client (function ?bad@@YAXHPBD@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
#include <stdexcept>
std::runtime_error runtime_error(const char* fmt, ...);
void bad(int, const char* name) { throw runtime_error("%s cannot be assigned to", name); }