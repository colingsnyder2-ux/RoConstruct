// from server: 100% by auto
// roc 2010-06 004133a0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004133a0
//
// 004133a0  56                   push esi
// 004133a1  8bf1                 mov esi, ecx
// 004133a3  837e4400             cmp dword ptr [esi + 0x44], 0
// 004133a7  7514                 jne 0x4133bd
// 004133a9  68882ea000           push 0xa02e88
// 004133ae  e88dfeffff           call 0x413240
// 004133b3  50                   push eax
// 004133b4  ff1590a39e00         call dword ptr [0x9ea390]
// 004133ba  894644               mov dword ptr [esi + 0x44], eax
// 004133bd  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004133c0  8b442408             mov eax, dword ptr [esp + 8]
// 004133c4  8908                 mov dword ptr [eax], ecx
// 004133c6  5e                   pop esi
// 004133c7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
