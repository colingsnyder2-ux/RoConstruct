// from server: 100% by auto
// roc 2007-08 0040a790  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a790
//
// 0040a790  8b442408             mov eax, dword ptr [esp + 8]
// 0040a794  8b542404             mov edx, dword ptr [esp + 4]
// 0040a798  50                   push eax
// 0040a799  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040a79c  52                   push edx
// 0040a79d  6881010000           push 0x181
// 0040a7a2  50                   push eax
// 0040a7a3  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0040a7a9  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
