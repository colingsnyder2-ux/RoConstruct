// from server: 100% by auto
// roc 2009-06 0040caf0  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040caf0
//
// 0040caf0  8b442404             mov eax, dword ptr [esp + 4]
// 0040caf4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040caf7  6a00                 push 0
// 0040caf9  50                   push eax
// 0040cafa  6882010000           push 0x182
// 0040caff  51                   push ecx
// 0040cb00  ff1590ee8900         call dword ptr [0x89ee90]
// 0040cb06  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
