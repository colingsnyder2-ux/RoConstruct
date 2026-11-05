// from server: 100% by nuck16
// roc 2009-12 006d69b0  unit: RBX::LaserTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d69b0
//
// 006d69b0  51                   push ecx
// 006d69b1  56                   push esi
// 006d69b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d69b6  6820919d00           push 0x9d9120
// 006d69bb  8bce                 mov ecx, esi
// 006d69bd  c744240800000000     mov dword ptr [esp + 8], 0
// 006d69c5  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d69cb  8bc6                 mov eax, esi
// 006d69cd  5e                   pop esi
// 006d69ce  59                   pop ecx
// 006d69cf  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "GunCursor";
}
