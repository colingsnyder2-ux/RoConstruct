// from server: 100% by auto
// roc 2010-06 00704c70  unit: RBX::VInstance::?$NonFactoryProduct  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704c70
//
// 00704c70  55                   push ebp
// 00704c71  8bec                 mov ebp, esp
// 00704c73  6aff                 push -1
// 00704c75  68f0749a00           push 0x9a74f0
// 00704c7a  64a100000000         mov eax, dword ptr fs:[0]
// 00704c80  50                   push eax
// 00704c81  64892500000000       mov dword ptr fs:[0], esp
// 00704c88  83ec0c               sub esp, 0xc
// 00704c8b  53                   push ebx
// 00704c8c  56                   push esi
// 00704c8d  57                   push edi
// 00704c8e  8b7d08               mov edi, dword ptr [ebp + 8]
// 00704c91  8965f0               mov dword ptr [ebp - 0x10], esp
// 00704c94  8bf1                 mov esi, ecx
// 00704c96  81ffc7711c07         cmp edi, 0x71c71c7
// 00704c9c  7605                 jbe 0x704ca3
// 00704c9e  e84df1d1ff           call 0x423df0
// 00704ca3  8b460c               mov eax, dword ptr [esi + 0xc]
// 00704ca6  85c0                 test eax, eax
// 00704ca8  7416                 je 0x704cc0
// 00704caa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00704cad  2bc8                 sub ecx, eax
// 00704caf  b8398ee338           mov eax, 0x38e38e39
// 00704cb4  f7e9                 imul ecx
// 00704cb6  c1fa03               sar edx, 3
// 00704cb9  8bc2                 mov eax, edx
// 00704cbb  c1e81f               shr eax, 0x1f
// 00704cbe  03c2                 add eax, edx
// 00704cc0  3bc7                 cmp eax, edi
// 00704cc2  0f8390000000         jae 0x704d58
// 00704cc8  6a00                 push 0
// 00704cca  57                   push edi
// 00704ccb  e890eeffff           call 0x703b60
// 00704cd0  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00704cd3  83c408               add esp, 8
// 00704cd6  8945ec               mov dword ptr [ebp - 0x14], eax
// 00704cd9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00704ce0  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00704ce3  7606                 jbe 0x704ceb
// 00704ce5  ff150ca99e00         call dword ptr [0x9ea90c]
// 00704ceb  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00704cee  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00704cf1  7606                 jbe 0x704cf9
// 00704cf3  ff150ca99e00         call dword ptr [0x9ea90c]
// 00704cf9  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00704cfc  c645e800             mov byte ptr [ebp - 0x18], 0
// 00704d00  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00704d03  50                   push eax
// 00704d04  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00704d07  51                   push ecx
// 00704d08  8d5608               lea edx, [esi + 8]
// 00704d0b  52                   push edx
// 00704d0c  50                   push eax
// 00704d0d  53                   push ebx
// 00704d0e  57                   push edi
// 00704d0f  e89cf6ffff           call 0x7043b0
// 00704d14  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00704d17  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00704d1a  2bcb                 sub ecx, ebx
// 00704d1c  b8398ee338           mov eax, 0x38e38e39
// 00704d21  f7e9                 imul ecx
// 00704d23  c1fa03               sar edx, 3
// 00704d26  8bfa                 mov edi, edx
// 00704d28  c1ef1f               shr edi, 0x1f
// 00704d2b  83c418               add esp, 0x18
// 00704d2e  03fa                 add edi, edx
// 00704d30  85db                 test ebx, ebx
// 00704d32  7409                 je 0x704d3d
// 00704d34  53                   push ebx
// 00704d35  e8602c0a00           call 0x7a799a
// 00704d3a  83c404               add esp, 4
// 00704d3d  8b4508               mov eax, dword ptr [ebp + 8]
// 00704d40  8d0cc0               lea ecx, [eax + eax*8]
// 00704d43  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00704d46  8d1488               lea edx, [eax + ecx*4]
// 00704d49  8d0cff               lea ecx, [edi + edi*8]
// 00704d4c  895614               mov dword ptr [esi + 0x14], edx
// 00704d4f  8d1488               lea edx, [eax + ecx*4]
// 00704d52  895610               mov dword ptr [esi + 0x10], edx
// 00704d55  89460c               mov dword ptr [esi + 0xc], eax
// 00704d58  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00704d5b  5f                   pop edi
// 00704d5c  5e                   pop esi
// 00704d5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00704d64  5b                   pop ebx
// 00704d65  8be5                 mov esp, ebp
// 00704d67  5d                   pop ebp
// 00704d68  c20400               ret 4
// standard library vector<pod36> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
