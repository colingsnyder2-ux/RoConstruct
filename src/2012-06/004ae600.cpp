// from server: 100% by auto
// roc 2012-06 004ae600  unit: VerbBinderJob  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ae600
//
// 004ae600  53                   push ebx
// 004ae601  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004ae605  8b4304               mov eax, dword ptr [ebx + 4]
// 004ae608  56                   push esi
// 004ae609  57                   push edi
// 004ae60a  8bf1                 mov esi, ecx
// 004ae60c  8b7e04               mov edi, dword ptr [esi + 4]
// 004ae60f  83c004               add eax, 4
// 004ae612  8b00                 mov eax, dword ptr [eax]
// 004ae614  57                   push edi
// 004ae615  50                   push eax
// 004ae616  e835ffffff           call 0x4ae550
// 004ae61b  894704               mov dword ptr [edi + 4], eax
// 004ae61e  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004ae621  8b5604               mov edx, dword ptr [esi + 4]
// 004ae624  894e08               mov dword ptr [esi + 8], ecx
// 004ae627  8b4204               mov eax, dword ptr [edx + 4]
// 004ae62a  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae62e  7537                 jne 0x4ae667
// 004ae630  8b08                 mov ecx, dword ptr [eax]
// 004ae632  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ae636  750a                 jne 0x4ae642
// 004ae638  8bc1                 mov eax, ecx
// 004ae63a  8b08                 mov ecx, dword ptr [eax]
// 004ae63c  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ae640  74f6                 je 0x4ae638
// 004ae642  8902                 mov dword ptr [edx], eax
// 004ae644  8b7604               mov esi, dword ptr [esi + 4]
// 004ae647  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae64a  8b4108               mov eax, dword ptr [ecx + 8]
// 004ae64d  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae651  750b                 jne 0x4ae65e
// 004ae653  8bc8                 mov ecx, eax
// 004ae655  8b4108               mov eax, dword ptr [ecx + 8]
// 004ae658  80781900             cmp byte ptr [eax + 0x19], 0
// 004ae65c  74f5                 je 0x4ae653
// 004ae65e  5f                   pop edi
// 004ae65f  894e08               mov dword ptr [esi + 8], ecx
// 004ae662  5e                   pop esi
// 004ae663  5b                   pop ebx
// 004ae664  c20400               ret 4
// 004ae667  8912                 mov dword ptr [edx], edx
// 004ae669  8b7604               mov esi, dword ptr [esi + 4]
// 004ae66c  5f                   pop edi
// 004ae66d  897608               mov dword ptr [esi + 8], esi
// 004ae670  5e                   pop esi
// 004ae671  5b                   pop ebx
// 004ae672  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
