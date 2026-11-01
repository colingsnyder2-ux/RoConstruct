// from server: 100% by auto
// roc 2009-12 008552c0  unit: CXTPTabClientWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008552c0
//
// 008552c0  8b442404             mov eax, dword ptr [esp + 4]
// 008552c4  50                   push eax
// 008552c5  51                   push ecx
// 008552c6  ff15bcca9800         call dword ptr [0x98cabc]
// 008552cc  f7d8                 neg eax
// 008552ce  1bc0                 sbb eax, eax
// 008552d0  40                   inc eax
// 008552d1  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
