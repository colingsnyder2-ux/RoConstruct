// from server: 100% by auto
// roc 2010-06 0040cca0  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040cca0
//
// 0040cca0  8b442408             mov eax, dword ptr [esp + 8]
// 0040cca4  8b542404             mov edx, dword ptr [esp + 4]
// 0040cca8  50                   push eax
// 0040cca9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040ccac  52                   push edx
// 0040ccad  6881010000           push 0x181
// 0040ccb2  50                   push eax
// 0040ccb3  ff1554ba9e00         call dword ptr [0x9eba54]
// 0040ccb9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
