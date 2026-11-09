// from server: 100% by auto
// roc 2008-06 0040e210  unit: CBrowserView  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e210
//
// 0040e210  8b442408             mov eax, dword ptr [esp + 8]
// 0040e214  8b542404             mov edx, dword ptr [esp + 4]
// 0040e218  50                   push eax
// 0040e219  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040e21c  52                   push edx
// 0040e21d  6881010000           push 0x181
// 0040e222  50                   push eax
// 0040e223  ff15142e8000         call dword ptr [0x802e14]
// 0040e229  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
