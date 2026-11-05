// from server: 100% by auto
// roc 2011-06 0046d8c0  unit: CRobloxControlColorSelector  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046d8c0
//
// 0046d8c0  56                   push esi
// 0046d8c1  8bf1                 mov esi, ecx
// 0046d8c3  837e2000             cmp dword ptr [esi + 0x20], 0
// 0046d8c7  7514                 jne 0x46d8dd
// 0046d8c9  68ecf8a600           push 0xa6f8ec
// 0046d8ce  e88d7bfaff           call 0x415460
// 0046d8d3  50                   push eax
// 0046d8d4  ff156c03a400         call dword ptr [0xa4036c]
// 0046d8da  894620               mov dword ptr [esi + 0x20], eax
// 0046d8dd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0046d8e0  8b442408             mov eax, dword ptr [esp + 8]
// 0046d8e4  8908                 mov dword ptr [eax], ecx
// 0046d8e6  5e                   pop esi
// 0046d8e7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?GetProcAddress_ImageList_GetImageCount@CComCtlWrapper@@QAE?AUImageList_GetImageCount_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
