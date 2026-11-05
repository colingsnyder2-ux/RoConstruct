// from server: 100% by auto
// roc 2007-08 00539d10  unit: RBX::Reflection::VValue::V?$vector::?$holder  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00539d10
//
// 00539d10  83ec08               sub esp, 8
// 00539d13  56                   push esi
// 00539d14  8bf1                 mov esi, ecx
// 00539d16  8b5604               mov edx, dword ptr [esi + 4]
// 00539d19  85d2                 test edx, edx
// 00539d1b  57                   push edi
// 00539d1c  7504                 jne 0x539d22
// 00539d1e  33c9                 xor ecx, ecx
// 00539d20  eb08                 jmp 0x539d2a
// 00539d22  8b4e08               mov ecx, dword ptr [esi + 8]
// 00539d25  2bca                 sub ecx, edx
// 00539d27  c1f903               sar ecx, 3
// 00539d2a  85d2                 test edx, edx
// 00539d2c  743d                 je 0x539d6b
// 00539d2e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00539d31  2bc2                 sub eax, edx
// 00539d33  c1f803               sar eax, 3
// 00539d36  3bc8                 cmp ecx, eax
// 00539d38  7331                 jae 0x539d6b
// 00539d3a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00539d3e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00539d42  8b7e08               mov edi, dword ptr [esi + 8]
// 00539d45  c644240800           mov byte ptr [esp + 8], 0
// 00539d4a  8b442408             mov eax, dword ptr [esp + 8]
// 00539d4e  50                   push eax
// 00539d4f  51                   push ecx
// 00539d50  56                   push esi
// 00539d51  52                   push edx
// 00539d52  6a01                 push 1
// 00539d54  57                   push edi
// 00539d55  e8463eedff           call 0x40dba0
// 00539d5a  83c418               add esp, 0x18
// 00539d5d  83c708               add edi, 8
// 00539d60  897e08               mov dword ptr [esi + 8], edi
// 00539d63  5f                   pop edi
// 00539d64  5e                   pop esi
// 00539d65  83c408               add esp, 8
// 00539d68  c20400               ret 4
// 00539d6b  8b7e08               mov edi, dword ptr [esi + 8]
// 00539d6e  3bd7                 cmp edx, edi
// 00539d70  7606                 jbe 0x539d78
// 00539d72  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539d78  8b442414             mov eax, dword ptr [esp + 0x14]
// 00539d7c  50                   push eax
// 00539d7d  57                   push edi
// 00539d7e  56                   push esi
// 00539d7f  8d4c2414             lea ecx, [esp + 0x14]
// 00539d83  51                   push ecx
// 00539d84  8bce                 mov ecx, esi
// 00539d86  e8d5feffff           call 0x539c60
// 00539d8b  5f                   pop edi
// 00539d8c  5e                   pop esi
// 00539d8d  83c408               add esp, 8
// 00539d90  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
