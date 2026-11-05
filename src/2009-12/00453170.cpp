// from server: 100% by auto
// roc 2009-12 00453170  unit: CRobloxControlColorSelector  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00453170
//
// 00453170  56                   push esi
// 00453171  8bf1                 mov esi, ecx
// 00453173  837e2000             cmp dword ptr [esi + 0x20], 0
// 00453177  7514                 jne 0x45318d
// 00453179  6830bc9a00           push 0x9abc30
// 0045317e  e80dfefbff           call 0x412f90
// 00453183  50                   push eax
// 00453184  ff1520b29800         call dword ptr [0x98b220]
// 0045318a  894620               mov dword ptr [esi + 0x20], eax
// 0045318d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00453190  8b442408             mov eax, dword ptr [esp + 8]
// 00453194  8908                 mov dword ptr [eax], ecx
// 00453196  5e                   pop esi
// 00453197  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
