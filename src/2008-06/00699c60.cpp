// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00699c60  unit: Ogre::RbxSceneManager  size: 354 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00699c60
//
// 00699c60  55                   push ebp
// 00699c61  8bec                 mov ebp, esp
// 00699c63  6aff                 push -1
// 00699c65  6890e87d00           push 0x7de890
// 00699c6a  64a100000000         mov eax, dword ptr fs:[0]
// 00699c70  50                   push eax
// 00699c71  64892500000000       mov dword ptr fs:[0], esp
// 00699c78  83ec18               sub esp, 0x18
// 00699c7b  53                   push ebx
// 00699c7c  56                   push esi
// 00699c7d  8bf1                 mov esi, ecx
// 00699c7f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00699c82  57                   push edi
// 00699c83  8965f0               mov dword ptr [ebp - 0x10], esp
// 00699c86  85c9                 test ecx, ecx
// 00699c88  7505                 jne 0x699c8f
// 00699c8a  894dec               mov dword ptr [ebp - 0x14], ecx
// 00699c8d  eb18                 jmp 0x699ca7
// 00699c8f  8b5614               mov edx, dword ptr [esi + 0x14]
// 00699c92  2bd1                 sub edx, ecx
// 00699c94  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699c99  f7ea                 imul edx
// 00699c9b  d1fa                 sar edx, 1
// 00699c9d  8bc2                 mov eax, edx
// 00699c9f  c1e81f               shr eax, 0x1f
// 00699ca2  03c2                 add eax, edx
// 00699ca4  8945ec               mov dword ptr [ebp - 0x14], eax
// 00699ca7  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00699caa  85ff                 test edi, edi
// 00699cac  0f8418020000         je 0x699eca
// 00699cb2  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00699cb5  8bd3                 mov edx, ebx
// 00699cb7  2bd1                 sub edx, ecx
// 00699cb9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699cbe  f7ea                 imul edx
// 00699cc0  d1fa                 sar edx, 1
// 00699cc2  8bc2                 mov eax, edx
// 00699cc4  c1e81f               shr eax, 0x1f
// 00699cc7  03c2                 add eax, edx
// 00699cc9  b955555515           mov ecx, 0x15555555
// 00699cce  2bc8                 sub ecx, eax
// 00699cd0  3bcf                 cmp ecx, edi
// 00699cd2  7305                 jae 0x699cd9
// 00699cd4  e867d0e2ff           call 0x4c6d40
// 00699cd9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00699cdc  03c7                 add eax, edi
// 00699cde  3bc8                 cmp ecx, eax
// 00699ce0  0f83f1000000         jae 0x699dd7
// 00699ce6  8bd1                 mov edx, ecx
// 00699ce8  d1ea                 shr edx, 1
// 00699cea  bb55555515           mov ebx, 0x15555555
// 00699cef  2bda                 sub ebx, edx
// 00699cf1  3bd9                 cmp ebx, ecx
// 00699cf3  730c                 jae 0x699d01
// 00699cf5  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00699cfc  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00699cff  eb05                 jmp 0x699d06
// 00699d01  03ca                 add ecx, edx
// 00699d03  894dec               mov dword ptr [ebp - 0x14], ecx
// 00699d06  3bc8                 cmp ecx, eax
// 00699d08  7305                 jae 0x699d0f
// 00699d0a  8945ec               mov dword ptr [ebp - 0x14], eax
// 00699d0d  8bc8                 mov ecx, eax
// 00699d0f  6a00                 push 0
// 00699d11  51                   push ecx
// 00699d12  e89937ffff           call 0x68d4b0
// 00699d17  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00699d1a  c645e800             mov byte ptr [ebp - 0x18], 0
// 00699d1e  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00699d21  52                   push edx
// 00699d22  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00699d25  52                   push edx
// 00699d26  8d5e08               lea ebx, [esi + 8]
// 00699d29  53                   push ebx
// 00699d2a  50                   push eax
// 00699d2b  894510               mov dword ptr [ebp + 0x10], eax
// 00699d2e  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00699d31  50                   push eax
// 00699d32  51                   push ecx
// 00699d33  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00699d3a  e81146ffff           call 0x68e350
// 00699d3f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00699d42  83c420               add esp, 0x20
// 00699d45  51                   push ecx
// 00699d46  57                   push edi
// 00699d47  50                   push eax
// 00699d48  8bce                 mov ecx, esi
// 00699d4a  e861a1ffff           call 0x693eb0
// 00699d4f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00699d52  c6451400             mov byte ptr [ebp + 0x14], 0
// 00699d56  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00699d59  52                   push edx
// 00699d5a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00699d5d  52                   push edx
// 00699d5e  53                   push ebx
// 00699d5f  50                   push eax
// 00699d60  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00699d63  51                   push ecx
// 00699d64  50                   push eax
// 00699d65  e8e645ffff           call 0x68e350
// 00699d6a  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00699d6d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00699d70  2bcb                 sub ecx, ebx
// 00699d72  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699d77  f7e9                 imul ecx
// 00699d79  d1fa                 sar edx, 1
// 00699d7b  8bca                 mov ecx, edx
// 00699d7d  c1e91f               shr ecx, 0x1f
// 00699d80  03ca                 add ecx, edx
// 00699d82  83c418               add esp, 0x18
// 00699d85  03f9                 add edi, ecx
// 00699d87  85db                 test ebx, ebx
// 00699d89  7409                 je 0x699d94
// 00699d8b  53                   push ebx
// 00699d8c  e8e9680000           call 0x6a067a
// 00699d91  83c404               add esp, 4
// 00699d94  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00699d97  8d1440               lea edx, [eax + eax*2]
// 00699d9a  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00699d9d  8d0c90               lea ecx, [eax + edx*4]
// 00699da0  8d147f               lea edx, [edi + edi*2]
// 00699da3  894e14               mov dword ptr [esi + 0x14], ecx
// 00699da6  8d0c90               lea ecx, [eax + edx*4]
// 00699da9  894e10               mov dword ptr [esi + 0x10], ecx
// 00699dac  89460c               mov dword ptr [esi + 0xc], eax
// 00699daf  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00699db2  64890d00000000       mov dword ptr fs:[0], ecx
// 00699db9  5f                   pop edi
// 00699dba  5e                   pop esi
// 00699dbb  5b                   pop ebx
// 00699dbc  8be5                 mov esp, ebp
// 00699dbe  5d                   pop ebp
// 00699dbf  c21000               ret 0x10
// standard library vector<pod12> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
