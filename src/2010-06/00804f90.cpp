// from server: 100% by auto
// roc 2010-06 00804f90  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804f90
//
// 00804f90  8b442408             mov eax, dword ptr [esp + 8]
// 00804f94  56                   push esi
// 00804f95  8b742408             mov esi, dword ptr [esp + 8]
// 00804f99  6a10                 push 0x10
// 00804f9b  50                   push eax
// 00804f9c  8bce                 mov ecx, esi
// 00804f9e  e87935faff           call 0x7a851c
// 00804fa3  8bc6                 mov eax, esi
// 00804fa5  5e                   pop esi
// 00804fa6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
