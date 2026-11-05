// from server: 100% by nuck16
// roc 2009-12 006d5c70  unit: RBX::ModelSetFrontTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5c70
//
// 006d5c70  51                   push ecx
// 006d5c71  56                   push esi
// 006d5c72  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5c76  685c8b9d00           push 0x9d8b5c
// 006d5c7b  8bce                 mov ecx, esi
// 006d5c7d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5c85  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d5c8b  8bc6                 mov eax, esi
// 006d5c8d  5e                   pop esi
// 006d5c8e  59                   pop ecx
// 006d5c8f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "DirectionCursor";
}
