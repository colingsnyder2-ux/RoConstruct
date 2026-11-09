// from server: 100% by nuck16
// roc 2009-12 006d61b0  unit: RBX::DropperTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d61b0
//
// 006d61b0  51                   push ecx
// 006d61b1  56                   push esi
// 006d61b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d61b6  68508e9d00           push 0x9d8e50
// 006d61bb  8bce                 mov ecx, esi
// 006d61bd  c744240800000000     mov dword ptr [esp + 8], 0
// 006d61c5  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d61cb  8bc6                 mov eax, esi
// 006d61cd  5e                   pop esi
// 006d61ce  59                   pop ecx
// 006d61cf  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "DropperCursor";
}
