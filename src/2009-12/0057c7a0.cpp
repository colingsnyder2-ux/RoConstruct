// from server: 100% by auto
// roc 2009-12 0057c7a0  unit: RBX::SceneUpdater  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c7a0
//
// 0057c7a0  83ec08               sub esp, 8
// 0057c7a3  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0057c7a6  8b4204               mov eax, dword ptr [edx + 4]
// 0057c7a9  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0057c7ad  55                   push ebp
// 0057c7ae  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0057c7b2  56                   push esi
// 0057c7b3  8bf2                 mov esi, edx
// 0057c7b5  c644240801           mov byte ptr [esp + 8], 1
// 0057c7ba  7522                 jne 0x57c7de
// 0057c7bc  57                   push edi
// 0057c7bd  8b7d00               mov edi, dword ptr [ebp]
// 0057c7c0  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0057c7c3  8bf0                 mov esi, eax
// 0057c7c5  0f92c2               setb dl
// 0057c7c8  8854240c             mov byte ptr [esp + 0xc], dl
// 0057c7cc  84d2                 test dl, dl
// 0057c7ce  7404                 je 0x57c7d4
// 0057c7d0  8b00                 mov eax, dword ptr [eax]
// 0057c7d2  eb03                 jmp 0x57c7d7
// 0057c7d4  8b4008               mov eax, dword ptr [eax + 8]
// 0057c7d7  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0057c7db  74e3                 je 0x57c7c0
// 0057c7dd  5f                   pop edi
// 0057c7de  8b442408             mov eax, dword ptr [esp + 8]
// 0057c7e2  55                   push ebp
// 0057c7e3  56                   push esi
// 0057c7e4  50                   push eax
// 0057c7e5  8d542414             lea edx, [esp + 0x14]
// 0057c7e9  52                   push edx
// 0057c7ea  e841faffff           call 0x57c230
// 0057c7ef  8bc8                 mov ecx, eax
// 0057c7f1  8b11                 mov edx, dword ptr [ecx]
// 0057c7f3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057c7f7  8b4904               mov ecx, dword ptr [ecx + 4]
// 0057c7fa  5e                   pop esi
// 0057c7fb  8910                 mov dword ptr [eax], edx
// 0057c7fd  894804               mov dword ptr [eax + 4], ecx
// 0057c800  c6400801             mov byte ptr [eax + 8], 1
// 0057c804  5d                   pop ebp
// 0057c805  83c408               add esp, 8
// 0057c808  c20800               ret 8
// library ogre-1.7.0/OgrePixelFormat.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@@std@@_N@2@ABU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgrePixelFormat.cpp
