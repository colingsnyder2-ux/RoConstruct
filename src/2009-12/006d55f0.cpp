// from server: 100% by nuck16
// roc 2009-12 006d55f0  unit: RBX::InletTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d55f0
//
// 006d55f0  51                   push ecx
// 006d55f1  56                   push esi
// 006d55f2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d55f6  68bc879d00           push 0x9d87bc
// 006d55fb  8bce                 mov ecx, esi
// 006d55fd  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5605  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d560b  8bc6                 mov eax, esi
// 006d560d  5e                   pop esi
// 006d560e  59                   pop ecx
// 006d560f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "InletCursor";
}
