// from server: 100% by nuck16
// roc 2009-12 007e6240  unit: RBX::ExclusiveArbiter  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e6240
//
// 007e6240  51                   push ecx
// 007e6241  56                   push esi
// 007e6242  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007e6246  68a4ff9e00           push 0x9effa4
// 007e624b  8bce                 mov ecx, esi
// 007e624d  c744240800000000     mov dword ptr [esp + 8], 0
// 007e6255  ff15f4b69800         call dword ptr [0x98b6f4]
// 007e625b  8bc6                 mov eax, esi
// 007e625d  5e                   pop esi
// 007e625e  59                   pop ecx
// 007e625f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "ExclusiveArbiter";
}
