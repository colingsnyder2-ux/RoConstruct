// from server: 100% by auto
// roc 2011-06 00499560  unit: VerbBinderJob  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00499560
//
// 00499560  53                   push ebx
// 00499561  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00499565  8b4304               mov eax, dword ptr [ebx + 4]
// 00499568  56                   push esi
// 00499569  57                   push edi
// 0049956a  8bf1                 mov esi, ecx
// 0049956c  8b7e04               mov edi, dword ptr [esi + 4]
// 0049956f  83c004               add eax, 4
// 00499572  8b00                 mov eax, dword ptr [eax]
// 00499574  57                   push edi
// 00499575  50                   push eax
// 00499576  e835ffffff           call 0x4994b0
// 0049957b  894704               mov dword ptr [edi + 4], eax
// 0049957e  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00499581  8b5604               mov edx, dword ptr [esi + 4]
// 00499584  894e08               mov dword ptr [esi + 8], ecx
// 00499587  8b4204               mov eax, dword ptr [edx + 4]
// 0049958a  80781900             cmp byte ptr [eax + 0x19], 0
// 0049958e  7537                 jne 0x4995c7
// 00499590  8b08                 mov ecx, dword ptr [eax]
// 00499592  80791900             cmp byte ptr [ecx + 0x19], 0
// 00499596  750a                 jne 0x4995a2
// 00499598  8bc1                 mov eax, ecx
// 0049959a  8b08                 mov ecx, dword ptr [eax]
// 0049959c  80791900             cmp byte ptr [ecx + 0x19], 0
// 004995a0  74f6                 je 0x499598
// 004995a2  8902                 mov dword ptr [edx], eax
// 004995a4  8b7604               mov esi, dword ptr [esi + 4]
// 004995a7  8b4e04               mov ecx, dword ptr [esi + 4]
// 004995aa  8b4108               mov eax, dword ptr [ecx + 8]
// 004995ad  80781900             cmp byte ptr [eax + 0x19], 0
// 004995b1  750b                 jne 0x4995be
// 004995b3  8bc8                 mov ecx, eax
// 004995b5  8b4108               mov eax, dword ptr [ecx + 8]
// 004995b8  80781900             cmp byte ptr [eax + 0x19], 0
// 004995bc  74f5                 je 0x4995b3
// 004995be  5f                   pop edi
// 004995bf  894e08               mov dword ptr [esi + 8], ecx
// 004995c2  5e                   pop esi
// 004995c3  5b                   pop ebx
// 004995c4  c20400               ret 4
// 004995c7  8912                 mov dword ptr [edx], edx
// 004995c9  8b7604               mov esi, dword ptr [esi + 4]
// 004995cc  5f                   pop edi
// 004995cd  897608               mov dword ptr [esi + 8], esi
// 004995d0  5e                   pop esi
// 004995d1  5b                   pop ebx
// 004995d2  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
