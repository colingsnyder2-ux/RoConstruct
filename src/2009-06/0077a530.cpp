// from server: 100% by auto
// roc 2009-06 0077a530  unit: CXTPTabClientWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a530
//
// 0077a530  8b442404             mov eax, dword ptr [esp + 4]
// 0077a534  50                   push eax
// 0077a535  51                   push ecx
// 0077a536  ff15acee8900         call dword ptr [0x89eeac]
// 0077a53c  f7d8                 neg eax
// 0077a53e  1bc0                 sbb eax, eax
// 0077a540  40                   inc eax
// 0077a541  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
