// from server: 100% by nuck16
// roc 2009-12 006d5b60  unit: RBX::RightMotorTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5b60
//
// 006d5b60  51                   push ecx
// 006d5b61  56                   push esi
// 006d5b62  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5b66  689c899d00           push 0x9d899c
// 006d5b6b  8bce                 mov ecx, esi
// 006d5b6d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5b75  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d5b7b  8bc6                 mov eax, esi
// 006d5b7d  5e                   pop esi
// 006d5b7e  59                   pop ecx
// 006d5b7f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "MotorCursor";
}
