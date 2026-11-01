// from server: 100% by auto
// roc 2009-12 008099d0  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008099d0
//
// 008099d0  56                   push esi
// 008099d1  8bf1                 mov esi, ecx
// 008099d3  837e5400             cmp dword ptr [esi + 0x54], 0
// 008099d7  7514                 jne 0x8099ed
// 008099d9  68a8309f00           push 0x9f30a8
// 008099de  e8ad95c0ff           call 0x412f90
// 008099e3  50                   push eax
// 008099e4  ff1520b29800         call dword ptr [0x98b220]
// 008099ea  894654               mov dword ptr [esi + 0x54], eax
// 008099ed  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 008099f0  8b442408             mov eax, dword ptr [esp + 8]
// 008099f4  8908                 mov dword ptr [eax], ecx
// 008099f6  5e                   pop esi
// 008099f7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
