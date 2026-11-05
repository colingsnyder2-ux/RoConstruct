// from server: 100% by auto
// roc 2007-08 004a2830  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2830
//
// 004a2830  83ec08               sub esp, 8
// 004a2833  56                   push esi
// 004a2834  8bf1                 mov esi, ecx
// 004a2836  57                   push edi
// 004a2837  8b7e04               mov edi, dword ptr [esi + 4]
// 004a283a  85ff                 test edi, edi
// 004a283c  7504                 jne 0x4a2842
// 004a283e  33c9                 xor ecx, ecx
// 004a2840  eb15                 jmp 0x4a2857
// 004a2842  8b4e08               mov ecx, dword ptr [esi + 8]
// 004a2845  2bcf                 sub ecx, edi
// 004a2847  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a284c  f7e9                 imul ecx
// 004a284e  d1fa                 sar edx, 1
// 004a2850  8bca                 mov ecx, edx
// 004a2852  c1e91f               shr ecx, 0x1f
// 004a2855  03ca                 add ecx, edx
// 004a2857  85ff                 test edi, edi
// 004a2859  744a                 je 0x4a28a5
// 004a285b  8b560c               mov edx, dword ptr [esi + 0xc]
// 004a285e  2bd7                 sub edx, edi
// 004a2860  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a2865  f7ea                 imul edx
// 004a2867  d1fa                 sar edx, 1
// 004a2869  8bc2                 mov eax, edx
// 004a286b  c1e81f               shr eax, 0x1f
// 004a286e  03c2                 add eax, edx
// 004a2870  3bc8                 cmp ecx, eax
// 004a2872  7331                 jae 0x4a28a5
// 004a2874  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a2878  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a287c  8b7e08               mov edi, dword ptr [esi + 8]
// 004a287f  c644240800           mov byte ptr [esp + 8], 0
// 004a2884  8b442408             mov eax, dword ptr [esp + 8]
// 004a2888  50                   push eax
// 004a2889  51                   push ecx
// 004a288a  56                   push esi
// 004a288b  52                   push edx
// 004a288c  6a01                 push 1
// 004a288e  57                   push edi
// 004a288f  e8bcf2ffff           call 0x4a1b50
// 004a2894  83c418               add esp, 0x18
// 004a2897  83c70c               add edi, 0xc
// 004a289a  897e08               mov dword ptr [esi + 8], edi
// 004a289d  5f                   pop edi
// 004a289e  5e                   pop esi
// 004a289f  83c408               add esp, 8
// 004a28a2  c20400               ret 4
// 004a28a5  53                   push ebx
// 004a28a6  8b5e08               mov ebx, dword ptr [esi + 8]
// 004a28a9  3bfb                 cmp edi, ebx
// 004a28ab  7606                 jbe 0x4a28b3
// 004a28ad  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a28b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a28b7  50                   push eax
// 004a28b8  53                   push ebx
// 004a28b9  56                   push esi
// 004a28ba  8d4c2418             lea ecx, [esp + 0x18]
// 004a28be  51                   push ecx
// 004a28bf  8bce                 mov ecx, esi
// 004a28c1  e8bafeffff           call 0x4a2780
// 004a28c6  5b                   pop ebx
// 004a28c7  5f                   pop edi
// 004a28c8  5e                   pop esi
// 004a28c9  83c408               add esp, 8
// 004a28cc  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
