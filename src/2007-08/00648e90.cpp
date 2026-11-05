// from server: 100% by auto
// roc 2007-08 00648e90  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648e90
//
// 00648e90  56                   push esi
// 00648e91  8bf1                 mov esi, ecx
// 00648e93  837e5400             cmp dword ptr [esi + 0x54], 0
// 00648e97  7514                 jne 0x648ead
// 00648e99  68c86b7c00           push 0x7c6bc8
// 00648e9e  e86d5eddff           call 0x41ed10
// 00648ea3  50                   push eax
// 00648ea4  ff1588d27700         call dword ptr [0x77d288]
// 00648eaa  894654               mov dword ptr [esi + 0x54], eax
// 00648ead  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00648eb0  8b442408             mov eax, dword ptr [esp + 8]
// 00648eb4  8908                 mov dword ptr [eax], ecx
// 00648eb6  5e                   pop esi
// 00648eb7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetIcon@CComCtlWrapper@@QAE?AUImageList_GetIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
