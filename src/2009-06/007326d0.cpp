// from server: 100% by auto
// roc 2009-06 007326d0  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007326d0
//
// 007326d0  56                   push esi
// 007326d1  8bf1                 mov esi, ecx
// 007326d3  837e2000             cmp dword ptr [esi + 0x20], 0
// 007326d7  7514                 jne 0x7326ed
// 007326d9  68a8308f00           push 0x8f30a8
// 007326de  e8fd0dceff           call 0x4134e0
// 007326e3  50                   push eax
// 007326e4  ff15e8e18900         call dword ptr [0x89e1e8]
// 007326ea  894620               mov dword ptr [esi + 0x20], eax
// 007326ed  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007326f0  8b442408             mov eax, dword ptr [esp + 8]
// 007326f4  8908                 mov dword ptr [eax], ecx
// 007326f6  5e                   pop esi
// 007326f7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
