// from server: 100% by auto
// roc 2010-06 00804f70  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804f70
//
// 00804f70  56                   push esi
// 00804f71  8b742408             mov esi, dword ptr [esp + 8]
// 00804f75  6a08                 push 8
// 00804f77  8d442410             lea eax, [esp + 0x10]
// 00804f7b  50                   push eax
// 00804f7c  8bce                 mov ecx, esi
// 00804f7e  e89935faff           call 0x7a851c
// 00804f83  8bc6                 mov eax, esi
// 00804f85  5e                   pop esi
// 00804f86  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??6@YGAAVCArchive@@AAV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
