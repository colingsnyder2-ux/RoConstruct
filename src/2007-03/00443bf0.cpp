// from server: 100% by auto
// roc 2007-03 00443bf0  unit: seg_00440000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00443bf0
//
// 00443bf0  83ec08               sub esp, 8
// 00443bf3  56                   push esi
// 00443bf4  8bf1                 mov esi, ecx
// 00443bf6  57                   push edi
// 00443bf7  8b7e04               mov edi, dword ptr [esi + 4]
// 00443bfa  85ff                 test edi, edi
// 00443bfc  7504                 jne 0x443c02
// 00443bfe  33c9                 xor ecx, ecx
// 00443c00  eb15                 jmp 0x443c17
// 00443c02  8b4e08               mov ecx, dword ptr [esi + 8]
// 00443c05  2bcf                 sub ecx, edi
// 00443c07  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00443c0c  f7e9                 imul ecx
// 00443c0e  d1fa                 sar edx, 1
// 00443c10  8bca                 mov ecx, edx
// 00443c12  c1e91f               shr ecx, 0x1f
// 00443c15  03ca                 add ecx, edx
// 00443c17  85ff                 test edi, edi
// 00443c19  744a                 je 0x443c65
// 00443c1b  8b560c               mov edx, dword ptr [esi + 0xc]
// 00443c1e  2bd7                 sub edx, edi
// 00443c20  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00443c25  f7ea                 imul edx
// 00443c27  d1fa                 sar edx, 1
// 00443c29  8bc2                 mov eax, edx
// 00443c2b  c1e81f               shr eax, 0x1f
// 00443c2e  03c2                 add eax, edx
// 00443c30  3bc8                 cmp ecx, eax
// 00443c32  7331                 jae 0x443c65
// 00443c34  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00443c38  8b542414             mov edx, dword ptr [esp + 0x14]
// 00443c3c  8b7e08               mov edi, dword ptr [esi + 8]
// 00443c3f  c644240800           mov byte ptr [esp + 8], 0
// 00443c44  8b442408             mov eax, dword ptr [esp + 8]
// 00443c48  50                   push eax
// 00443c49  51                   push ecx
// 00443c4a  56                   push esi
// 00443c4b  52                   push edx
// 00443c4c  6a01                 push 1
// 00443c4e  57                   push edi
// 00443c4f  e80cf6ffff           call 0x443260
// 00443c54  83c418               add esp, 0x18
// 00443c57  83c70c               add edi, 0xc
// 00443c5a  897e08               mov dword ptr [esi + 8], edi
// 00443c5d  5f                   pop edi
// 00443c5e  5e                   pop esi
// 00443c5f  83c408               add esp, 8
// 00443c62  c20400               ret 4
// 00443c65  53                   push ebx
// 00443c66  8b5e08               mov ebx, dword ptr [esi + 8]
// 00443c69  3bfb                 cmp edi, ebx
// 00443c6b  7606                 jbe 0x443c73
// 00443c6d  ff1544e97700         call dword ptr [0x77e944]
// 00443c73  8b442418             mov eax, dword ptr [esp + 0x18]
// 00443c77  50                   push eax
// 00443c78  53                   push ebx
// 00443c79  56                   push esi
// 00443c7a  8d4c2418             lea ecx, [esp + 0x18]
// 00443c7e  51                   push ecx
// 00443c7f  8bce                 mov ecx, esi
// 00443c81  e87afbffff           call 0x443800
// 00443c86  5b                   pop ebx
// 00443c87  5f                   pop edi
// 00443c88  5e                   pop esi
// 00443c89  83c408               add esp, 8
// 00443c8c  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
