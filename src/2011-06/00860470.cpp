// from server: 100% by auto
// roc 2011-06 00860470  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860470
//
// 00860470  8b442408             mov eax, dword ptr [esp + 8]
// 00860474  56                   push esi
// 00860475  8b742408             mov esi, dword ptr [esp + 8]
// 00860479  6a10                 push 0x10
// 0086047b  50                   push eax
// 0086047c  8bce                 mov ecx, esi
// 0086047e  e85da7faff           call 0x80abe0
// 00860483  8bc6                 mov eax, esi
// 00860485  5e                   pop esi
// 00860486  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
