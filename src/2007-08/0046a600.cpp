// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 0046a600  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a600
//
// 0046a600  6aff                 push -1
// 0046a602  682c7f7400           push 0x747f2c
// 0046a607  64a100000000         mov eax, dword ptr fs:[0]
// 0046a60d  50                   push eax
// 0046a60e  51                   push ecx
// 0046a60f  56                   push esi
// 0046a610  57                   push edi
// 0046a611  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046a616  33c4                 xor eax, esp
// 0046a618  50                   push eax
// 0046a619  8d442410             lea eax, [esp + 0x10]
// 0046a61d  64a300000000         mov dword ptr fs:[0], eax
// 0046a623  8bf1                 mov esi, ecx
// 0046a625  8974240c             mov dword ptr [esp + 0xc], esi
// 0046a629  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046a62d  8b07                 mov eax, dword ptr [edi]
// 0046a62f  8906                 mov dword ptr [esi], eax
// 0046a631  8b4f04               mov ecx, dword ptr [edi + 4]
// 0046a634  8d5708               lea edx, [edi + 8]
// 0046a637  894e04               mov dword ptr [esi + 4], ecx
// 0046a63a  52                   push edx
// 0046a63b  8d4e08               lea ecx, [esi + 8]
// 0046a63e  ff159ce67700         call dword ptr [0x77e69c]
// 0046a644  83c724               add edi, 0x24
// 0046a647  57                   push edi
// 0046a648  8d4e24               lea ecx, [esi + 0x24]
// 0046a64b  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046a653  ff159ce67700         call dword ptr [0x77e69c]
// 0046a659  8bc6                 mov eax, esi
// 0046a65b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046a65f  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a666  59                   pop ecx
// 0046a667  5f                   pop edi
// 0046a668  5e                   pop esi
// 0046a669  83c410               add esp, 0x10
// 0046a66c  c20400               ret 4

#include <string>

namespace RBX { namespace LDraw2Lua {
struct LDraw2RobloxMapRoot {
    int field0;
    int field4;
    std::string field8;
    std::string field24;
    LDraw2RobloxMapRoot(const LDraw2RobloxMapRoot& other);
};

LDraw2RobloxMapRoot::LDraw2RobloxMapRoot(const LDraw2RobloxMapRoot& other)
    : field0(other.field0), field4(other.field4), field8(other.field8), field24(other.field24)
{
}
}}
