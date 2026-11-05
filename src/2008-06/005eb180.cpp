// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005eb180  unit: RBX::VSky::?$FactoryProduct  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005eb180
//
// 005eb180  55                   push ebp
// 005eb181  8bec                 mov ebp, esp
// 005eb183  6aff                 push -1
// 005eb185  68c06c7d00           push 0x7d6cc0
// 005eb18a  64a100000000         mov eax, dword ptr fs:[0]
// 005eb190  50                   push eax
// 005eb191  64892500000000       mov dword ptr fs:[0], esp
// 005eb198  83ec08               sub esp, 8
// 005eb19b  53                   push ebx
// 005eb19c  56                   push esi
// 005eb19d  57                   push edi
// 005eb19e  8b7d08               mov edi, dword ptr [ebp + 8]
// 005eb1a1  8965f0               mov dword ptr [ebp - 0x10], esp
// 005eb1a4  8bf1                 mov esi, ecx
// 005eb1a6  57                   push edi
// 005eb1a7  8975ec               mov dword ptr [ebp - 0x14], esi
// 005eb1aa  e8a1dce3ff           call 0x428e50
// 005eb1af  84c0                 test al, al
// 005eb1b1  7437                 je 0x5eb1ea
// 005eb1b3  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005eb1b6  c6450800             mov byte ptr [ebp + 8], 0
// 005eb1ba  8b4508               mov eax, dword ptr [ebp + 8]
// 005eb1bd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005eb1c0  50                   push eax
// 005eb1c1  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005eb1c4  51                   push ecx
// 005eb1c5  8d5608               lea edx, [esi + 8]
// 005eb1c8  52                   push edx
// 005eb1c9  50                   push eax
// 005eb1ca  57                   push edi
// 005eb1cb  53                   push ebx
// 005eb1cc  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005eb1d3  e8d8dde3ff           call 0x428fb0
// 005eb1d8  8d0cfd00000000       lea ecx, [edi*8]
// 005eb1df  83c418               add esp, 0x18
// 005eb1e2  2bcf                 sub ecx, edi
// 005eb1e4  8d148b               lea edx, [ebx + ecx*4]
// 005eb1e7  895610               mov dword ptr [esi + 0x10], edx
// 005eb1ea  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005eb1ed  5f                   pop edi
// 005eb1ee  5e                   pop esi
// 005eb1ef  64890d00000000       mov dword ptr fs:[0], ecx
// 005eb1f6  5b                   pop ebx
// 005eb1f7  8be5                 mov esp, ebp
// 005eb1f9  5d                   pop ebp
// 005eb1fa  c20800               ret 8
// standard library vector<string> (function ?_Construct_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
