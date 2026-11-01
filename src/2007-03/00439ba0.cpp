// from server: 100% by auto
// roc 2007-03 00439ba0  unit: seg_00430000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00439ba0
//
// 00439ba0  8b5104               mov edx, dword ptr [ecx + 4]
// 00439ba3  8b4204               mov eax, dword ptr [edx + 4]
// 00439ba6  83ec10               sub esp, 0x10
// 00439ba9  80782100             cmp byte ptr [eax + 0x21], 0
// 00439bad  56                   push esi
// 00439bae  57                   push edi
// 00439baf  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00439bb3  7516                 jne 0x439bcb
// 00439bb5  8b37                 mov esi, dword ptr [edi]
// 00439bb7  39700c               cmp dword ptr [eax + 0xc], esi
// 00439bba  7305                 jae 0x439bc1
// 00439bbc  8b4008               mov eax, dword ptr [eax + 8]
// 00439bbf  eb04                 jmp 0x439bc5
// 00439bc1  8bd0                 mov edx, eax
// 00439bc3  8b00                 mov eax, dword ptr [eax]
// 00439bc5  80782100             cmp byte ptr [eax + 0x21], 0
// 00439bc9  74ec                 je 0x439bb7
// 00439bcb  8b4104               mov eax, dword ptr [ecx + 4]
// 00439bce  3bd0                 cmp edx, eax
// 00439bd0  8954240c             mov dword ptr [esp + 0xc], edx
// 00439bd4  894c2408             mov dword ptr [esp + 8], ecx
// 00439bd8  740d                 je 0x439be7
// 00439bda  8b37                 mov esi, dword ptr [edi]
// 00439bdc  3b720c               cmp esi, dword ptr [edx + 0xc]
// 00439bdf  7206                 jb 0x439be7
// 00439be1  8d4c2408             lea ecx, [esp + 8]
// 00439be5  eb0c                 jmp 0x439bf3
// 00439be7  894c2410             mov dword ptr [esp + 0x10], ecx
// 00439beb  89442414             mov dword ptr [esp + 0x14], eax
// 00439bef  8d4c2410             lea ecx, [esp + 0x10]
// 00439bf3  8b11                 mov edx, dword ptr [ecx]
// 00439bf5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00439bf9  8b4904               mov ecx, dword ptr [ecx + 4]
// 00439bfc  5f                   pop edi
// 00439bfd  8910                 mov dword ptr [eax], edx
// 00439bff  894804               mov dword ptr [eax + 4], ecx
// 00439c02  5e                   pop esi
// 00439c03  83c410               add esp, 0x10
// 00439c06  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?find@?$_Tree@V?$_Tmap_traits@IVVector4@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVVector4@Ogre@@@std@@@4@$0A@@std@@@std@@QBE?AVconst_iterator@12@ABI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
