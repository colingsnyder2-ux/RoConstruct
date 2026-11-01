// from server: 100% by auto
// roc 2009-06 00486d80  unit: Ogre::RbxMeshPartAdapter  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486d80
//
// 00486d80  55                   push ebp
// 00486d81  8bec                 mov ebp, esp
// 00486d83  6aff                 push -1
// 00486d85  68c0548500           push 0x8554c0
// 00486d8a  64a100000000         mov eax, dword ptr fs:[0]
// 00486d90  50                   push eax
// 00486d91  64892500000000       mov dword ptr fs:[0], esp
// 00486d98  83ec18               sub esp, 0x18
// 00486d9b  53                   push ebx
// 00486d9c  56                   push esi
// 00486d9d  8bf1                 mov esi, ecx
// 00486d9f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00486da2  57                   push edi
// 00486da3  8965f0               mov dword ptr [ebp - 0x10], esp
// 00486da6  85d2                 test edx, edx
// 00486da8  7504                 jne 0x486dae
// 00486daa  33c9                 xor ecx, ecx
// 00486dac  eb0a                 jmp 0x486db8
// 00486dae  8b4614               mov eax, dword ptr [esi + 0x14]
// 00486db1  2bc2                 sub eax, edx
// 00486db3  c1f804               sar eax, 4
// 00486db6  8bc8                 mov ecx, eax
// 00486db8  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00486dbb  85ff                 test edi, edi
// 00486dbd  0f84ee010000         je 0x486fb1
// 00486dc3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00486dc6  8bc3                 mov eax, ebx
// 00486dc8  2bc2                 sub eax, edx
// 00486dca  c1f804               sar eax, 4
// 00486dcd  baffffff0f           mov edx, 0xfffffff
// 00486dd2  2bd0                 sub edx, eax
// 00486dd4  3bd7                 cmp edx, edi
// 00486dd6  7305                 jae 0x486ddd
// 00486dd8  e883950000           call 0x490360
// 00486ddd  8d1438               lea edx, [eax + edi]
// 00486de0  3bca                 cmp ecx, edx
// 00486de2  0f8303010000         jae 0x486eeb
// 00486de8  8bc1                 mov eax, ecx
// 00486dea  d1e8                 shr eax, 1
// 00486dec  bbffffff0f           mov ebx, 0xfffffff
// 00486df1  2bd8                 sub ebx, eax
// 00486df3  3bd9                 cmp ebx, ecx
// 00486df5  730c                 jae 0x486e03
// 00486df7  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00486dfe  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00486e01  eb05                 jmp 0x486e08
// 00486e03  03c8                 add ecx, eax
// 00486e05  894dec               mov dword ptr [ebp - 0x14], ecx
// 00486e08  3bca                 cmp ecx, edx
// 00486e0a  7305                 jae 0x486e11
// 00486e0c  8955ec               mov dword ptr [ebp - 0x14], edx
// 00486e0f  8bca                 mov ecx, edx
// 00486e11  6a00                 push 0
// 00486e13  51                   push ecx
// 00486e14  e837b7ffff           call 0x482550
// 00486e19  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00486e1c  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00486e1f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00486e22  83c408               add esp, 8
// 00486e25  c1fb04               sar ebx, 4
// 00486e28  51                   push ecx
// 00486e29  8bd3                 mov edx, ebx
// 00486e2b  c1e204               shl edx, 4
// 00486e2e  57                   push edi
// 00486e2f  03d0                 add edx, eax
// 00486e31  52                   push edx
// 00486e32  8bce                 mov ecx, esi
// 00486e34  894510               mov dword ptr [ebp + 0x10], eax
// 00486e37  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00486e3e  e86df9ffff           call 0x4867b0
// 00486e43  8b460c               mov eax, dword ptr [esi + 0xc]
// 00486e46  c6451400             mov byte ptr [ebp + 0x14], 0
// 00486e4a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486e4d  52                   push edx
// 00486e4e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486e51  52                   push edx
// 00486e52  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00486e55  8d4e08               lea ecx, [esi + 8]
// 00486e58  51                   push ecx
// 00486e59  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00486e5c  51                   push ecx
// 00486e5d  52                   push edx
// 00486e5e  50                   push eax
// 00486e5f  e86cf0ffff           call 0x485ed0
// 00486e64  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00486e67  83c418               add esp, 0x18
// 00486e6a  c6451400             mov byte ptr [ebp + 0x14], 0
// 00486e6e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486e71  52                   push edx
// 00486e72  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486e75  52                   push edx
// 00486e76  8d043b               lea eax, [ebx + edi]
// 00486e79  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00486e7c  c1e004               shl eax, 4
// 00486e7f  8d5608               lea edx, [esi + 8]
// 00486e82  52                   push edx
// 00486e83  03c3                 add eax, ebx
// 00486e85  50                   push eax
// 00486e86  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00486e89  51                   push ecx
// 00486e8a  50                   push eax
// 00486e8b  e840f0ffff           call 0x485ed0
// 00486e90  8b460c               mov eax, dword ptr [esi + 0xc]
// 00486e93  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00486e96  2bc8                 sub ecx, eax
// 00486e98  c1f904               sar ecx, 4
// 00486e9b  83c418               add esp, 0x18
// 00486e9e  03f9                 add edi, ecx
// 00486ea0  85c0                 test eax, eax
// 00486ea2  7409                 je 0x486ead
// 00486ea4  50                   push eax
// 00486ea5  e8881b2900           call 0x718a32
// 00486eaa  83c404               add esp, 4
// 00486ead  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00486eb0  c1e004               shl eax, 4
// 00486eb3  03c3                 add eax, ebx
// 00486eb5  c1e704               shl edi, 4
// 00486eb8  03fb                 add edi, ebx
// 00486eba  894614               mov dword ptr [esi + 0x14], eax
// 00486ebd  897e10               mov dword ptr [esi + 0x10], edi
// 00486ec0  895e0c               mov dword ptr [esi + 0xc], ebx
// 00486ec3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486ec6  64890d00000000       mov dword ptr fs:[0], ecx
// 00486ecd  5f                   pop edi
// 00486ece  5e                   pop esi
// 00486ecf  5b                   pop ebx
// 00486ed0  8be5                 mov esp, ebp
// 00486ed2  5d                   pop ebp
// 00486ed3  c21000               ret 0x10
// library ogre-1.6.4/OgreBillboardSet.cpp (function ?_Insert_n@?$vector@U?$TRect@M@Ogre@@V?$allocator@U?$TRect@M@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@U?$TRect@M@Ogre@@V?$allocator@U?$TRect@M@Ogre@@@std@@@2@IABU?$TRect@M@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardSet.cpp
