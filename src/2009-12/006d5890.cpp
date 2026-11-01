// from server: 100% by nuck16
// roc 2009-12 006d5890  unit: RBX::HingeTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5890
//
// 006d5890  51                   push ecx
// 006d5891  56                   push esi
// 006d5892  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5896  68fc889d00           push 0x9d88fc
// 006d589b  8bce                 mov ecx, esi
// 006d589d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d58a5  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d58ab  8bc6                 mov eax, esi
// 006d58ad  5e                   pop esi
// 006d58ae  59                   pop ecx
// 006d58af  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "HingeCursor";
}
