// from server: 100% by auto
// roc 2009-12 005dd620  unit: RBX::ImmediateMeshGenAdapter  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd620
//
// 005dd620  55                   push ebp
// 005dd621  8bec                 mov ebp, esp
// 005dd623  6aff                 push -1
// 005dd625  6830dd9300           push 0x93dd30
// 005dd62a  64a100000000         mov eax, dword ptr fs:[0]
// 005dd630  50                   push eax
// 005dd631  64892500000000       mov dword ptr fs:[0], esp
// 005dd638  83ec0c               sub esp, 0xc
// 005dd63b  53                   push ebx
// 005dd63c  56                   push esi
// 005dd63d  57                   push edi
// 005dd63e  8b7d08               mov edi, dword ptr [ebp + 8]
// 005dd641  8965f0               mov dword ptr [ebp - 0x10], esp
// 005dd644  8bf1                 mov esi, ecx
// 005dd646  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 005dd64c  7605                 jbe 0x5dd653
// 005dd64e  e80d4be6ff           call 0x442160
// 005dd653  8b460c               mov eax, dword ptr [esi + 0xc]
// 005dd656  85c0                 test eax, eax
// 005dd658  7416                 je 0x5dd670
// 005dd65a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005dd65d  2bc8                 sub ecx, eax
// 005dd65f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd664  f7e9                 imul ecx
// 005dd666  c1fa02               sar edx, 2
// 005dd669  8bc2                 mov eax, edx
// 005dd66b  c1e81f               shr eax, 0x1f
// 005dd66e  03c2                 add eax, edx
// 005dd670  3bc7                 cmp eax, edi
// 005dd672  0f8390000000         jae 0x5dd708
// 005dd678  6a00                 push 0
// 005dd67a  57                   push edi
// 005dd67b  e800a81b00           call 0x797e80
// 005dd680  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dd683  83c408               add esp, 8
// 005dd686  8945ec               mov dword ptr [ebp - 0x14], eax
// 005dd689  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005dd690  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005dd693  7606                 jbe 0x5dd69b
// 005dd695  ff1560b79800         call dword ptr [0x98b760]
// 005dd69b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005dd69e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005dd6a1  7606                 jbe 0x5dd6a9
// 005dd6a3  ff1560b79800         call dword ptr [0x98b760]
// 005dd6a9  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005dd6ac  c645e800             mov byte ptr [ebp - 0x18], 0
// 005dd6b0  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 005dd6b3  50                   push eax
// 005dd6b4  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005dd6b7  51                   push ecx
// 005dd6b8  8d5608               lea edx, [esi + 8]
// 005dd6bb  52                   push edx
// 005dd6bc  50                   push eax
// 005dd6bd  53                   push ebx
// 005dd6be  57                   push edi
// 005dd6bf  e8dcfdffff           call 0x5dd4a0
// 005dd6c4  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005dd6c7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005dd6ca  2bcb                 sub ecx, ebx
// 005dd6cc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd6d1  f7e9                 imul ecx
// 005dd6d3  c1fa02               sar edx, 2
// 005dd6d6  8bfa                 mov edi, edx
// 005dd6d8  c1ef1f               shr edi, 0x1f
// 005dd6db  83c418               add esp, 0x18
// 005dd6de  03fa                 add edi, edx
// 005dd6e0  85db                 test ebx, ebx
// 005dd6e2  7409                 je 0x5dd6ed
// 005dd6e4  53                   push ebx
// 005dd6e5  e870612100           call 0x7f385a
// 005dd6ea  83c404               add esp, 4
// 005dd6ed  8b4508               mov eax, dword ptr [ebp + 8]
// 005dd6f0  8d0c40               lea ecx, [eax + eax*2]
// 005dd6f3  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005dd6f6  8d14c8               lea edx, [eax + ecx*8]
// 005dd6f9  8d0c7f               lea ecx, [edi + edi*2]
// 005dd6fc  895614               mov dword ptr [esi + 0x14], edx
// 005dd6ff  8d14c8               lea edx, [eax + ecx*8]
// 005dd702  895610               mov dword ptr [esi + 0x10], edx
// 005dd705  89460c               mov dword ptr [esi + 0xc], eax
// 005dd708  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005dd70b  5f                   pop edi
// 005dd70c  5e                   pop esi
// 005dd70d  64890d00000000       mov dword ptr fs:[0], ecx
// 005dd714  5b                   pop ebx
// 005dd715  8be5                 mov esp, ebp
// 005dd717  5d                   pop ebp
// 005dd718  c20400               ret 4
// standard library vector<pod24> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
