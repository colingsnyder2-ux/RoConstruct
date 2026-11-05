// from server: 100% by auto
// roc 2010-06 00454670  unit: CRobloxControlColorSelector  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00454670
//
// 00454670  56                   push esi
// 00454671  8bf1                 mov esi, ecx
// 00454673  837e2000             cmp dword ptr [esi + 0x20], 0
// 00454677  7514                 jne 0x45468d
// 00454679  6828caa000           push 0xa0ca28
// 0045467e  e8bdebfbff           call 0x413240
// 00454683  50                   push eax
// 00454684  ff1590a39e00         call dword ptr [0x9ea390]
// 0045468a  894620               mov dword ptr [esi + 0x20], eax
// 0045468d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00454690  8b442408             mov eax, dword ptr [esp + 8]
// 00454694  8908                 mov dword ptr [eax], ecx
// 00454696  5e                   pop esi
// 00454697  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
