// from server: 100% by auto
// roc 2009-06 00413640  unit: CRbxChildFrame  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413640
//
// 00413640  56                   push esi
// 00413641  8bf1                 mov esi, ecx
// 00413643  837e4400             cmp dword ptr [esi + 0x44], 0
// 00413647  7514                 jne 0x41365d
// 00413649  684cf68a00           push 0x8af64c
// 0041364e  e88dfeffff           call 0x4134e0
// 00413653  50                   push eax
// 00413654  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041365a  894644               mov dword ptr [esi + 0x44], eax
// 0041365d  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00413660  8b442408             mov eax, dword ptr [esp + 8]
// 00413664  8908                 mov dword ptr [eax], ecx
// 00413666  5e                   pop esi
// 00413667  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetProcAddress_ImageList_AddMasked@CComCtlWrapper@@QAE?AUImageList_AddMasked_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
