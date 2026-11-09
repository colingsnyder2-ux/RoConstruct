// from server: 100% by auto
// roc 2007-08 00648d70  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648d70
//
// 00648d70  56                   push esi
// 00648d71  8bf1                 mov esi, ecx
// 00648d73  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 00648d77  7514                 jne 0x648d8d
// 00648d79  68b06b7c00           push 0x7c6bb0
// 00648d7e  e88d5fddff           call 0x41ed10
// 00648d83  50                   push eax
// 00648d84  ff1588d27700         call dword ptr [0x77d288]
// 00648d8a  89462c               mov dword ptr [esi + 0x2c], eax
// 00648d8d  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00648d90  8b442408             mov eax, dword ptr [esp + 8]
// 00648d94  8908                 mov dword ptr [eax], ecx
// 00648d96  5e                   pop esi
// 00648d97  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
