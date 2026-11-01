// from server: 100% by auto
// roc 2010-06 00961580  unit: RBX::SceneUpdater  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961580
//
// 00961580  83ec08               sub esp, 8
// 00961583  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00961586  8b4204               mov eax, dword ptr [edx + 4]
// 00961589  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0096158d  55                   push ebp
// 0096158e  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00961592  56                   push esi
// 00961593  8bf2                 mov esi, edx
// 00961595  c644240801           mov byte ptr [esp + 8], 1
// 0096159a  7522                 jne 0x9615be
// 0096159c  57                   push edi
// 0096159d  8b7d00               mov edi, dword ptr [ebp]
// 009615a0  3b780c               cmp edi, dword ptr [eax + 0xc]
// 009615a3  8bf0                 mov esi, eax
// 009615a5  0f92c2               setb dl
// 009615a8  8854240c             mov byte ptr [esp + 0xc], dl
// 009615ac  84d2                 test dl, dl
// 009615ae  7404                 je 0x9615b4
// 009615b0  8b00                 mov eax, dword ptr [eax]
// 009615b2  eb03                 jmp 0x9615b7
// 009615b4  8b4008               mov eax, dword ptr [eax + 8]
// 009615b7  80782d00             cmp byte ptr [eax + 0x2d], 0
// 009615bb  74e3                 je 0x9615a0
// 009615bd  5f                   pop edi
// 009615be  8b442408             mov eax, dword ptr [esp + 8]
// 009615c2  55                   push ebp
// 009615c3  56                   push esi
// 009615c4  50                   push eax
// 009615c5  8d542414             lea edx, [esp + 0x14]
// 009615c9  52                   push edx
// 009615ca  e8419ecbff           call 0x61b410
// 009615cf  8bc8                 mov ecx, eax
// 009615d1  8b11                 mov edx, dword ptr [ecx]
// 009615d3  8b442414             mov eax, dword ptr [esp + 0x14]
// 009615d7  8b4904               mov ecx, dword ptr [ecx + 4]
// 009615da  5e                   pop esi
// 009615db  8910                 mov dword ptr [eax], edx
// 009615dd  894804               mov dword ptr [eax + 4], ecx
// 009615e0  c6400801             mov byte ptr [eax + 8], 1
// 009615e4  5d                   pop ebp
// 009615e5  83c408               add esp, 8
// 009615e8  c20800               ret 8
// library ogre-1.7.0/OgrePixelFormat.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@@std@@_N@2@ABU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgrePixelFormat.cpp
