// from server: 100% by auto
// roc 2009-12 00817cc0  unit: CXTPCommandBarsOptions  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00817cc0
//
// 00817cc0  56                   push esi
// 00817cc1  8bf1                 mov esi, ecx
// 00817cc3  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 00817cc7  7514                 jne 0x817cdd
// 00817cc9  68f4409f00           push 0x9f40f4
// 00817cce  e8bdb2bfff           call 0x412f90
// 00817cd3  50                   push eax
// 00817cd4  ff1520b29800         call dword ptr [0x98b220]
// 00817cda  89463c               mov dword ptr [esi + 0x3c], eax
// 00817cdd  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00817ce0  8b442408             mov eax, dword ptr [esp + 8]
// 00817ce4  8908                 mov dword ptr [eax], ecx
// 00817ce6  5e                   pop esi
// 00817ce7  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
