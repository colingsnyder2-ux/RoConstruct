// from server: 100% by auto
// roc 2010-06 005eb320  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb320
//
// 005eb320  53                   push ebx
// 005eb321  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005eb325  8b4318               mov eax, dword ptr [ebx + 0x18]
// 005eb328  56                   push esi
// 005eb329  57                   push edi
// 005eb32a  8bf1                 mov esi, ecx
// 005eb32c  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005eb32f  83c004               add eax, 4
// 005eb332  8b00                 mov eax, dword ptr [eax]
// 005eb334  57                   push edi
// 005eb335  50                   push eax
// 005eb336  e805f5ffff           call 0x5ea840
// 005eb33b  894704               mov dword ptr [edi + 4], eax
// 005eb33e  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb341  8b5618               mov edx, dword ptr [esi + 0x18]
// 005eb344  894e1c               mov dword ptr [esi + 0x1c], ecx
// 005eb347  8b4204               mov eax, dword ptr [edx + 4]
// 005eb34a  80781900             cmp byte ptr [eax + 0x19], 0
// 005eb34e  7537                 jne 0x5eb387
// 005eb350  8b08                 mov ecx, dword ptr [eax]
// 005eb352  80791900             cmp byte ptr [ecx + 0x19], 0
// 005eb356  750a                 jne 0x5eb362
// 005eb358  8bc1                 mov eax, ecx
// 005eb35a  8b08                 mov ecx, dword ptr [eax]
// 005eb35c  80791900             cmp byte ptr [ecx + 0x19], 0
// 005eb360  74f6                 je 0x5eb358
// 005eb362  8902                 mov dword ptr [edx], eax
// 005eb364  8b7618               mov esi, dword ptr [esi + 0x18]
// 005eb367  8b4e04               mov ecx, dword ptr [esi + 4]
// 005eb36a  8b4108               mov eax, dword ptr [ecx + 8]
// 005eb36d  80781900             cmp byte ptr [eax + 0x19], 0
// 005eb371  750b                 jne 0x5eb37e
// 005eb373  8bc8                 mov ecx, eax
// 005eb375  8b4108               mov eax, dword ptr [ecx + 8]
// 005eb378  80781900             cmp byte ptr [eax + 0x19], 0
// 005eb37c  74f5                 je 0x5eb373
// 005eb37e  5f                   pop edi
// 005eb37f  894e08               mov dword ptr [esi + 8], ecx
// 005eb382  5e                   pop esi
// 005eb383  5b                   pop ebx
// 005eb384  c20400               ret 4
// 005eb387  8912                 mov dword ptr [edx], edx
// 005eb389  8b7618               mov esi, dword ptr [esi + 0x18]
// 005eb38c  5f                   pop edi
// 005eb38d  897608               mov dword ptr [esi + 8], esi
// 005eb390  5e                   pop esi
// 005eb391  5b                   pop ebx
// 005eb392  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
