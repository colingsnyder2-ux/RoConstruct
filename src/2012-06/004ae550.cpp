// from server: 100% by auto
// roc 2012-06 004ae550  unit: VerbBinderJob  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ae550
//
// 004ae550  55                   push ebp
// 004ae551  8bec                 mov ebp, esp
// 004ae553  6aff                 push -1
// 004ae555  680047aa00           push 0xaa4700
// 004ae55a  64a100000000         mov eax, dword ptr fs:[0]
// 004ae560  50                   push eax
// 004ae561  64892500000000       mov dword ptr fs:[0], esp
// 004ae568  83ec0c               sub esp, 0xc
// 004ae56b  53                   push ebx
// 004ae56c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004ae56f  807b1900             cmp byte ptr [ebx + 0x19], 0
// 004ae573  56                   push esi
// 004ae574  8bf1                 mov esi, ecx
// 004ae576  8b4604               mov eax, dword ptr [esi + 4]
// 004ae579  57                   push edi
// 004ae57a  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ae57d  8975e8               mov dword ptr [ebp - 0x18], esi
// 004ae580  8945ec               mov dword ptr [ebp - 0x14], eax
// 004ae583  7547                 jne 0x4ae5cc
// 004ae585  0fb64b18             movzx ecx, byte ptr [ebx + 0x18]
// 004ae589  51                   push ecx
// 004ae58a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004ae58d  8d530c               lea edx, [ebx + 0xc]
// 004ae590  52                   push edx
// 004ae591  50                   push eax
// 004ae592  51                   push ecx
// 004ae593  50                   push eax
// 004ae594  8bce                 mov ecx, esi
// 004ae596  e8556a0c00           call 0x574ff0
// 004ae59b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ae59e  807a1900             cmp byte ptr [edx + 0x19], 0
// 004ae5a2  8bf8                 mov edi, eax
// 004ae5a4  7403                 je 0x4ae5a9
// 004ae5a6  897dec               mov dword ptr [ebp - 0x14], edi
// 004ae5a9  8b03                 mov eax, dword ptr [ebx]
// 004ae5ab  57                   push edi
// 004ae5ac  50                   push eax
// 004ae5ad  8bce                 mov ecx, esi
// 004ae5af  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004ae5b6  e895ffffff           call 0x4ae550
// 004ae5bb  8907                 mov dword ptr [edi], eax
// 004ae5bd  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004ae5c0  57                   push edi
// 004ae5c1  51                   push ecx
// 004ae5c2  8bce                 mov ecx, esi
// 004ae5c4  e887ffffff           call 0x4ae550
// 004ae5c9  894708               mov dword ptr [edi + 8], eax
// 004ae5cc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004ae5cf  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004ae5d2  5f                   pop edi
// 004ae5d3  5e                   pop esi
// 004ae5d4  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae5db  5b                   pop ebx
// 004ae5dc  8be5                 mov esp, ebp
// 004ae5de  5d                   pop ebp
// 004ae5df  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
