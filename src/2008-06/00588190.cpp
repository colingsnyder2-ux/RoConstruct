// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00588190  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588190
//
// 00588190  55                   push ebp
// 00588191  8bec                 mov ebp, esp
// 00588193  6aff                 push -1
// 00588195  6830147d00           push 0x7d1430
// 0058819a  64a100000000         mov eax, dword ptr fs:[0]
// 005881a0  50                   push eax
// 005881a1  64892500000000       mov dword ptr fs:[0], esp
// 005881a8  83ec0c               sub esp, 0xc
// 005881ab  53                   push ebx
// 005881ac  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005881af  807b1900             cmp byte ptr [ebx + 0x19], 0
// 005881b3  56                   push esi
// 005881b4  8bf1                 mov esi, ecx
// 005881b6  8b4618               mov eax, dword ptr [esi + 0x18]
// 005881b9  57                   push edi
// 005881ba  8965f0               mov dword ptr [ebp - 0x10], esp
// 005881bd  8975e8               mov dword ptr [ebp - 0x18], esi
// 005881c0  8945ec               mov dword ptr [ebp - 0x14], eax
// 005881c3  7547                 jne 0x58820c
// 005881c5  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 005881c9  51                   push ecx
// 005881ca  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005881cd  8d530c               lea edx, [ebx + 0xc]
// 005881d0  52                   push edx
// 005881d1  50                   push eax
// 005881d2  51                   push ecx
// 005881d3  50                   push eax
// 005881d4  8bce                 mov ecx, esi
// 005881d6  e865f4ffff           call 0x587640
// 005881db  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005881de  807a1900             cmp byte ptr [edx + 0x19], 0
// 005881e2  8bf8                 mov edi, eax
// 005881e4  7403                 je 0x5881e9
// 005881e6  897dec               mov dword ptr [ebp - 0x14], edi
// 005881e9  8b03                 mov eax, dword ptr [ebx]
// 005881eb  57                   push edi
// 005881ec  50                   push eax
// 005881ed  8bce                 mov ecx, esi
// 005881ef  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005881f6  e895ffffff           call 0x588190
// 005881fb  8907                 mov dword ptr [edi], eax
// 005881fd  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00588200  57                   push edi
// 00588201  51                   push ecx
// 00588202  8bce                 mov ecx, esi
// 00588204  e887ffffff           call 0x588190
// 00588209  894708               mov dword ptr [edi + 8], eax
// 0058820c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058820f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00588212  5f                   pop edi
// 00588213  5e                   pop esi
// 00588214  64890d00000000       mov dword ptr fs:[0], ecx
// 0058821b  5b                   pop ebx
// 0058821c  8be5                 mov esp, ebp
// 0058821e  5d                   pop ebp
// 0058821f  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
