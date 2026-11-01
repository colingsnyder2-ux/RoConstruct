// from server: 100% by auto
// roc 2009-12 00683660  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00683660
//
// 00683660  55                   push ebp
// 00683661  8bec                 mov ebp, esp
// 00683663  6aff                 push -1
// 00683665  68305c9400           push 0x945c30
// 0068366a  64a100000000         mov eax, dword ptr fs:[0]
// 00683670  50                   push eax
// 00683671  64892500000000       mov dword ptr fs:[0], esp
// 00683678  83ec0c               sub esp, 0xc
// 0068367b  53                   push ebx
// 0068367c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0068367f  807b1900             cmp byte ptr [ebx + 0x19], 0
// 00683683  56                   push esi
// 00683684  8bf1                 mov esi, ecx
// 00683686  8b4618               mov eax, dword ptr [esi + 0x18]
// 00683689  57                   push edi
// 0068368a  8965f0               mov dword ptr [ebp - 0x10], esp
// 0068368d  8975e8               mov dword ptr [ebp - 0x18], esi
// 00683690  8945ec               mov dword ptr [ebp - 0x14], eax
// 00683693  7547                 jne 0x6836dc
// 00683695  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 00683699  51                   push ecx
// 0068369a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0068369d  8d530c               lea edx, [ebx + 0xc]
// 006836a0  52                   push edx
// 006836a1  50                   push eax
// 006836a2  51                   push ecx
// 006836a3  50                   push eax
// 006836a4  8bce                 mov ecx, esi
// 006836a6  e8c5f4ffff           call 0x682b70
// 006836ab  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006836ae  807a1900             cmp byte ptr [edx + 0x19], 0
// 006836b2  8bf8                 mov edi, eax
// 006836b4  7403                 je 0x6836b9
// 006836b6  897dec               mov dword ptr [ebp - 0x14], edi
// 006836b9  8b03                 mov eax, dword ptr [ebx]
// 006836bb  57                   push edi
// 006836bc  50                   push eax
// 006836bd  8bce                 mov ecx, esi
// 006836bf  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006836c6  e895ffffff           call 0x683660
// 006836cb  8907                 mov dword ptr [edi], eax
// 006836cd  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006836d0  57                   push edi
// 006836d1  51                   push ecx
// 006836d2  8bce                 mov ecx, esi
// 006836d4  e887ffffff           call 0x683660
// 006836d9  894708               mov dword ptr [edi + 8], eax
// 006836dc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006836df  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 006836e2  5f                   pop edi
// 006836e3  5e                   pop esi
// 006836e4  64890d00000000       mov dword ptr fs:[0], ecx
// 006836eb  5b                   pop ebx
// 006836ec  8be5                 mov esp, ebp
// 006836ee  5d                   pop ebp
// 006836ef  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
