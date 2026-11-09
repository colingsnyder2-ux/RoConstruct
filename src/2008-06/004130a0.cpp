// from server: 100% by auto
// roc 2008-06 004130a0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004130a0
//
// 004130a0  56                   push esi
// 004130a1  8bf1                 mov esi, ecx
// 004130a3  837e4400             cmp dword ptr [esi + 0x44], 0
// 004130a7  7514                 jne 0x4130bd
// 004130a9  6888e88000           push 0x80e888
// 004130ae  e88dfeffff           call 0x412f40
// 004130b3  50                   push eax
// 004130b4  ff15c0218000         call dword ptr [0x8021c0]
// 004130ba  894644               mov dword ptr [esi + 0x44], eax
// 004130bd  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 004130c0  8b442408             mov eax, dword ptr [esp + 8]
// 004130c4  8908                 mov dword ptr [eax], ecx
// 004130c6  5e                   pop esi
// 004130c7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
