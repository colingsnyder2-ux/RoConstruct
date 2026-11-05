// from server: 100% by auto
// roc 2010-06 00904b00  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904b00
//
// 00904b00  55                   push ebp
// 00904b01  8bec                 mov ebp, esp
// 00904b03  6aff                 push -1
// 00904b05  68c00a9c00           push 0x9c0ac0
// 00904b0a  64a100000000         mov eax, dword ptr fs:[0]
// 00904b10  50                   push eax
// 00904b11  64892500000000       mov dword ptr fs:[0], esp
// 00904b18  83ec18               sub esp, 0x18
// 00904b1b  53                   push ebx
// 00904b1c  56                   push esi
// 00904b1d  8bf1                 mov esi, ecx
// 00904b1f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00904b22  57                   push edi
// 00904b23  8965f0               mov dword ptr [ebp - 0x10], esp
// 00904b26  85d2                 test edx, edx
// 00904b28  7504                 jne 0x904b2e
// 00904b2a  33c9                 xor ecx, ecx
// 00904b2c  eb0a                 jmp 0x904b38
// 00904b2e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00904b31  2bc2                 sub eax, edx
// 00904b33  c1f804               sar eax, 4
// 00904b36  8bc8                 mov ecx, eax
// 00904b38  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00904b3b  85ff                 test edi, edi
// 00904b3d  0f8405020000         je 0x904d48
// 00904b43  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00904b46  8bc3                 mov eax, ebx
// 00904b48  2bc2                 sub eax, edx
// 00904b4a  c1f804               sar eax, 4
// 00904b4d  baffffff0f           mov edx, 0xfffffff
// 00904b52  2bd0                 sub edx, eax
// 00904b54  3bd7                 cmp edx, edi
// 00904b56  7305                 jae 0x904b5d
// 00904b58  e893f2b1ff           call 0x423df0
// 00904b5d  8d1438               lea edx, [eax + edi]
// 00904b60  3bca                 cmp ecx, edx
// 00904b62  0f8303010000         jae 0x904c6b
// 00904b68  8bc1                 mov eax, ecx
// 00904b6a  d1e8                 shr eax, 1
// 00904b6c  bbffffff0f           mov ebx, 0xfffffff
// 00904b71  2bd8                 sub ebx, eax
// 00904b73  3bd9                 cmp ebx, ecx
// 00904b75  730c                 jae 0x904b83
// 00904b77  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00904b7e  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00904b81  eb05                 jmp 0x904b88
// 00904b83  03c8                 add ecx, eax
// 00904b85  894dec               mov dword ptr [ebp - 0x14], ecx
// 00904b88  3bca                 cmp ecx, edx
// 00904b8a  7305                 jae 0x904b91
// 00904b8c  8955ec               mov dword ptr [ebp - 0x14], edx
// 00904b8f  8bca                 mov ecx, edx
// 00904b91  6a00                 push 0
// 00904b93  51                   push ecx
// 00904b94  e837f3ffff           call 0x903ed0
// 00904b99  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00904b9c  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00904b9f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00904ba2  83c408               add esp, 8
// 00904ba5  c1fb04               sar ebx, 4
// 00904ba8  51                   push ecx
// 00904ba9  8bd3                 mov edx, ebx
// 00904bab  c1e204               shl edx, 4
// 00904bae  57                   push edi
// 00904baf  03d0                 add edx, eax
// 00904bb1  52                   push edx
// 00904bb2  8bce                 mov ecx, esi
// 00904bb4  894510               mov dword ptr [ebp + 0x10], eax
// 00904bb7  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00904bbe  e83dfbffff           call 0x904700
// 00904bc3  8b460c               mov eax, dword ptr [esi + 0xc]
// 00904bc6  c6451400             mov byte ptr [ebp + 0x14], 0
// 00904bca  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00904bcd  52                   push edx
// 00904bce  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00904bd1  52                   push edx
// 00904bd2  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00904bd5  8d4e08               lea ecx, [esi + 8]
// 00904bd8  51                   push ecx
// 00904bd9  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00904bdc  51                   push ecx
// 00904bdd  52                   push edx
// 00904bde  50                   push eax
// 00904bdf  e81cf9ffff           call 0x904500
// 00904be4  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00904be7  83c418               add esp, 0x18
// 00904bea  c6451400             mov byte ptr [ebp + 0x14], 0
// 00904bee  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00904bf1  52                   push edx
// 00904bf2  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00904bf5  52                   push edx
// 00904bf6  8d043b               lea eax, [ebx + edi]
// 00904bf9  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00904bfc  c1e004               shl eax, 4
// 00904bff  8d5608               lea edx, [esi + 8]
// 00904c02  52                   push edx
// 00904c03  03c3                 add eax, ebx
// 00904c05  50                   push eax
// 00904c06  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00904c09  51                   push ecx
// 00904c0a  50                   push eax
// 00904c0b  e8f0f8ffff           call 0x904500
// 00904c10  8b460c               mov eax, dword ptr [esi + 0xc]
// 00904c13  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00904c16  2bc8                 sub ecx, eax
// 00904c18  c1f904               sar ecx, 4
// 00904c1b  83c418               add esp, 0x18
// 00904c1e  03f9                 add edi, ecx
// 00904c20  85c0                 test eax, eax
// 00904c22  7409                 je 0x904c2d
// 00904c24  50                   push eax
// 00904c25  e8702deaff           call 0x7a799a
// 00904c2a  83c404               add esp, 4
// 00904c2d  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00904c30  c1e004               shl eax, 4
// 00904c33  03c3                 add eax, ebx
// 00904c35  c1e704               shl edi, 4
// 00904c38  03fb                 add edi, ebx
// 00904c3a  894614               mov dword ptr [esi + 0x14], eax
// 00904c3d  897e10               mov dword ptr [esi + 0x10], edi
// 00904c40  895e0c               mov dword ptr [esi + 0xc], ebx
// 00904c43  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00904c46  64890d00000000       mov dword ptr fs:[0], ecx
// 00904c4d  5f                   pop edi
// 00904c4e  5e                   pop esi
// 00904c4f  5b                   pop ebx
// 00904c50  8be5                 mov esp, ebp
// 00904c52  5d                   pop ebp
// 00904c53  c21000               ret 0x10
// standard library vector<pod16> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
