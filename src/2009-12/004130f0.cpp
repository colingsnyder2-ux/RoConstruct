// from server: 100% by auto
// roc 2009-12 004130f0  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004130f0
//
// 004130f0  56                   push esi
// 004130f1  8bf1                 mov esi, ecx
// 004130f3  837e4400             cmp dword ptr [esi + 0x44], 0
// 004130f7  7514                 jne 0x41310d
// 004130f9  6800229a00           push 0x9a2200
// 004130fe  e88dfeffff           call 0x412f90
// 00413103  50                   push eax
// 00413104  ff1520b29800         call dword ptr [0x98b220]
// 0041310a  894644               mov dword ptr [esi + 0x44], eax
// 0041310d  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00413110  8b442408             mov eax, dword ptr [esp + 8]
// 00413114  8908                 mov dword ptr [eax], ecx
// 00413116  5e                   pop esi
// 00413117  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
