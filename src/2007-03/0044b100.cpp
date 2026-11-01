// from server: 100% by auto
// roc 2007-03 0044b100  unit: seg_00440000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044b100
//
// 0044b100  83ec08               sub esp, 8
// 0044b103  56                   push esi
// 0044b104  8bf1                 mov esi, ecx
// 0044b106  57                   push edi
// 0044b107  8b7e04               mov edi, dword ptr [esi + 4]
// 0044b10a  85ff                 test edi, edi
// 0044b10c  7504                 jne 0x44b112
// 0044b10e  33c9                 xor ecx, ecx
// 0044b110  eb15                 jmp 0x44b127
// 0044b112  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044b115  2bcf                 sub ecx, edi
// 0044b117  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044b11c  f7e9                 imul ecx
// 0044b11e  d1fa                 sar edx, 1
// 0044b120  8bca                 mov ecx, edx
// 0044b122  c1e91f               shr ecx, 0x1f
// 0044b125  03ca                 add ecx, edx
// 0044b127  85ff                 test edi, edi
// 0044b129  744a                 je 0x44b175
// 0044b12b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0044b12e  2bd7                 sub edx, edi
// 0044b130  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044b135  f7ea                 imul edx
// 0044b137  d1fa                 sar edx, 1
// 0044b139  8bc2                 mov eax, edx
// 0044b13b  c1e81f               shr eax, 0x1f
// 0044b13e  03c2                 add eax, edx
// 0044b140  3bc8                 cmp ecx, eax
// 0044b142  7331                 jae 0x44b175
// 0044b144  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044b148  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044b14c  8b7e08               mov edi, dword ptr [esi + 8]
// 0044b14f  c644240800           mov byte ptr [esp + 8], 0
// 0044b154  8b442408             mov eax, dword ptr [esp + 8]
// 0044b158  50                   push eax
// 0044b159  51                   push ecx
// 0044b15a  56                   push esi
// 0044b15b  52                   push edx
// 0044b15c  6a01                 push 1
// 0044b15e  57                   push edi
// 0044b15f  e85cfaffff           call 0x44abc0
// 0044b164  83c418               add esp, 0x18
// 0044b167  83c70c               add edi, 0xc
// 0044b16a  897e08               mov dword ptr [esi + 8], edi
// 0044b16d  5f                   pop edi
// 0044b16e  5e                   pop esi
// 0044b16f  83c408               add esp, 8
// 0044b172  c20400               ret 4
// 0044b175  53                   push ebx
// 0044b176  8b5e08               mov ebx, dword ptr [esi + 8]
// 0044b179  3bfb                 cmp edi, ebx
// 0044b17b  7606                 jbe 0x44b183
// 0044b17d  ff1544e97700         call dword ptr [0x77e944]
// 0044b183  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044b187  50                   push eax
// 0044b188  53                   push ebx
// 0044b189  56                   push esi
// 0044b18a  8d4c2418             lea ecx, [esp + 0x18]
// 0044b18e  51                   push ecx
// 0044b18f  8bce                 mov ecx, esi
// 0044b191  e8bafeffff           call 0x44b050
// 0044b196  5b                   pop ebx
// 0044b197  5f                   pop edi
// 0044b198  5e                   pop esi
// 0044b199  83c408               add esp, 8
// 0044b19c  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
