// from server: 100% by auto
// roc 2011-06 0060e7e0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060e7e0
//
// 0060e7e0  55                   push ebp
// 0060e7e1  8bec                 mov ebp, esp
// 0060e7e3  6aff                 push -1
// 0060e7e5  68a0839e00           push 0x9e83a0
// 0060e7ea  64a100000000         mov eax, dword ptr fs:[0]
// 0060e7f0  50                   push eax
// 0060e7f1  64892500000000       mov dword ptr fs:[0], esp
// 0060e7f8  83ec0c               sub esp, 0xc
// 0060e7fb  53                   push ebx
// 0060e7fc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0060e7ff  807b1900             cmp byte ptr [ebx + 0x19], 0
// 0060e803  56                   push esi
// 0060e804  8bf1                 mov esi, ecx
// 0060e806  8b4604               mov eax, dword ptr [esi + 4]
// 0060e809  57                   push edi
// 0060e80a  8965f0               mov dword ptr [ebp - 0x10], esp
// 0060e80d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0060e810  8945ec               mov dword ptr [ebp - 0x14], eax
// 0060e813  7547                 jne 0x60e85c
// 0060e815  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 0060e819  51                   push ecx
// 0060e81a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0060e81d  8d530c               lea edx, [ebx + 0xc]
// 0060e820  52                   push edx
// 0060e821  50                   push eax
// 0060e822  51                   push ecx
// 0060e823  50                   push eax
// 0060e824  8bce                 mov ecx, esi
// 0060e826  e8c5f4ffff           call 0x60dcf0
// 0060e82b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0060e82e  807a1900             cmp byte ptr [edx + 0x19], 0
// 0060e832  8bf8                 mov edi, eax
// 0060e834  7403                 je 0x60e839
// 0060e836  897dec               mov dword ptr [ebp - 0x14], edi
// 0060e839  8b03                 mov eax, dword ptr [ebx]
// 0060e83b  57                   push edi
// 0060e83c  50                   push eax
// 0060e83d  8bce                 mov ecx, esi
// 0060e83f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0060e846  e895ffffff           call 0x60e7e0
// 0060e84b  8907                 mov dword ptr [edi], eax
// 0060e84d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0060e850  57                   push edi
// 0060e851  51                   push ecx
// 0060e852  8bce                 mov ecx, esi
// 0060e854  e887ffffff           call 0x60e7e0
// 0060e859  894708               mov dword ptr [edi + 8], eax
// 0060e85c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0060e85f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0060e862  5f                   pop edi
// 0060e863  5e                   pop esi
// 0060e864  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e86b  5b                   pop ebx
// 0060e86c  8be5                 mov esp, ebp
// 0060e86e  5d                   pop ebp
// 0060e86f  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
