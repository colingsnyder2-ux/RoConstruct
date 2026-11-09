// from server: 100% by auto
// roc 2010-06 007cbd70  unit: CXTPCommandBarsOptions  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cbd70
//
// 007cbd70  56                   push esi
// 007cbd71  8bf1                 mov esi, ecx
// 007cbd73  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 007cbd77  7514                 jne 0x7cbd8d
// 007cbd79  68e483a500           push 0xa583e4
// 007cbd7e  e8bd74c4ff           call 0x413240
// 007cbd83  50                   push eax
// 007cbd84  ff1590a39e00         call dword ptr [0x9ea390]
// 007cbd8a  89463c               mov dword ptr [esi + 0x3c], eax
// 007cbd8d  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 007cbd90  8b442408             mov eax, dword ptr [esp + 8]
// 007cbd94  8908                 mov dword ptr [eax], ecx
// 007cbd96  5e                   pop esi
// 007cbd97  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_Draw@CComCtlWrapper@@QAE?AUImageList_Draw_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
