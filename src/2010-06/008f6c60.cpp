// from server: 100% by auto
// roc 2010-06 008f6c60  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6c60
//
// 008f6c60  55                   push ebp
// 008f6c61  8bec                 mov ebp, esp
// 008f6c63  6aff                 push -1
// 008f6c65  6880009c00           push 0x9c0080
// 008f6c6a  64a100000000         mov eax, dword ptr fs:[0]
// 008f6c70  50                   push eax
// 008f6c71  64892500000000       mov dword ptr fs:[0], esp
// 008f6c78  83ec0c               sub esp, 0xc
// 008f6c7b  53                   push ebx
// 008f6c7c  56                   push esi
// 008f6c7d  57                   push edi
// 008f6c7e  8b7d08               mov edi, dword ptr [ebp + 8]
// 008f6c81  8965f0               mov dword ptr [ebp - 0x10], esp
// 008f6c84  8bf1                 mov esi, ecx
// 008f6c86  81ffc7711c07         cmp edi, 0x71c71c7
// 008f6c8c  7605                 jbe 0x8f6c93
// 008f6c8e  e85dd1b2ff           call 0x423df0
// 008f6c93  8b460c               mov eax, dword ptr [esi + 0xc]
// 008f6c96  85c0                 test eax, eax
// 008f6c98  7416                 je 0x8f6cb0
// 008f6c9a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008f6c9d  2bc8                 sub ecx, eax
// 008f6c9f  b8398ee338           mov eax, 0x38e38e39
// 008f6ca4  f7e9                 imul ecx
// 008f6ca6  c1fa03               sar edx, 3
// 008f6ca9  8bc2                 mov eax, edx
// 008f6cab  c1e81f               shr eax, 0x1f
// 008f6cae  03c2                 add eax, edx
// 008f6cb0  3bc7                 cmp eax, edi
// 008f6cb2  0f8390000000         jae 0x8f6d48
// 008f6cb8  6a00                 push 0
// 008f6cba  57                   push edi
// 008f6cbb  e8a0cee0ff           call 0x703b60
// 008f6cc0  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008f6cc3  83c408               add esp, 8
// 008f6cc6  8945ec               mov dword ptr [ebp - 0x14], eax
// 008f6cc9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008f6cd0  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008f6cd3  7606                 jbe 0x8f6cdb
// 008f6cd5  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f6cdb  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008f6cde  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008f6ce1  7606                 jbe 0x8f6ce9
// 008f6ce3  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f6ce9  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008f6cec  c645e800             mov byte ptr [ebp - 0x18], 0
// 008f6cf0  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 008f6cf3  50                   push eax
// 008f6cf4  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008f6cf7  51                   push ecx
// 008f6cf8  8d5608               lea edx, [esi + 8]
// 008f6cfb  52                   push edx
// 008f6cfc  50                   push eax
// 008f6cfd  53                   push ebx
// 008f6cfe  57                   push edi
// 008f6cff  e8ecbaffff           call 0x8f27f0
// 008f6d04  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008f6d07  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008f6d0a  2bcb                 sub ecx, ebx
// 008f6d0c  b8398ee338           mov eax, 0x38e38e39
// 008f6d11  f7e9                 imul ecx
// 008f6d13  c1fa03               sar edx, 3
// 008f6d16  8bfa                 mov edi, edx
// 008f6d18  c1ef1f               shr edi, 0x1f
// 008f6d1b  83c418               add esp, 0x18
// 008f6d1e  03fa                 add edi, edx
// 008f6d20  85db                 test ebx, ebx
// 008f6d22  7409                 je 0x8f6d2d
// 008f6d24  53                   push ebx
// 008f6d25  e8700cebff           call 0x7a799a
// 008f6d2a  83c404               add esp, 4
// 008f6d2d  8b4508               mov eax, dword ptr [ebp + 8]
// 008f6d30  8d0cc0               lea ecx, [eax + eax*8]
// 008f6d33  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008f6d36  8d1488               lea edx, [eax + ecx*4]
// 008f6d39  8d0cff               lea ecx, [edi + edi*8]
// 008f6d3c  895614               mov dword ptr [esi + 0x14], edx
// 008f6d3f  8d1488               lea edx, [eax + ecx*4]
// 008f6d42  895610               mov dword ptr [esi + 0x10], edx
// 008f6d45  89460c               mov dword ptr [esi + 0xc], eax
// 008f6d48  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008f6d4b  5f                   pop edi
// 008f6d4c  5e                   pop esi
// 008f6d4d  64890d00000000       mov dword ptr fs:[0], ecx
// 008f6d54  5b                   pop ebx
// 008f6d55  8be5                 mov esp, ebp
// 008f6d57  5d                   pop ebp
// 008f6d58  c20400               ret 4
// standard library vector<pod36> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
