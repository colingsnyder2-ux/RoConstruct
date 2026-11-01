// from server: 100% by auto
// roc 2009-12 005b0a40  unit: seg_005b0000  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0a40
//
// 005b0a40  55                   push ebp
// 005b0a41  8bec                 mov ebp, esp
// 005b0a43  6aff                 push -1
// 005b0a45  68f0c99300           push 0x93c9f0
// 005b0a4a  64a100000000         mov eax, dword ptr fs:[0]
// 005b0a50  50                   push eax
// 005b0a51  64892500000000       mov dword ptr fs:[0], esp
// 005b0a58  83ec0c               sub esp, 0xc
// 005b0a5b  53                   push ebx
// 005b0a5c  56                   push esi
// 005b0a5d  57                   push edi
// 005b0a5e  8b7d08               mov edi, dword ptr [ebp + 8]
// 005b0a61  8965f0               mov dword ptr [ebp - 0x10], esp
// 005b0a64  8bf1                 mov esi, ecx
// 005b0a66  81ff55555515         cmp edi, 0x15555555
// 005b0a6c  7605                 jbe 0x5b0a73
// 005b0a6e  e8ed16e9ff           call 0x442160
// 005b0a73  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b0a76  85c0                 test eax, eax
// 005b0a78  7415                 je 0x5b0a8f
// 005b0a7a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005b0a7d  2bc8                 sub ecx, eax
// 005b0a7f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b0a84  f7e9                 imul ecx
// 005b0a86  d1fa                 sar edx, 1
// 005b0a88  8bc2                 mov eax, edx
// 005b0a8a  c1e81f               shr eax, 0x1f
// 005b0a8d  03c2                 add eax, edx
// 005b0a8f  3bc7                 cmp eax, edi
// 005b0a91  0f838f000000         jae 0x5b0b26
// 005b0a97  6a00                 push 0
// 005b0a99  57                   push edi
// 005b0a9a  e8b12feaff           call 0x453a50
// 005b0a9f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b0aa2  83c408               add esp, 8
// 005b0aa5  8945ec               mov dword ptr [ebp - 0x14], eax
// 005b0aa8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005b0aaf  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005b0ab2  7606                 jbe 0x5b0aba
// 005b0ab4  ff1560b79800         call dword ptr [0x98b760]
// 005b0aba  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005b0abd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005b0ac0  7606                 jbe 0x5b0ac8
// 005b0ac2  ff1560b79800         call dword ptr [0x98b760]
// 005b0ac8  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005b0acb  c645e800             mov byte ptr [ebp - 0x18], 0
// 005b0acf  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 005b0ad2  50                   push eax
// 005b0ad3  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005b0ad6  51                   push ecx
// 005b0ad7  8d5608               lea edx, [esi + 8]
// 005b0ada  52                   push edx
// 005b0adb  50                   push eax
// 005b0adc  53                   push ebx
// 005b0add  57                   push edi
// 005b0ade  e8adceffff           call 0x5ad990
// 005b0ae3  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b0ae6  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005b0ae9  2bcb                 sub ecx, ebx
// 005b0aeb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b0af0  f7e9                 imul ecx
// 005b0af2  d1fa                 sar edx, 1
// 005b0af4  8bfa                 mov edi, edx
// 005b0af6  c1ef1f               shr edi, 0x1f
// 005b0af9  83c418               add esp, 0x18
// 005b0afc  03fa                 add edi, edx
// 005b0afe  85db                 test ebx, ebx
// 005b0b00  7409                 je 0x5b0b0b
// 005b0b02  53                   push ebx
// 005b0b03  e8522d2400           call 0x7f385a
// 005b0b08  83c404               add esp, 4
// 005b0b0b  8b4508               mov eax, dword ptr [ebp + 8]
// 005b0b0e  8d0c40               lea ecx, [eax + eax*2]
// 005b0b11  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005b0b14  8d1488               lea edx, [eax + ecx*4]
// 005b0b17  8d0c7f               lea ecx, [edi + edi*2]
// 005b0b1a  895614               mov dword ptr [esi + 0x14], edx
// 005b0b1d  8d1488               lea edx, [eax + ecx*4]
// 005b0b20  895610               mov dword ptr [esi + 0x10], edx
// 005b0b23  89460c               mov dword ptr [esi + 0xc], eax
// 005b0b26  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b0b29  5f                   pop edi
// 005b0b2a  5e                   pop esi
// 005b0b2b  64890d00000000       mov dword ptr fs:[0], ecx
// 005b0b32  5b                   pop ebx
// 005b0b33  8be5                 mov esp, ebp
// 005b0b35  5d                   pop ebp
// 005b0b36  c20400               ret 4
// standard library vector<pod12> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
