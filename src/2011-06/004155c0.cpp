// from server: 100% by auto
// roc 2011-06 004155c0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004155c0
//
// 004155c0  56                   push esi
// 004155c1  8bf1                 mov esi, ecx
// 004155c3  837e4400             cmp dword ptr [esi + 0x44], 0
// 004155c7  7514                 jne 0x4155dd
// 004155c9  6878e7a500           push 0xa5e778
// 004155ce  e88dfeffff           call 0x415460
// 004155d3  50                   push eax
// 004155d4  ff156c03a400         call dword ptr [0xa4036c]
// 004155da  894644               mov dword ptr [esi + 0x44], eax
// 004155dd  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004155e0  8b442408             mov eax, dword ptr [esp + 8]
// 004155e4  8908                 mov dword ptr [eax], ecx
// 004155e6  5e                   pop esi
// 004155e7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
