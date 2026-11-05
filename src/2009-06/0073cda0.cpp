// from server: 100% by auto
// roc 2009-06 0073cda0  unit: CXTPToolBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073cda0
//
// 0073cda0  56                   push esi
// 0073cda1  8bf1                 mov esi, ecx
// 0073cda3  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 0073cda7  7514                 jne 0x73cdbd
// 0073cda9  68303c8f00           push 0x8f3c30
// 0073cdae  e82d67cdff           call 0x4134e0
// 0073cdb3  50                   push eax
// 0073cdb4  ff15e8e18900         call dword ptr [0x89e1e8]
// 0073cdba  89463c               mov dword ptr [esi + 0x3c], eax
// 0073cdbd  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0073cdc0  8b442408             mov eax, dword ptr [esp + 8]
// 0073cdc4  8908                 mov dword ptr [eax], ecx
// 0073cdc6  5e                   pop esi
// 0073cdc7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
