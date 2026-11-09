// from server: 100% by auto
// roc 2011-06 00864830  unit: CXTPTabClientWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00864830
//
// 00864830  8b442404             mov eax, dword ptr [esp + 4]
// 00864834  50                   push eax
// 00864835  51                   push ecx
// 00864836  ff15001ca400         call dword ptr [0xa41c00]
// 0086483c  f7d8                 neg eax
// 0086483e  1bc0                 sbb eax, eax
// 00864840  40                   inc eax
// 00864841  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
