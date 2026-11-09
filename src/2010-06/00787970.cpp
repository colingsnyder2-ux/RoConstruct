// from server: 100% by auto
// roc 2010-06 00787970  unit: RBX::HUMAN::GettingUp  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787970
//
// 00787970  55                   push ebp
// 00787971  8bec                 mov ebp, esp
// 00787973  6aff                 push -1
// 00787975  68f0ce9a00           push 0x9acef0
// 0078797a  64a100000000         mov eax, dword ptr fs:[0]
// 00787980  50                   push eax
// 00787981  64892500000000       mov dword ptr fs:[0], esp
// 00787988  83ec0c               sub esp, 0xc
// 0078798b  53                   push ebx
// 0078798c  56                   push esi
// 0078798d  57                   push edi
// 0078798e  8b7d08               mov edi, dword ptr [ebp + 8]
// 00787991  8965f0               mov dword ptr [ebp - 0x10], esp
// 00787994  8bf1                 mov esi, ecx
// 00787996  81ffcccccc0c         cmp edi, 0xccccccc
// 0078799c  7605                 jbe 0x7879a3
// 0078799e  e84dc4c9ff           call 0x423df0
// 007879a3  8b460c               mov eax, dword ptr [esi + 0xc]
// 007879a6  85c0                 test eax, eax
// 007879a8  7416                 je 0x7879c0
// 007879aa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007879ad  2bc8                 sub ecx, eax
// 007879af  b867666666           mov eax, 0x66666667
// 007879b4  f7e9                 imul ecx
// 007879b6  c1fa03               sar edx, 3
// 007879b9  8bc2                 mov eax, edx
// 007879bb  c1e81f               shr eax, 0x1f
// 007879be  03c2                 add eax, edx
// 007879c0  3bc7                 cmp eax, edi
// 007879c2  0f8390000000         jae 0x787a58
// 007879c8  6a00                 push 0
// 007879ca  57                   push edi
// 007879cb  e8a0ddfcff           call 0x755770
// 007879d0  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007879d3  83c408               add esp, 8
// 007879d6  8945ec               mov dword ptr [ebp - 0x14], eax
// 007879d9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007879e0  395e0c               cmp dword ptr [esi + 0xc], ebx
// 007879e3  7606                 jbe 0x7879eb
// 007879e5  ff150ca99e00         call dword ptr [0x9ea90c]
// 007879eb  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007879ee  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007879f1  7606                 jbe 0x7879f9
// 007879f3  ff150ca99e00         call dword ptr [0x9ea90c]
// 007879f9  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007879fc  c645e800             mov byte ptr [ebp - 0x18], 0
// 00787a00  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00787a03  50                   push eax
// 00787a04  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00787a07  51                   push ecx
// 00787a08  8d5608               lea edx, [esi + 8]
// 00787a0b  52                   push edx
// 00787a0c  50                   push eax
// 00787a0d  53                   push ebx
// 00787a0e  57                   push edi
// 00787a0f  e8fcf6ffff           call 0x787110
// 00787a14  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00787a17  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00787a1a  2bcb                 sub ecx, ebx
// 00787a1c  b867666666           mov eax, 0x66666667
// 00787a21  f7e9                 imul ecx
// 00787a23  c1fa03               sar edx, 3
// 00787a26  8bfa                 mov edi, edx
// 00787a28  c1ef1f               shr edi, 0x1f
// 00787a2b  83c418               add esp, 0x18
// 00787a2e  03fa                 add edi, edx
// 00787a30  85db                 test ebx, ebx
// 00787a32  7409                 je 0x787a3d
// 00787a34  53                   push ebx
// 00787a35  e860ff0100           call 0x7a799a
// 00787a3a  83c404               add esp, 4
// 00787a3d  8b4508               mov eax, dword ptr [ebp + 8]
// 00787a40  8d0c80               lea ecx, [eax + eax*4]
// 00787a43  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00787a46  8d1488               lea edx, [eax + ecx*4]
// 00787a49  8d0cbf               lea ecx, [edi + edi*4]
// 00787a4c  895614               mov dword ptr [esi + 0x14], edx
// 00787a4f  8d1488               lea edx, [eax + ecx*4]
// 00787a52  895610               mov dword ptr [esi + 0x10], edx
// 00787a55  89460c               mov dword ptr [esi + 0xc], eax
// 00787a58  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00787a5b  5f                   pop edi
// 00787a5c  5e                   pop esi
// 00787a5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00787a64  5b                   pop ebx
// 00787a65  8be5                 mov esp, ebp
// 00787a67  5d                   pop ebp
// 00787a68  c20400               ret 4
// standard library vector<pod20> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
