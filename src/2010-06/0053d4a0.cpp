// from server: 100% by auto
// roc 2010-06 0053d4a0  unit: RBX::ImmediateMeshGenAdapter  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d4a0
//
// 0053d4a0  55                   push ebp
// 0053d4a1  8bec                 mov ebp, esp
// 0053d4a3  6aff                 push -1
// 0053d4a5  68f0f79800           push 0x98f7f0
// 0053d4aa  64a100000000         mov eax, dword ptr fs:[0]
// 0053d4b0  50                   push eax
// 0053d4b1  64892500000000       mov dword ptr fs:[0], esp
// 0053d4b8  83ec0c               sub esp, 0xc
// 0053d4bb  53                   push ebx
// 0053d4bc  56                   push esi
// 0053d4bd  57                   push edi
// 0053d4be  8b7d08               mov edi, dword ptr [ebp + 8]
// 0053d4c1  8965f0               mov dword ptr [ebp - 0x10], esp
// 0053d4c4  8bf1                 mov esi, ecx
// 0053d4c6  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 0053d4cc  7605                 jbe 0x53d4d3
// 0053d4ce  e81d69eeff           call 0x423df0
// 0053d4d3  8b460c               mov eax, dword ptr [esi + 0xc]
// 0053d4d6  85c0                 test eax, eax
// 0053d4d8  7416                 je 0x53d4f0
// 0053d4da  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0053d4dd  2bc8                 sub ecx, eax
// 0053d4df  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d4e4  f7e9                 imul ecx
// 0053d4e6  c1fa02               sar edx, 2
// 0053d4e9  8bc2                 mov eax, edx
// 0053d4eb  c1e81f               shr eax, 0x1f
// 0053d4ee  03c2                 add eax, edx
// 0053d4f0  3bc7                 cmp eax, edi
// 0053d4f2  0f8390000000         jae 0x53d588
// 0053d4f8  6a00                 push 0
// 0053d4fa  57                   push edi
// 0053d4fb  e8e0311f00           call 0x7306e0
// 0053d500  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0053d503  83c408               add esp, 8
// 0053d506  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053d509  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053d510  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0053d513  7606                 jbe 0x53d51b
// 0053d515  ff150ca99e00         call dword ptr [0x9ea90c]
// 0053d51b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0053d51e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0053d521  7606                 jbe 0x53d529
// 0053d523  ff150ca99e00         call dword ptr [0x9ea90c]
// 0053d529  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053d52c  c645e800             mov byte ptr [ebp - 0x18], 0
// 0053d530  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0053d533  50                   push eax
// 0053d534  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0053d537  51                   push ecx
// 0053d538  8d5608               lea edx, [esi + 8]
// 0053d53b  52                   push edx
// 0053d53c  50                   push eax
// 0053d53d  53                   push ebx
// 0053d53e  57                   push edi
// 0053d53f  e81cfeffff           call 0x53d360
// 0053d544  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053d547  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053d54a  2bcb                 sub ecx, ebx
// 0053d54c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d551  f7e9                 imul ecx
// 0053d553  c1fa02               sar edx, 2
// 0053d556  8bfa                 mov edi, edx
// 0053d558  c1ef1f               shr edi, 0x1f
// 0053d55b  83c418               add esp, 0x18
// 0053d55e  03fa                 add edi, edx
// 0053d560  85db                 test ebx, ebx
// 0053d562  7409                 je 0x53d56d
// 0053d564  53                   push ebx
// 0053d565  e830a42600           call 0x7a799a
// 0053d56a  83c404               add esp, 4
// 0053d56d  8b4508               mov eax, dword ptr [ebp + 8]
// 0053d570  8d0c40               lea ecx, [eax + eax*2]
// 0053d573  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0053d576  8d14c8               lea edx, [eax + ecx*8]
// 0053d579  8d0c7f               lea ecx, [edi + edi*2]
// 0053d57c  895614               mov dword ptr [esi + 0x14], edx
// 0053d57f  8d14c8               lea edx, [eax + ecx*8]
// 0053d582  895610               mov dword ptr [esi + 0x10], edx
// 0053d585  89460c               mov dword ptr [esi + 0xc], eax
// 0053d588  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053d58b  5f                   pop edi
// 0053d58c  5e                   pop esi
// 0053d58d  64890d00000000       mov dword ptr fs:[0], ecx
// 0053d594  5b                   pop ebx
// 0053d595  8be5                 mov esp, ebp
// 0053d597  5d                   pop ebp
// 0053d598  c20400               ret 4
// standard library vector<pod24> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
