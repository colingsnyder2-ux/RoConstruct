// from server: 100% by auto
// roc 2009-06 00619e60  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00619e60
//
// 00619e60  53                   push ebx
// 00619e61  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00619e65  8b4318               mov eax, dword ptr [ebx + 0x18]
// 00619e68  56                   push esi
// 00619e69  57                   push edi
// 00619e6a  8bf1                 mov esi, ecx
// 00619e6c  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00619e6f  83c004               add eax, 4
// 00619e72  8b00                 mov eax, dword ptr [eax]
// 00619e74  57                   push edi
// 00619e75  50                   push eax
// 00619e76  e8c5f3ffff           call 0x619240
// 00619e7b  894704               mov dword ptr [edi + 4], eax
// 00619e7e  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 00619e81  8b5618               mov edx, dword ptr [esi + 0x18]
// 00619e84  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00619e87  8b4204               mov eax, dword ptr [edx + 4]
// 00619e8a  80781900             cmp byte ptr [eax + 0x19], 0
// 00619e8e  7537                 jne 0x619ec7
// 00619e90  8b08                 mov ecx, dword ptr [eax]
// 00619e92  80791900             cmp byte ptr [ecx + 0x19], 0
// 00619e96  750a                 jne 0x619ea2
// 00619e98  8bc1                 mov eax, ecx
// 00619e9a  8b08                 mov ecx, dword ptr [eax]
// 00619e9c  80791900             cmp byte ptr [ecx + 0x19], 0
// 00619ea0  74f6                 je 0x619e98
// 00619ea2  8902                 mov dword ptr [edx], eax
// 00619ea4  8b7618               mov esi, dword ptr [esi + 0x18]
// 00619ea7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00619eaa  8b4108               mov eax, dword ptr [ecx + 8]
// 00619ead  80781900             cmp byte ptr [eax + 0x19], 0
// 00619eb1  750b                 jne 0x619ebe
// 00619eb3  8bc8                 mov ecx, eax
// 00619eb5  8b4108               mov eax, dword ptr [ecx + 8]
// 00619eb8  80781900             cmp byte ptr [eax + 0x19], 0
// 00619ebc  74f5                 je 0x619eb3
// 00619ebe  5f                   pop edi
// 00619ebf  894e08               mov dword ptr [esi + 8], ecx
// 00619ec2  5e                   pop esi
// 00619ec3  5b                   pop ebx
// 00619ec4  c20400               ret 4
// 00619ec7  8912                 mov dword ptr [edx], edx
// 00619ec9  8b7618               mov esi, dword ptr [esi + 0x18]
// 00619ecc  5f                   pop edi
// 00619ecd  897608               mov dword ptr [esi + 8], esi
// 00619ed0  5e                   pop esi
// 00619ed1  5b                   pop ebx
// 00619ed2  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
