// from server: 100% by auto
// roc 2009-12 007f9b80  unit: CXTPControlComboBoxPopupBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9b80
//
// 007f9b80  8b442408             mov eax, dword ptr [esp + 8]
// 007f9b84  8b542404             mov edx, dword ptr [esp + 4]
// 007f9b88  50                   push eax
// 007f9b89  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007f9b8c  52                   push edx
// 007f9b8d  68b0000000           push 0xb0
// 007f9b92  50                   push eax
// 007f9b93  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9b99  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
