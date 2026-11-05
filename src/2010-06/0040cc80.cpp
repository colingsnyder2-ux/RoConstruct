// from server: 100% by auto
// roc 2010-06 0040cc80  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040cc80
//
// 0040cc80  8b442404             mov eax, dword ptr [esp + 4]
// 0040cc84  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040cc87  6a00                 push 0
// 0040cc89  50                   push eax
// 0040cc8a  6882010000           push 0x182
// 0040cc8f  51                   push ecx
// 0040cc90  ff1554ba9e00         call dword ptr [0x9eba54]
// 0040cc96  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
