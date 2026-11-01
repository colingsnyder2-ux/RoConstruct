// from server: 100% by nuck16
// roc 2009-12 006d54a0  unit: RBX::StudsTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d54a0
//
// 006d54a0  51                   push ecx
// 006d54a1  56                   push esi
// 006d54a2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d54a6  681c879d00           push 0x9d871c
// 006d54ab  8bce                 mov ecx, esi
// 006d54ad  c744240800000000     mov dword ptr [esp + 8], 0
// 006d54b5  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d54bb  8bc6                 mov eax, esi
// 006d54bd  5e                   pop esi
// 006d54be  59                   pop ecx
// 006d54bf  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "StudsCursor";
}
