// from server: 100% by auto
// roc 2010-06 005ea840  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ea840
//
// 005ea840  55                   push ebp
// 005ea841  8bec                 mov ebp, esp
// 005ea843  6aff                 push -1
// 005ea845  6850809900           push 0x998050
// 005ea84a  64a100000000         mov eax, dword ptr fs:[0]
// 005ea850  50                   push eax
// 005ea851  64892500000000       mov dword ptr fs:[0], esp
// 005ea858  83ec0c               sub esp, 0xc
// 005ea85b  53                   push ebx
// 005ea85c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ea85f  807b1900             cmp byte ptr [ebx + 0x19], 0
// 005ea863  56                   push esi
// 005ea864  8bf1                 mov esi, ecx
// 005ea866  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ea869  57                   push edi
// 005ea86a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005ea86d  8975e8               mov dword ptr [ebp - 0x18], esi
// 005ea870  8945ec               mov dword ptr [ebp - 0x14], eax
// 005ea873  7547                 jne 0x5ea8bc
// 005ea875  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 005ea879  51                   push ecx
// 005ea87a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005ea87d  8d530c               lea edx, [ebx + 0xc]
// 005ea880  52                   push edx
// 005ea881  50                   push eax
// 005ea882  51                   push ecx
// 005ea883  50                   push eax
// 005ea884  8bce                 mov ecx, esi
// 005ea886  e825f4ffff           call 0x5e9cb0
// 005ea88b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005ea88e  807a1900             cmp byte ptr [edx + 0x19], 0
// 005ea892  8bf8                 mov edi, eax
// 005ea894  7403                 je 0x5ea899
// 005ea896  897dec               mov dword ptr [ebp - 0x14], edi
// 005ea899  8b03                 mov eax, dword ptr [ebx]
// 005ea89b  57                   push edi
// 005ea89c  50                   push eax
// 005ea89d  8bce                 mov ecx, esi
// 005ea89f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005ea8a6  e895ffffff           call 0x5ea840
// 005ea8ab  8907                 mov dword ptr [edi], eax
// 005ea8ad  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005ea8b0  57                   push edi
// 005ea8b1  51                   push ecx
// 005ea8b2  8bce                 mov ecx, esi
// 005ea8b4  e887ffffff           call 0x5ea840
// 005ea8b9  894708               mov dword ptr [edi + 8], eax
// 005ea8bc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005ea8bf  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005ea8c2  5f                   pop edi
// 005ea8c3  5e                   pop esi
// 005ea8c4  64890d00000000       mov dword ptr fs:[0], ecx
// 005ea8cb  5b                   pop ebx
// 005ea8cc  8be5                 mov esp, ebp
// 005ea8ce  5d                   pop ebp
// 005ea8cf  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
