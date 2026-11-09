// from server: 100% by auto
// roc 2010-06 00955850  unit: seg_00950000  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955850
//
// 00955850  55                   push ebp
// 00955851  8bec                 mov ebp, esp
// 00955853  6aff                 push -1
// 00955855  6870209c00           push 0x9c2070
// 0095585a  64a100000000         mov eax, dword ptr fs:[0]
// 00955860  50                   push eax
// 00955861  64892500000000       mov dword ptr fs:[0], esp
// 00955868  83ec0c               sub esp, 0xc
// 0095586b  53                   push ebx
// 0095586c  56                   push esi
// 0095586d  57                   push edi
// 0095586e  8b7d08               mov edi, dword ptr [ebp + 8]
// 00955871  8965f0               mov dword ptr [ebp - 0x10], esp
// 00955874  8bf1                 mov esi, ecx
// 00955876  81ff55555515         cmp edi, 0x15555555
// 0095587c  7605                 jbe 0x955883
// 0095587e  e86de5acff           call 0x423df0
// 00955883  8b460c               mov eax, dword ptr [esi + 0xc]
// 00955886  85c0                 test eax, eax
// 00955888  7415                 je 0x95589f
// 0095588a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0095588d  2bc8                 sub ecx, eax
// 0095588f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955894  f7e9                 imul ecx
// 00955896  d1fa                 sar edx, 1
// 00955898  8bc2                 mov eax, edx
// 0095589a  c1e81f               shr eax, 0x1f
// 0095589d  03c2                 add eax, edx
// 0095589f  3bc7                 cmp eax, edi
// 009558a1  0f838f000000         jae 0x955936
// 009558a7  6a00                 push 0
// 009558a9  57                   push edi
// 009558aa  e8e191f9ff           call 0x8eea90
// 009558af  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 009558b2  83c408               add esp, 8
// 009558b5  8945ec               mov dword ptr [ebp - 0x14], eax
// 009558b8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 009558bf  395e0c               cmp dword ptr [esi + 0xc], ebx
// 009558c2  7606                 jbe 0x9558ca
// 009558c4  ff150ca99e00         call dword ptr [0x9ea90c]
// 009558ca  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 009558cd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 009558d0  7606                 jbe 0x9558d8
// 009558d2  ff150ca99e00         call dword ptr [0x9ea90c]
// 009558d8  8b4d08               mov ecx, dword ptr [ebp + 8]
// 009558db  c645e800             mov byte ptr [ebp - 0x18], 0
// 009558df  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 009558e2  50                   push eax
// 009558e3  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 009558e6  51                   push ecx
// 009558e7  8d5608               lea edx, [esi + 8]
// 009558ea  52                   push edx
// 009558eb  50                   push eax
// 009558ec  53                   push ebx
// 009558ed  57                   push edi
// 009558ee  e81dd1ffff           call 0x952a10
// 009558f3  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 009558f6  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 009558f9  2bcb                 sub ecx, ebx
// 009558fb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955900  f7e9                 imul ecx
// 00955902  d1fa                 sar edx, 1
// 00955904  8bfa                 mov edi, edx
// 00955906  c1ef1f               shr edi, 0x1f
// 00955909  83c418               add esp, 0x18
// 0095590c  03fa                 add edi, edx
// 0095590e  85db                 test ebx, ebx
// 00955910  7409                 je 0x95591b
// 00955912  53                   push ebx
// 00955913  e88220e5ff           call 0x7a799a
// 00955918  83c404               add esp, 4
// 0095591b  8b4508               mov eax, dword ptr [ebp + 8]
// 0095591e  8d0c40               lea ecx, [eax + eax*2]
// 00955921  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00955924  8d1488               lea edx, [eax + ecx*4]
// 00955927  8d0c7f               lea ecx, [edi + edi*2]
// 0095592a  895614               mov dword ptr [esi + 0x14], edx
// 0095592d  8d1488               lea edx, [eax + ecx*4]
// 00955930  895610               mov dword ptr [esi + 0x10], edx
// 00955933  89460c               mov dword ptr [esi + 0xc], eax
// 00955936  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00955939  5f                   pop edi
// 0095593a  5e                   pop esi
// 0095593b  64890d00000000       mov dword ptr fs:[0], ecx
// 00955942  5b                   pop ebx
// 00955943  8be5                 mov esp, ebp
// 00955945  5d                   pop ebp
// 00955946  c20400               ret 4
// standard library vector<pod12> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
