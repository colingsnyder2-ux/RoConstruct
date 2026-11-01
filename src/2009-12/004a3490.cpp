// from server: 100% by auto
// roc 2009-12 004a3490  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3490
//
// 004a3490  55                   push ebp
// 004a3491  8bec                 mov ebp, esp
// 004a3493  6aff                 push -1
// 004a3495  6820099300           push 0x930920
// 004a349a  64a100000000         mov eax, dword ptr fs:[0]
// 004a34a0  50                   push eax
// 004a34a1  64892500000000       mov dword ptr fs:[0], esp
// 004a34a8  83ec0c               sub esp, 0xc
// 004a34ab  53                   push ebx
// 004a34ac  56                   push esi
// 004a34ad  57                   push edi
// 004a34ae  8b7d08               mov edi, dword ptr [ebp + 8]
// 004a34b1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a34b4  8bf1                 mov esi, ecx
// 004a34b6  81ff55555505         cmp edi, 0x5555555
// 004a34bc  7605                 jbe 0x4a34c3
// 004a34be  e89decf9ff           call 0x442160
// 004a34c3  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a34c6  85c0                 test eax, eax
// 004a34c8  7416                 je 0x4a34e0
// 004a34ca  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004a34cd  2bc8                 sub ecx, eax
// 004a34cf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a34d4  f7e9                 imul ecx
// 004a34d6  c1fa03               sar edx, 3
// 004a34d9  8bc2                 mov eax, edx
// 004a34db  c1e81f               shr eax, 0x1f
// 004a34de  03c2                 add eax, edx
// 004a34e0  3bc7                 cmp eax, edi
// 004a34e2  0f8394000000         jae 0x4a357c
// 004a34e8  6a00                 push 0
// 004a34ea  57                   push edi
// 004a34eb  e80081ffff           call 0x49b5f0
// 004a34f0  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a34f3  83c408               add esp, 8
// 004a34f6  8945ec               mov dword ptr [ebp - 0x14], eax
// 004a34f9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a3500  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004a3503  7606                 jbe 0x4a350b
// 004a3505  ff1560b79800         call dword ptr [0x98b760]
// 004a350b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a350e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a3511  7606                 jbe 0x4a3519
// 004a3513  ff1560b79800         call dword ptr [0x98b760]
// 004a3519  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004a351c  c645e800             mov byte ptr [ebp - 0x18], 0
// 004a3520  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a3523  50                   push eax
// 004a3524  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a3527  51                   push ecx
// 004a3528  8d5608               lea edx, [esi + 8]
// 004a352b  52                   push edx
// 004a352c  50                   push eax
// 004a352d  53                   push ebx
// 004a352e  57                   push edi
// 004a352f  e8cccaffff           call 0x4a0000
// 004a3534  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a3537  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004a353a  2bcb                 sub ecx, ebx
// 004a353c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a3541  f7e9                 imul ecx
// 004a3543  c1fa03               sar edx, 3
// 004a3546  8bfa                 mov edi, edx
// 004a3548  c1ef1f               shr edi, 0x1f
// 004a354b  83c418               add esp, 0x18
// 004a354e  03fa                 add edi, edx
// 004a3550  85db                 test ebx, ebx
// 004a3552  7409                 je 0x4a355d
// 004a3554  53                   push ebx
// 004a3555  e800033500           call 0x7f385a
// 004a355a  83c404               add esp, 4
// 004a355d  8b4508               mov eax, dword ptr [ebp + 8]
// 004a3560  8d0c40               lea ecx, [eax + eax*2]
// 004a3563  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a3566  c1e104               shl ecx, 4
// 004a3569  8d147f               lea edx, [edi + edi*2]
// 004a356c  03c8                 add ecx, eax
// 004a356e  c1e204               shl edx, 4
// 004a3571  03d0                 add edx, eax
// 004a3573  894e14               mov dword ptr [esi + 0x14], ecx
// 004a3576  895610               mov dword ptr [esi + 0x10], edx
// 004a3579  89460c               mov dword ptr [esi + 0xc], eax
// 004a357c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a357f  5f                   pop edi
// 004a3580  5e                   pop esi
// 004a3581  64890d00000000       mov dword ptr fs:[0], ecx
// 004a3588  5b                   pop ebx
// 004a3589  8be5                 mov esp, ebp
// 004a358b  5d                   pop ebp
// 004a358c  c20400               ret 4
// standard library vector<pod48> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
