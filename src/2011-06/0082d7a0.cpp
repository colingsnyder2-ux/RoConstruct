// from server: 100% by auto
// roc 2011-06 0082d7a0  unit: CXTPCommandBarsOptions  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082d7a0
//
// 0082d7a0  56                   push esi
// 0082d7a1  8bf1                 mov esi, ecx
// 0082d7a3  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 0082d7a7  7514                 jne 0x82d7bd
// 0082d7a9  682840ac00           push 0xac4028
// 0082d7ae  e8ad7cbeff           call 0x415460
// 0082d7b3  50                   push eax
// 0082d7b4  ff156c03a400         call dword ptr [0xa4036c]
// 0082d7ba  89463c               mov dword ptr [esi + 0x3c], eax
// 0082d7bd  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0082d7c0  8b442408             mov eax, dword ptr [esp + 8]
// 0082d7c4  8908                 mov dword ptr [eax], ecx
// 0082d7c6  5e                   pop esi
// 0082d7c7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
