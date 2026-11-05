// from server: 100% by auto
// roc 2011-06 0081fdd0  unit: CXTPCommandBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081fdd0
//
// 0081fdd0  56                   push esi
// 0081fdd1  8bf1                 mov esi, ecx
// 0081fdd3  837e2c00             cmp dword ptr [esi + 0x2c], 0
// 0081fdd7  7514                 jne 0x81fded
// 0081fdd9  68d82fac00           push 0xac2fd8
// 0081fdde  e87d56bfff           call 0x415460
// 0081fde3  50                   push eax
// 0081fde4  ff156c03a400         call dword ptr [0xa4036c]
// 0081fdea  89462c               mov dword ptr [esi + 0x2c], eax
// 0081fded  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 0081fdf0  8b442408             mov eax, dword ptr [esp + 8]
// 0081fdf4  8908                 mov dword ptr [eax], ecx
// 0081fdf6  5e                   pop esi
// 0081fdf7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxeditbrowsectrl.cpp (function ?GetProcAddress_ImageList_ReplaceIcon@CComCtlWrapper@@QAE?AUImageList_ReplaceIcon_Type@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxeditbrowsectrl.cpp
