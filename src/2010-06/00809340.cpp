// from server: 100% by auto
// roc 2010-06 00809340  unit: CXTPTabClientWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809340
//
// 00809340  8b442404             mov eax, dword ptr [esp + 4]
// 00809344  50                   push eax
// 00809345  51                   push ecx
// 00809346  ff1518ba9e00         call dword ptr [0x9eba18]
// 0080934c  f7d8                 neg eax
// 0080934e  1bc0                 sbb eax, eax
// 00809350  40                   inc eax
// 00809351  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
