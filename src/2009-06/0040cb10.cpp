// from server: 100% by auto
// roc 2009-06 0040cb10  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cb10
//
// 0040cb10  8b442408             mov eax, dword ptr [esp + 8]
// 0040cb14  8b542404             mov edx, dword ptr [esp + 4]
// 0040cb18  50                   push eax
// 0040cb19  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040cb1c  52                   push edx
// 0040cb1d  6881010000           push 0x181
// 0040cb22  50                   push eax
// 0040cb23  ff1590ee8900         call dword ptr [0x89ee90]
// 0040cb29  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
