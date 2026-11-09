// from server: 100% by auto
// roc 2008-06 004dd7d0  unit: RBX::RenderBase::Mesh::Level  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd7d0
//
// 004dd7d0  55                   push ebp
// 004dd7d1  8bec                 mov ebp, esp
// 004dd7d3  6aff                 push -1
// 004dd7d5  6890a27c00           push 0x7ca290
// 004dd7da  64a100000000         mov eax, dword ptr fs:[0]
// 004dd7e0  50                   push eax
// 004dd7e1  64892500000000       mov dword ptr fs:[0], esp
// 004dd7e8  83ec0c               sub esp, 0xc
// 004dd7eb  53                   push ebx
// 004dd7ec  56                   push esi
// 004dd7ed  57                   push edi
// 004dd7ee  8b7d08               mov edi, dword ptr [ebp + 8]
// 004dd7f1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004dd7f4  8bf1                 mov esi, ecx
// 004dd7f6  81ff55555515         cmp edi, 0x15555555
// 004dd7fc  7605                 jbe 0x4dd803
// 004dd7fe  e83d95feff           call 0x4c6d40
// 004dd803  8b460c               mov eax, dword ptr [esi + 0xc]
// 004dd806  85c0                 test eax, eax
// 004dd808  7415                 je 0x4dd81f
// 004dd80a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004dd80d  2bc8                 sub ecx, eax
// 004dd80f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004dd814  f7e9                 imul ecx
// 004dd816  d1fa                 sar edx, 1
// 004dd818  8bc2                 mov eax, edx
// 004dd81a  c1e81f               shr eax, 0x1f
// 004dd81d  03c2                 add eax, edx
// 004dd81f  3bc7                 cmp eax, edi
// 004dd821  0f838f000000         jae 0x4dd8b6
// 004dd827  6a00                 push 0
// 004dd829  57                   push edi
// 004dd82a  e881fc1a00           call 0x68d4b0
// 004dd82f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004dd832  83c408               add esp, 8
// 004dd835  8945ec               mov dword ptr [ebp - 0x14], eax
// 004dd838  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004dd83f  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004dd842  7606                 jbe 0x4dd84a
// 004dd844  ff1590288000         call dword ptr [0x802890]
// 004dd84a  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004dd84d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004dd850  7606                 jbe 0x4dd858
// 004dd852  ff1590288000         call dword ptr [0x802890]
// 004dd858  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004dd85b  c645e800             mov byte ptr [ebp - 0x18], 0
// 004dd85f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004dd862  50                   push eax
// 004dd863  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004dd866  51                   push ecx
// 004dd867  8d5608               lea edx, [esi + 8]
// 004dd86a  52                   push edx
// 004dd86b  50                   push eax
// 004dd86c  53                   push ebx
// 004dd86d  57                   push edi
// 004dd86e  e8fdedffff           call 0x4dc670
// 004dd873  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004dd876  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004dd879  2bcb                 sub ecx, ebx
// 004dd87b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004dd880  f7e9                 imul ecx
// 004dd882  d1fa                 sar edx, 1
// 004dd884  8bfa                 mov edi, edx
// 004dd886  c1ef1f               shr edi, 0x1f
// 004dd889  83c418               add esp, 0x18
// 004dd88c  03fa                 add edi, edx
// 004dd88e  85db                 test ebx, ebx
// 004dd890  7409                 je 0x4dd89b
// 004dd892  53                   push ebx
// 004dd893  e8e22d1c00           call 0x6a067a
// 004dd898  83c404               add esp, 4
// 004dd89b  8b4508               mov eax, dword ptr [ebp + 8]
// 004dd89e  8d0c40               lea ecx, [eax + eax*2]
// 004dd8a1  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004dd8a4  8d1488               lea edx, [eax + ecx*4]
// 004dd8a7  8d0c7f               lea ecx, [edi + edi*2]
// 004dd8aa  895614               mov dword ptr [esi + 0x14], edx
// 004dd8ad  8d1488               lea edx, [eax + ecx*4]
// 004dd8b0  895610               mov dword ptr [esi + 0x10], edx
// 004dd8b3  89460c               mov dword ptr [esi + 0xc], eax
// 004dd8b6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004dd8b9  5f                   pop edi
// 004dd8ba  5e                   pop esi
// 004dd8bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd8c2  5b                   pop ebx
// 004dd8c3  8be5                 mov esp, ebp
// 004dd8c5  5d                   pop ebp
// 004dd8c6  c20400               ret 4
// standard library vector<pod12> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
