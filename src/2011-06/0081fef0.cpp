// from server: 100% by auto
// roc 2011-06 0081fef0  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081fef0
//
// 0081fef0  56                   push esi
// 0081fef1  8bf1                 mov esi, ecx
// 0081fef3  837e5400             cmp dword ptr [esi + 0x54], 0
// 0081fef7  7514                 jne 0x81ff0d
// 0081fef9  68f02fac00           push 0xac2ff0
// 0081fefe  e85d55bfff           call 0x415460
// 0081ff03  50                   push eax
// 0081ff04  ff156c03a400         call dword ptr [0xa4036c]
// 0081ff0a  894654               mov dword ptr [esi + 0x54], eax
// 0081ff0d  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0081ff10  8b442408             mov eax, dword ptr [esp + 8]
// 0081ff14  8908                 mov dword ptr [eax], ecx
// 0081ff16  5e                   pop esi
// 0081ff17  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
