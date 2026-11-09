// from server: 100% by auto
// roc 2009-12 004a3130  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3130
//
// 004a3130  55                   push ebp
// 004a3131  8bec                 mov ebp, esp
// 004a3133  6aff                 push -1
// 004a3135  68f0089300           push 0x9308f0
// 004a313a  64a100000000         mov eax, dword ptr fs:[0]
// 004a3140  50                   push eax
// 004a3141  64892500000000       mov dword ptr fs:[0], esp
// 004a3148  83ec0c               sub esp, 0xc
// 004a314b  53                   push ebx
// 004a314c  56                   push esi
// 004a314d  57                   push edi
// 004a314e  8b7d08               mov edi, dword ptr [ebp + 8]
// 004a3151  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a3154  8bf1                 mov esi, ecx
// 004a3156  81ffc7711c07         cmp edi, 0x71c71c7
// 004a315c  7605                 jbe 0x4a3163
// 004a315e  e8fdeff9ff           call 0x442160
// 004a3163  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a3166  85c0                 test eax, eax
// 004a3168  7416                 je 0x4a3180
// 004a316a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004a316d  2bc8                 sub ecx, eax
// 004a316f  b8398ee338           mov eax, 0x38e38e39
// 004a3174  f7e9                 imul ecx
// 004a3176  c1fa03               sar edx, 3
// 004a3179  8bc2                 mov eax, edx
// 004a317b  c1e81f               shr eax, 0x1f
// 004a317e  03c2                 add eax, edx
// 004a3180  3bc7                 cmp eax, edi
// 004a3182  0f8390000000         jae 0x4a3218
// 004a3188  6a00                 push 0
// 004a318a  57                   push edi
// 004a318b  e83083ffff           call 0x49b4c0
// 004a3190  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a3193  83c408               add esp, 8
// 004a3196  8945ec               mov dword ptr [ebp - 0x14], eax
// 004a3199  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a31a0  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004a31a3  7606                 jbe 0x4a31ab
// 004a31a5  ff1560b79800         call dword ptr [0x98b760]
// 004a31ab  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a31ae  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a31b1  7606                 jbe 0x4a31b9
// 004a31b3  ff1560b79800         call dword ptr [0x98b760]
// 004a31b9  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004a31bc  c645e800             mov byte ptr [ebp - 0x18], 0
// 004a31c0  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a31c3  50                   push eax
// 004a31c4  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a31c7  51                   push ecx
// 004a31c8  8d5608               lea edx, [esi + 8]
// 004a31cb  52                   push edx
// 004a31cc  50                   push eax
// 004a31cd  53                   push ebx
// 004a31ce  57                   push edi
// 004a31cf  e8fcb8ffff           call 0x49ead0
// 004a31d4  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a31d7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004a31da  2bcb                 sub ecx, ebx
// 004a31dc  b8398ee338           mov eax, 0x38e38e39
// 004a31e1  f7e9                 imul ecx
// 004a31e3  c1fa03               sar edx, 3
// 004a31e6  8bfa                 mov edi, edx
// 004a31e8  c1ef1f               shr edi, 0x1f
// 004a31eb  83c418               add esp, 0x18
// 004a31ee  03fa                 add edi, edx
// 004a31f0  85db                 test ebx, ebx
// 004a31f2  7409                 je 0x4a31fd
// 004a31f4  53                   push ebx
// 004a31f5  e860063500           call 0x7f385a
// 004a31fa  83c404               add esp, 4
// 004a31fd  8b4508               mov eax, dword ptr [ebp + 8]
// 004a3200  8d0cc0               lea ecx, [eax + eax*8]
// 004a3203  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a3206  8d1488               lea edx, [eax + ecx*4]
// 004a3209  8d0cff               lea ecx, [edi + edi*8]
// 004a320c  895614               mov dword ptr [esi + 0x14], edx
// 004a320f  8d1488               lea edx, [eax + ecx*4]
// 004a3212  895610               mov dword ptr [esi + 0x10], edx
// 004a3215  89460c               mov dword ptr [esi + 0xc], eax
// 004a3218  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a321b  5f                   pop edi
// 004a321c  5e                   pop esi
// 004a321d  64890d00000000       mov dword ptr fs:[0], ecx
// 004a3224  5b                   pop ebx
// 004a3225  8be5                 mov esp, ebp
// 004a3227  5d                   pop ebp
// 004a3228  c20400               ret 4
// standard library vector<pod36> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
