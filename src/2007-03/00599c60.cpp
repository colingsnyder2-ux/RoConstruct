// from server: 100% by auto
// roc 2007-03 00599c60  unit: seg_00590000  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00599c60
//
// 00599c60  53                   push ebx
// 00599c61  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00599c65  8b4304               mov eax, dword ptr [ebx + 4]
// 00599c68  56                   push esi
// 00599c69  57                   push edi
// 00599c6a  8bf1                 mov esi, ecx
// 00599c6c  8b7e04               mov edi, dword ptr [esi + 4]
// 00599c6f  83c004               add eax, 4
// 00599c72  8b00                 mov eax, dword ptr [eax]
// 00599c74  57                   push edi
// 00599c75  50                   push eax
// 00599c76  e8e5f3ffff           call 0x599060
// 00599c7b  894704               mov dword ptr [edi + 4], eax
// 00599c7e  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00599c81  8b5604               mov edx, dword ptr [esi + 4]
// 00599c84  894e08               mov dword ptr [esi + 8], ecx
// 00599c87  8b4204               mov eax, dword ptr [edx + 4]
// 00599c8a  80782100             cmp byte ptr [eax + 0x21], 0
// 00599c8e  7537                 jne 0x599cc7
// 00599c90  8b08                 mov ecx, dword ptr [eax]
// 00599c92  80792100             cmp byte ptr [ecx + 0x21], 0
// 00599c96  750a                 jne 0x599ca2
// 00599c98  8bc1                 mov eax, ecx
// 00599c9a  8b08                 mov ecx, dword ptr [eax]
// 00599c9c  80792100             cmp byte ptr [ecx + 0x21], 0
// 00599ca0  74f6                 je 0x599c98
// 00599ca2  8902                 mov dword ptr [edx], eax
// 00599ca4  8b7604               mov esi, dword ptr [esi + 4]
// 00599ca7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00599caa  8b4108               mov eax, dword ptr [ecx + 8]
// 00599cad  80782100             cmp byte ptr [eax + 0x21], 0
// 00599cb1  750b                 jne 0x599cbe
// 00599cb3  8bc8                 mov ecx, eax
// 00599cb5  8b4108               mov eax, dword ptr [ecx + 8]
// 00599cb8  80782100             cmp byte ptr [eax + 0x21], 0
// 00599cbc  74f5                 je 0x599cb3
// 00599cbe  5f                   pop edi
// 00599cbf  894e08               mov dword ptr [esi + 8], ecx
// 00599cc2  5e                   pop esi
// 00599cc3  5b                   pop ebx
// 00599cc4  c20400               ret 4
// 00599cc7  8912                 mov dword ptr [edx], edx
// 00599cc9  8b7604               mov esi, dword ptr [esi + 4]
// 00599ccc  5f                   pop edi
// 00599ccd  897608               mov dword ptr [esi + 8], esi
// 00599cd0  5e                   pop esi
// 00599cd1  5b                   pop ebx
// 00599cd2  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@IVVector4@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVVector4@Ogre@@@std@@@4@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
