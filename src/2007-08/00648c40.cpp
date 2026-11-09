// from server: 100% by auto
// roc 2007-08 00648c40  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648c40
//
// 00648c40  56                   push esi
// 00648c41  8bf1                 mov esi, ecx
// 00648c43  837e2000             cmp dword ptr [esi + 0x20], 0
// 00648c47  7514                 jne 0x648c5d
// 00648c49  68986b7c00           push 0x7c6b98
// 00648c4e  e8bd60ddff           call 0x41ed10
// 00648c53  50                   push eax
// 00648c54  ff1588d27700         call dword ptr [0x77d288]
// 00648c5a  894620               mov dword ptr [esi + 0x20], eax
// 00648c5d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00648c60  8b442408             mov eax, dword ptr [esp + 8]
// 00648c64  8908                 mov dword ptr [eax], ecx
// 00648c66  5e                   pop esi
// 00648c67  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
