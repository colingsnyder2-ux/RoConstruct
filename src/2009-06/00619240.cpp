// from server: 100% by auto
// roc 2009-06 00619240  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619240
//
// 00619240  55                   push ebp
// 00619241  8bec                 mov ebp, esp
// 00619243  6aff                 push -1
// 00619245  6830828600           push 0x868230
// 0061924a  64a100000000         mov eax, dword ptr fs:[0]
// 00619250  50                   push eax
// 00619251  64892500000000       mov dword ptr fs:[0], esp
// 00619258  83ec0c               sub esp, 0xc
// 0061925b  53                   push ebx
// 0061925c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0061925f  807b1900             cmp byte ptr [ebx + 0x19], 0
// 00619263  56                   push esi
// 00619264  8bf1                 mov esi, ecx
// 00619266  8b4618               mov eax, dword ptr [esi + 0x18]
// 00619269  57                   push edi
// 0061926a  8965f0               mov dword ptr [ebp - 0x10], esp
// 0061926d  8975e8               mov dword ptr [ebp - 0x18], esi
// 00619270  8945ec               mov dword ptr [ebp - 0x14], eax
// 00619273  7547                 jne 0x6192bc
// 00619275  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 00619279  51                   push ecx
// 0061927a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0061927d  8d530c               lea edx, [ebx + 0xc]
// 00619280  52                   push edx
// 00619281  50                   push eax
// 00619282  51                   push ecx
// 00619283  50                   push eax
// 00619284  8bce                 mov ecx, esi
// 00619286  e8c5f4ffff           call 0x618750
// 0061928b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0061928e  807a1900             cmp byte ptr [edx + 0x19], 0
// 00619292  8bf8                 mov edi, eax
// 00619294  7403                 je 0x619299
// 00619296  897dec               mov dword ptr [ebp - 0x14], edi
// 00619299  8b03                 mov eax, dword ptr [ebx]
// 0061929b  57                   push edi
// 0061929c  50                   push eax
// 0061929d  8bce                 mov ecx, esi
// 0061929f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006192a6  e895ffffff           call 0x619240
// 006192ab  8907                 mov dword ptr [edi], eax
// 006192ad  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006192b0  57                   push edi
// 006192b1  51                   push ecx
// 006192b2  8bce                 mov ecx, esi
// 006192b4  e887ffffff           call 0x619240
// 006192b9  894708               mov dword ptr [edi + 8], eax
// 006192bc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006192bf  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006192c2  5f                   pop edi
// 006192c3  5e                   pop esi
// 006192c4  64890d00000000       mov dword ptr fs:[0], ecx
// 006192cb  5b                   pop ebx
// 006192cc  8be5                 mov esp, ebp
// 006192ce  5d                   pop ebp
// 006192cf  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
