// from server: 100% by auto
// roc 2008-06 006fd860  unit: CXTCaptionButtonTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fd860
//
// 006fd860  8b442408             mov eax, dword ptr [esp + 8]
// 006fd864  56                   push esi
// 006fd865  8b742408             mov esi, dword ptr [esp + 8]
// 006fd869  6a10                 push 0x10
// 006fd86b  50                   push eax
// 006fd86c  8bce                 mov ecx, esi
// 006fd86e  e8bd38faff           call 0x6a1130
// 006fd873  8bc6                 mov eax, esi
// 006fd875  5e                   pop esi
// 006fd876  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
