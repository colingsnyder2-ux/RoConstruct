// from server: 100% by auto
// roc 2007-08 00424410  unit: CSelectionTreeCtrl  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00424410
//
// 00424410  83ec08               sub esp, 8
// 00424413  56                   push esi
// 00424414  8bf1                 mov esi, ecx
// 00424416  8b5604               mov edx, dword ptr [esi + 4]
// 00424419  85d2                 test edx, edx
// 0042441b  57                   push edi
// 0042441c  7504                 jne 0x424422
// 0042441e  33c9                 xor ecx, ecx
// 00424420  eb08                 jmp 0x42442a
// 00424422  8b4e08               mov ecx, dword ptr [esi + 8]
// 00424425  2bca                 sub ecx, edx
// 00424427  c1f903               sar ecx, 3
// 0042442a  85d2                 test edx, edx
// 0042442c  743d                 je 0x42446b
// 0042442e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424431  2bc2                 sub eax, edx
// 00424433  c1f803               sar eax, 3
// 00424436  3bc8                 cmp ecx, eax
// 00424438  7331                 jae 0x42446b
// 0042443a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042443e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00424442  8b7e08               mov edi, dword ptr [esi + 8]
// 00424445  c644240800           mov byte ptr [esp + 8], 0
// 0042444a  8b442408             mov eax, dword ptr [esp + 8]
// 0042444e  50                   push eax
// 0042444f  51                   push ecx
// 00424450  56                   push esi
// 00424451  52                   push edx
// 00424452  6a01                 push 1
// 00424454  57                   push edi
// 00424455  e84697feff           call 0x40dba0
// 0042445a  83c418               add esp, 0x18
// 0042445d  83c708               add edi, 8
// 00424460  897e08               mov dword ptr [esi + 8], edi
// 00424463  5f                   pop edi
// 00424464  5e                   pop esi
// 00424465  83c408               add esp, 8
// 00424468  c20400               ret 4
// 0042446b  8b7e08               mov edi, dword ptr [esi + 8]
// 0042446e  3bd7                 cmp edx, edi
// 00424470  7606                 jbe 0x424478
// 00424472  ff15d8e67700         call dword ptr [0x77e6d8]
// 00424478  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042447c  50                   push eax
// 0042447d  57                   push edi
// 0042447e  56                   push esi
// 0042447f  8d4c2414             lea ecx, [esp + 0x14]
// 00424483  51                   push ecx
// 00424484  8bce                 mov ecx, esi
// 00424486  e895efffff           call 0x423420
// 0042448b  5f                   pop edi
// 0042448c  5e                   pop esi
// 0042448d  83c408               add esp, 8
// 00424490  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
