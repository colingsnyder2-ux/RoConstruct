// from server: 100% by auto
// roc 2008-06 00701c20  unit: CXTPTabClientWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00701c20
//
// 00701c20  8b442404             mov eax, dword ptr [esp + 4]
// 00701c24  50                   push eax
// 00701c25  51                   push ecx
// 00701c26  ff15682c8000         call dword ptr [0x802c68]
// 00701c2c  f7d8                 neg eax
// 00701c2e  1bc0                 sbb eax, eax
// 00701c30  40                   inc eax
// 00701c31  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
