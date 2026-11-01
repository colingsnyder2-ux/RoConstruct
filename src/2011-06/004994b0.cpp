// from server: 100% by auto
// roc 2011-06 004994b0  unit: VerbBinderJob  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004994b0
//
// 004994b0  55                   push ebp
// 004994b1  8bec                 mov ebp, esp
// 004994b3  6aff                 push -1
// 004994b5  68c06a9d00           push 0x9d6ac0
// 004994ba  64a100000000         mov eax, dword ptr fs:[0]
// 004994c0  50                   push eax
// 004994c1  64892500000000       mov dword ptr fs:[0], esp
// 004994c8  83ec0c               sub esp, 0xc
// 004994cb  53                   push ebx
// 004994cc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004994cf  807b1900             cmp byte ptr [ebx + 0x19], 0
// 004994d3  56                   push esi
// 004994d4  8bf1                 mov esi, ecx
// 004994d6  8b4604               mov eax, dword ptr [esi + 4]
// 004994d9  57                   push edi
// 004994da  8965f0               mov dword ptr [ebp - 0x10], esp
// 004994dd  8975e8               mov dword ptr [ebp - 0x18], esi
// 004994e0  8945ec               mov dword ptr [ebp - 0x14], eax
// 004994e3  7547                 jne 0x49952c
// 004994e5  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 004994e9  51                   push ecx
// 004994ea  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004994ed  8d530c               lea edx, [ebx + 0xc]
// 004994f0  52                   push edx
// 004994f1  50                   push eax
// 004994f2  51                   push ecx
// 004994f3  50                   push eax
// 004994f4  8bce                 mov ecx, esi
// 004994f6  e8b55f2400           call 0x6df4b0
// 004994fb  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004994fe  807a1900             cmp byte ptr [edx + 0x19], 0
// 00499502  8bf8                 mov edi, eax
// 00499504  7403                 je 0x499509
// 00499506  897dec               mov dword ptr [ebp - 0x14], edi
// 00499509  8b03                 mov eax, dword ptr [ebx]
// 0049950b  57                   push edi
// 0049950c  50                   push eax
// 0049950d  8bce                 mov ecx, esi
// 0049950f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00499516  e895ffffff           call 0x4994b0
// 0049951b  8907                 mov dword ptr [edi], eax
// 0049951d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00499520  57                   push edi
// 00499521  51                   push ecx
// 00499522  8bce                 mov ecx, esi
// 00499524  e887ffffff           call 0x4994b0
// 00499529  894708               mov dword ptr [edi + 8], eax
// 0049952c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049952f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00499532  5f                   pop edi
// 00499533  5e                   pop esi
// 00499534  64890d00000000       mov dword ptr fs:[0], ecx
// 0049953b  5b                   pop ebx
// 0049953c  8be5                 mov esp, ebp
// 0049953e  5d                   pop ebp
// 0049953f  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
