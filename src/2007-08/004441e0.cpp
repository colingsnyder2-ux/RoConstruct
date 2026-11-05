// from server: 100% by auto
// roc 2007-08 004441e0  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004441e0
//
// 004441e0  83ec08               sub esp, 8
// 004441e3  56                   push esi
// 004441e4  8bf1                 mov esi, ecx
// 004441e6  8b5604               mov edx, dword ptr [esi + 4]
// 004441e9  85d2                 test edx, edx
// 004441eb  57                   push edi
// 004441ec  7504                 jne 0x4441f2
// 004441ee  33c9                 xor ecx, ecx
// 004441f0  eb08                 jmp 0x4441fa
// 004441f2  8b4e08               mov ecx, dword ptr [esi + 8]
// 004441f5  2bca                 sub ecx, edx
// 004441f7  c1f904               sar ecx, 4
// 004441fa  85d2                 test edx, edx
// 004441fc  743d                 je 0x44423b
// 004441fe  8b460c               mov eax, dword ptr [esi + 0xc]
// 00444201  2bc2                 sub eax, edx
// 00444203  c1f804               sar eax, 4
// 00444206  3bc8                 cmp ecx, eax
// 00444208  7331                 jae 0x44423b
// 0044420a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044420e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00444212  8b7e08               mov edi, dword ptr [esi + 8]
// 00444215  c644240800           mov byte ptr [esp + 8], 0
// 0044421a  8b442408             mov eax, dword ptr [esp + 8]
// 0044421e  50                   push eax
// 0044421f  51                   push ecx
// 00444220  56                   push esi
// 00444221  52                   push edx
// 00444222  6a01                 push 1
// 00444224  57                   push edi
// 00444225  e8d6f4ffff           call 0x443700
// 0044422a  83c418               add esp, 0x18
// 0044422d  83c710               add edi, 0x10
// 00444230  897e08               mov dword ptr [esi + 8], edi
// 00444233  5f                   pop edi
// 00444234  5e                   pop esi
// 00444235  83c408               add esp, 8
// 00444238  c20400               ret 4
// 0044423b  8b7e08               mov edi, dword ptr [esi + 8]
// 0044423e  3bd7                 cmp edx, edi
// 00444240  7606                 jbe 0x444248
// 00444242  ff15d8e67700         call dword ptr [0x77e6d8]
// 00444248  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044424c  50                   push eax
// 0044424d  57                   push edi
// 0044424e  56                   push esi
// 0044424f  8d4c2414             lea ecx, [esp + 0x14]
// 00444253  51                   push ecx
// 00444254  8bce                 mov ecx, esi
// 00444256  e865fbffff           call 0x443dc0
// 0044425b  5f                   pop edi
// 0044425c  5e                   pop esi
// 0044425d  83c408               add esp, 8
// 00444260  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
