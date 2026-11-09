// from server: 100% by auto
// roc 2008-06 006c47e0  unit: CXTPToolBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c47e0
//
// 006c47e0  56                   push esi
// 006c47e1  8bf1                 mov esi, ecx
// 006c47e3  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 006c47e7  7514                 jne 0x6c47fd
// 006c47e9  68e02b8500           push 0x852be0
// 006c47ee  e84de7d4ff           call 0x412f40
// 006c47f3  50                   push eax
// 006c47f4  ff15c0218000         call dword ptr [0x8021c0]
// 006c47fa  89463c               mov dword ptr [esi + 0x3c], eax
// 006c47fd  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 006c4800  8b442408             mov eax, dword ptr [esp + 8]
// 006c4804  8908                 mov dword ptr [eax], ecx
// 006c4806  5e                   pop esi
// 006c4807  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
