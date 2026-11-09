// from server: 100% by auto
// roc 2009-06 0071b9f0  unit: CXTPControlComboBox  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071b9f0
//
// 0071b9f0  8b442408             mov eax, dword ptr [esp + 8]
// 0071b9f4  8b542404             mov edx, dword ptr [esp + 4]
// 0071b9f8  50                   push eax
// 0071b9f9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0071b9fc  52                   push edx
// 0071b9fd  68b0000000           push 0xb0
// 0071ba02  50                   push eax
// 0071ba03  ff1590ee8900         call dword ptr [0x89ee90]
// 0071ba09  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmaskededit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmaskededit.cpp
