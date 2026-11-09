// from server: 100% by auto
// roc 2009-12 008098b0  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008098b0
//
// 008098b0  56                   push esi
// 008098b1  8bf1                 mov esi, ecx
// 008098b3  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 008098b7  7514                 jne 0x8098cd
// 008098b9  6890309f00           push 0x9f3090
// 008098be  e8cd96c0ff           call 0x412f90
// 008098c3  50                   push eax
// 008098c4  ff1520b29800         call dword ptr [0x98b220]
// 008098ca  89462c               mov dword ptr [esi + 0x2c], eax
// 008098cd  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 008098d0  8b442408             mov eax, dword ptr [esp + 8]
// 008098d4  8908                 mov dword ptr [eax], ecx
// 008098d6  5e                   pop esi
// 008098d7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
