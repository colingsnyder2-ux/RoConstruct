// from server: 100% by auto
// roc 2010-06 007bda10  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bda10
//
// 007bda10  56                   push esi
// 007bda11  8bf1                 mov esi, ecx
// 007bda13  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 007bda17  7514                 jne 0x7bda2d
// 007bda19  687873a500           push 0xa57378
// 007bda1e  e81d58c5ff           call 0x413240
// 007bda23  50                   push eax
// 007bda24  ff1590a39e00         call dword ptr [0x9ea390]
// 007bda2a  89462c               mov dword ptr [esi + 0x2c], eax
// 007bda2d  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 007bda30  8b442408             mov eax, dword ptr [esp + 8]
// 007bda34  8908                 mov dword ptr [eax], ecx
// 007bda36  5e                   pop esi
// 007bda37  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
