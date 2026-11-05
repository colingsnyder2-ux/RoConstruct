// from server: 100% by auto
// roc 2011-06 00816cf0  unit: CXTPControlComboBox  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00816cf0
//
// 00816cf0  8b442408             mov eax, dword ptr [esp + 8]
// 00816cf4  8b542404             mov edx, dword ptr [esp + 4]
// 00816cf8  50                   push eax
// 00816cf9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00816cfc  52                   push edx
// 00816cfd  68b0000000           push 0xb0
// 00816d02  50                   push eax
// 00816d03  ff15c019a400         call dword ptr [0xa419c0]
// 00816d09  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmaskededit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmaskededit.cpp
