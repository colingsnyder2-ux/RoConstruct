// from server: 100% by auto
// roc 2010-06 007bdb30  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdb30
//
// 007bdb30  56                   push esi
// 007bdb31  8bf1                 mov esi, ecx
// 007bdb33  837e5400             cmp dword ptr [esi + 0x54], 0
// 007bdb37  7514                 jne 0x7bdb4d
// 007bdb39  689073a500           push 0xa57390
// 007bdb3e  e8fd56c5ff           call 0x413240
// 007bdb43  50                   push eax
// 007bdb44  ff1590a39e00         call dword ptr [0x9ea390]
// 007bdb4a  894654               mov dword ptr [esi + 0x54], eax
// 007bdb4d  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 007bdb50  8b442408             mov eax, dword ptr [esp + 8]
// 007bdb54  8908                 mov dword ptr [eax], ecx
// 007bdb56  5e                   pop esi
// 007bdb57  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
