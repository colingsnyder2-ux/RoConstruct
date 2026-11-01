// from server: 100% by auto
// roc 2007-03 00565d80  unit: seg_00560000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00565d80
//
// 00565d80  8b5104               mov edx, dword ptr [ecx + 4]
// 00565d83  8b4204               mov eax, dword ptr [edx + 4]
// 00565d86  80781500             cmp byte ptr [eax + 0x15], 0
// 00565d8a  56                   push esi
// 00565d8b  57                   push edi
// 00565d8c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00565d90  7516                 jne 0x565da8
// 00565d92  8b37                 mov esi, dword ptr [edi]
// 00565d94  3b700c               cmp esi, dword ptr [eax + 0xc]
// 00565d97  7306                 jae 0x565d9f
// 00565d99  8bd0                 mov edx, eax
// 00565d9b  8b00                 mov eax, dword ptr [eax]
// 00565d9d  eb03                 jmp 0x565da2
// 00565d9f  8b4008               mov eax, dword ptr [eax + 8]
// 00565da2  80781500             cmp byte ptr [eax + 0x15], 0
// 00565da6  74ec                 je 0x565d94
// 00565da8  8b7104               mov esi, dword ptr [ecx + 4]
// 00565dab  8b4604               mov eax, dword ptr [esi + 4]
// 00565dae  80781500             cmp byte ptr [eax + 0x15], 0
// 00565db2  7516                 jne 0x565dca
// 00565db4  8b3f                 mov edi, dword ptr [edi]
// 00565db6  39780c               cmp dword ptr [eax + 0xc], edi
// 00565db9  7305                 jae 0x565dc0
// 00565dbb  8b4008               mov eax, dword ptr [eax + 8]
// 00565dbe  eb04                 jmp 0x565dc4
// 00565dc0  8bf0                 mov esi, eax
// 00565dc2  8b00                 mov eax, dword ptr [eax]
// 00565dc4  80781500             cmp byte ptr [eax + 0x15], 0
// 00565dc8  74ec                 je 0x565db6
// 00565dca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00565dce  5f                   pop edi
// 00565dcf  897004               mov dword ptr [eax + 4], esi
// 00565dd2  8908                 mov dword ptr [eax], ecx
// 00565dd4  894808               mov dword ptr [eax + 8], ecx
// 00565dd7  89500c               mov dword ptr [eax + 0xc], edx
// 00565dda  5e                   pop esi
// 00565ddb  c20800               ret 8
// library ogre-1.6.4/OgreResourceBackgroundQueue.cpp (function ?equal_range@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@V123@@2@ABK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceBackgroundQueue.cpp
