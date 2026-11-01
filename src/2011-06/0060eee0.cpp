// from server: 100% by auto
// roc 2011-06 0060eee0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060eee0
//
// 0060eee0  53                   push ebx
// 0060eee1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0060eee5  8b4304               mov eax, dword ptr [ebx + 4]
// 0060eee8  56                   push esi
// 0060eee9  57                   push edi
// 0060eeea  8bf1                 mov esi, ecx
// 0060eeec  8b7e04               mov edi, dword ptr [esi + 4]
// 0060eeef  83c004               add eax, 4
// 0060eef2  8b00                 mov eax, dword ptr [eax]
// 0060eef4  57                   push edi
// 0060eef5  50                   push eax
// 0060eef6  e8e5f8ffff           call 0x60e7e0
// 0060eefb  894704               mov dword ptr [edi + 4], eax
// 0060eefe  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0060ef01  8b5604               mov edx, dword ptr [esi + 4]
// 0060ef04  894e08               mov dword ptr [esi + 8], ecx
// 0060ef07  8b4204               mov eax, dword ptr [edx + 4]
// 0060ef0a  80781900             cmp byte ptr [eax + 0x19], 0
// 0060ef0e  7537                 jne 0x60ef47
// 0060ef10  8b08                 mov ecx, dword ptr [eax]
// 0060ef12  80791900             cmp byte ptr [ecx + 0x19], 0
// 0060ef16  750a                 jne 0x60ef22
// 0060ef18  8bc1                 mov eax, ecx
// 0060ef1a  8b08                 mov ecx, dword ptr [eax]
// 0060ef1c  80791900             cmp byte ptr [ecx + 0x19], 0
// 0060ef20  74f6                 je 0x60ef18
// 0060ef22  8902                 mov dword ptr [edx], eax
// 0060ef24  8b7604               mov esi, dword ptr [esi + 4]
// 0060ef27  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060ef2a  8b4108               mov eax, dword ptr [ecx + 8]
// 0060ef2d  80781900             cmp byte ptr [eax + 0x19], 0
// 0060ef31  750b                 jne 0x60ef3e
// 0060ef33  8bc8                 mov ecx, eax
// 0060ef35  8b4108               mov eax, dword ptr [ecx + 8]
// 0060ef38  80781900             cmp byte ptr [eax + 0x19], 0
// 0060ef3c  74f5                 je 0x60ef33
// 0060ef3e  5f                   pop edi
// 0060ef3f  894e08               mov dword ptr [esi + 8], ecx
// 0060ef42  5e                   pop esi
// 0060ef43  5b                   pop ebx
// 0060ef44  c20400               ret 4
// 0060ef47  8912                 mov dword ptr [edx], edx
// 0060ef49  8b7604               mov esi, dword ptr [esi + 4]
// 0060ef4c  5f                   pop edi
// 0060ef4d  897608               mov dword ptr [esi + 8], esi
// 0060ef50  5e                   pop esi
// 0060ef51  5b                   pop ebx
// 0060ef52  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
