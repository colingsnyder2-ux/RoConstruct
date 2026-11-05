// from server: 100% by auto
// roc 2008-06 0040e1f0  unit: CBrowserView  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e1f0
//
// 0040e1f0  8b442404             mov eax, dword ptr [esp + 4]
// 0040e1f4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040e1f7  6a00                 push 0
// 0040e1f9  50                   push eax
// 0040e1fa  6882010000           push 0x182
// 0040e1ff  51                   push ecx
// 0040e200  ff15142e8000         call dword ptr [0x802e14]
// 0040e206  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
