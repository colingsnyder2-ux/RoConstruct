// from server: 100% by auto
// roc 2007-08 00439d10  unit: RBX::VSoundId::?$XItem  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439d10
//
// 00439d10  8b5104               mov edx, dword ptr [ecx + 4]
// 00439d13  8b4204               mov eax, dword ptr [edx + 4]
// 00439d16  83ec10               sub esp, 0x10
// 00439d19  80782100             cmp byte ptr [eax + 0x21], 0
// 00439d1d  56                   push esi
// 00439d1e  57                   push edi
// 00439d1f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00439d23  7516                 jne 0x439d3b
// 00439d25  8b37                 mov esi, dword ptr [edi]
// 00439d27  39700c               cmp dword ptr [eax + 0xc], esi
// 00439d2a  7305                 jae 0x439d31
// 00439d2c  8b4008               mov eax, dword ptr [eax + 8]
// 00439d2f  eb04                 jmp 0x439d35
// 00439d31  8bd0                 mov edx, eax
// 00439d33  8b00                 mov eax, dword ptr [eax]
// 00439d35  80782100             cmp byte ptr [eax + 0x21], 0
// 00439d39  74ec                 je 0x439d27
// 00439d3b  8b4104               mov eax, dword ptr [ecx + 4]
// 00439d3e  3bd0                 cmp edx, eax
// 00439d40  8954240c             mov dword ptr [esp + 0xc], edx
// 00439d44  894c2408             mov dword ptr [esp + 8], ecx
// 00439d48  740d                 je 0x439d57
// 00439d4a  8b37                 mov esi, dword ptr [edi]
// 00439d4c  3b720c               cmp esi, dword ptr [edx + 0xc]
// 00439d4f  7206                 jb 0x439d57
// 00439d51  8d4c2408             lea ecx, [esp + 8]
// 00439d55  eb0c                 jmp 0x439d63
// 00439d57  894c2410             mov dword ptr [esp + 0x10], ecx
// 00439d5b  89442414             mov dword ptr [esp + 0x14], eax
// 00439d5f  8d4c2410             lea ecx, [esp + 0x10]
// 00439d63  8b11                 mov edx, dword ptr [ecx]
// 00439d65  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00439d69  8b4904               mov ecx, dword ptr [ecx + 4]
// 00439d6c  5f                   pop edi
// 00439d6d  8910                 mov dword ptr [eax], edx
// 00439d6f  894804               mov dword ptr [eax + 4], ecx
// 00439d72  5e                   pop esi
// 00439d73  83c410               add esp, 0x10
// 00439d76  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?find@?$_Tree@V?$_Tmap_traits@IVVector4@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVVector4@Ogre@@@std@@@4@$0A@@std@@@std@@QBE?AVconst_iterator@12@ABI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
