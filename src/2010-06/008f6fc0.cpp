// from server: 100% by auto
// roc 2010-06 008f6fc0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6fc0
//
// 008f6fc0  55                   push ebp
// 008f6fc1  8bec                 mov ebp, esp
// 008f6fc3  6aff                 push -1
// 008f6fc5  68b0009c00           push 0x9c00b0
// 008f6fca  64a100000000         mov eax, dword ptr fs:[0]
// 008f6fd0  50                   push eax
// 008f6fd1  64892500000000       mov dword ptr fs:[0], esp
// 008f6fd8  83ec0c               sub esp, 0xc
// 008f6fdb  53                   push ebx
// 008f6fdc  56                   push esi
// 008f6fdd  57                   push edi
// 008f6fde  8b7d08               mov edi, dword ptr [ebp + 8]
// 008f6fe1  8965f0               mov dword ptr [ebp - 0x10], esp
// 008f6fe4  8bf1                 mov esi, ecx
// 008f6fe6  81ff55555505         cmp edi, 0x5555555
// 008f6fec  7605                 jbe 0x8f6ff3
// 008f6fee  e8fdcdb2ff           call 0x423df0
// 008f6ff3  8b460c               mov eax, dword ptr [esi + 0xc]
// 008f6ff6  85c0                 test eax, eax
// 008f6ff8  7416                 je 0x8f7010
// 008f6ffa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008f6ffd  2bc8                 sub ecx, eax
// 008f6fff  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008f7004  f7e9                 imul ecx
// 008f7006  c1fa03               sar edx, 3
// 008f7009  8bc2                 mov eax, edx
// 008f700b  c1e81f               shr eax, 0x1f
// 008f700e  03c2                 add eax, edx
// 008f7010  3bc7                 cmp eax, edi
// 008f7012  0f8394000000         jae 0x8f70ac
// 008f7018  6a00                 push 0
// 008f701a  57                   push edi
// 008f701b  e8b0e7e5ff           call 0x7557d0
// 008f7020  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008f7023  83c408               add esp, 8
// 008f7026  8945ec               mov dword ptr [ebp - 0x14], eax
// 008f7029  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008f7030  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008f7033  7606                 jbe 0x8f703b
// 008f7035  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f703b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008f703e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008f7041  7606                 jbe 0x8f7049
// 008f7043  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f7049  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008f704c  c645e800             mov byte ptr [ebp - 0x18], 0
// 008f7050  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 008f7053  50                   push eax
// 008f7054  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008f7057  51                   push ecx
// 008f7058  8d5608               lea edx, [esi + 8]
// 008f705b  52                   push edx
// 008f705c  50                   push eax
// 008f705d  53                   push ebx
// 008f705e  57                   push edi
// 008f705f  e8bcccffff           call 0x8f3d20
// 008f7064  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008f7067  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008f706a  2bcb                 sub ecx, ebx
// 008f706c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008f7071  f7e9                 imul ecx
// 008f7073  c1fa03               sar edx, 3
// 008f7076  8bfa                 mov edi, edx
// 008f7078  c1ef1f               shr edi, 0x1f
// 008f707b  83c418               add esp, 0x18
// 008f707e  03fa                 add edi, edx
// 008f7080  85db                 test ebx, ebx
// 008f7082  7409                 je 0x8f708d
// 008f7084  53                   push ebx
// 008f7085  e81009ebff           call 0x7a799a
// 008f708a  83c404               add esp, 4
// 008f708d  8b4508               mov eax, dword ptr [ebp + 8]
// 008f7090  8d0c40               lea ecx, [eax + eax*2]
// 008f7093  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008f7096  c1e104               shl ecx, 4
// 008f7099  8d147f               lea edx, [edi + edi*2]
// 008f709c  03c8                 add ecx, eax
// 008f709e  c1e204               shl edx, 4
// 008f70a1  03d0                 add edx, eax
// 008f70a3  894e14               mov dword ptr [esi + 0x14], ecx
// 008f70a6  895610               mov dword ptr [esi + 0x10], edx
// 008f70a9  89460c               mov dword ptr [esi + 0xc], eax
// 008f70ac  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008f70af  5f                   pop edi
// 008f70b0  5e                   pop esi
// 008f70b1  64890d00000000       mov dword ptr fs:[0], ecx
// 008f70b8  5b                   pop ebx
// 008f70b9  8be5                 mov esp, ebp
// 008f70bb  5d                   pop ebp
// 008f70bc  c20400               ret 4
// standard library vector<pod48> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
