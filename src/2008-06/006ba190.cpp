// from server: 100% by auto
// roc 2008-06 006ba190  unit: CXTPPropertyGridItemConstraint  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba190
//
// 006ba190  56                   push esi
// 006ba191  8bf1                 mov esi, ecx
// 006ba193  837e2000             cmp dword ptr [esi + 0x20], 0
// 006ba197  7514                 jne 0x6ba1ad
// 006ba199  6860208500           push 0x852060
// 006ba19e  e89d8dd5ff           call 0x412f40
// 006ba1a3  50                   push eax
// 006ba1a4  ff15c0218000         call dword ptr [0x8021c0]
// 006ba1aa  894620               mov dword ptr [esi + 0x20], eax
// 006ba1ad  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006ba1b0  8b442408             mov eax, dword ptr [esp + 8]
// 006ba1b4  8908                 mov dword ptr [eax], ecx
// 006ba1b6  5e                   pop esi
// 006ba1b7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
