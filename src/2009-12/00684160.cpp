// from server: 100% by auto
// roc 2009-12 00684160  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00684160
//
// 00684160  53                   push ebx
// 00684161  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00684165  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00684168  56                   push esi
// 00684169  57                   push edi
// 0068416a  8bf1                 mov esi, ecx
// 0068416c  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0068416f  83c004               add eax, 4
// 00684172  8b00                 mov eax, dword ptr [eax]
// 00684174  57                   push edi
// 00684175  50                   push eax
// 00684176  e8e5f4ffff           call 0x683660
// 0068417b  894704               mov dword ptr [edi + 4], eax
// 0068417e  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 00684181  8b5618               mov edx, dword ptr [esi + 0x18]
// 00684184  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00684187  8b4204               mov eax, dword ptr [edx + 4]
// 0068418a  80781900             cmp byte ptr [eax + 0x19], 0
// 0068418e  7537                 jne 0x6841c7
// 00684190  8b08                 mov ecx, dword ptr [eax]
// 00684192  80791900             cmp byte ptr [ecx + 0x19], 0
// 00684196  750a                 jne 0x6841a2
// 00684198  8bc1                 mov eax, ecx
// 0068419a  8b08                 mov ecx, dword ptr [eax]
// 0068419c  80791900             cmp byte ptr [ecx + 0x19], 0
// 006841a0  74f6                 je 0x684198
// 006841a2  8902                 mov dword ptr [edx], eax
// 006841a4  8b7618               mov esi, dword ptr [esi + 0x18]
// 006841a7  8b4e04               mov ecx, dword ptr [esi + 4]
// 006841aa  8b4108               mov eax, dword ptr [ecx + 8]
// 006841ad  80781900             cmp byte ptr [eax + 0x19], 0
// 006841b1  750b                 jne 0x6841be
// 006841b3  8bc8                 mov ecx, eax
// 006841b5  8b4108               mov eax, dword ptr [ecx + 8]
// 006841b8  80781900             cmp byte ptr [eax + 0x19], 0
// 006841bc  74f5                 je 0x6841b3
// 006841be  5f                   pop edi
// 006841bf  894e08               mov dword ptr [esi + 8], ecx
// 006841c2  5e                   pop esi
// 006841c3  5b                   pop ebx
// 006841c4  c20400               ret 4
// 006841c7  8912                 mov dword ptr [edx], edx
// 006841c9  8b7618               mov esi, dword ptr [esi + 0x18]
// 006841cc  5f                   pop edi
// 006841cd  897608               mov dword ptr [esi + 8], esi
// 006841d0  5e                   pop esi
// 006841d1  5b                   pop ebx
// 006841d2  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
