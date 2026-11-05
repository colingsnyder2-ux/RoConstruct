// from server: 100% by nuck16
// roc 2009-12 007cca60  unit: RBX::GroupDropTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cca60
//
// 007cca60  51                   push ecx
// 007cca61  56                   push esi
// 007cca62  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007cca66  68e0e99e00           push 0x9ee9e0
// 007cca6b  8bce                 mov ecx, esi
// 007cca6d  c744240800000000     mov dword ptr [esp + 8], 0
// 007cca75  ff15f4b69800         call dword ptr [0x98b6f4]
// 007cca7b  8bc6                 mov eax, esi
// 007cca7d  5e                   pop esi
// 007cca7e  59                   pop ecx
// 007cca7f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "DropCursor";
}
