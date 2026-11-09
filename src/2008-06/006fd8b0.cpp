// from server: 100% by auto
// roc 2008-06 006fd8b0  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fd8b0
//
// 006fd8b0  8b442408             mov eax, dword ptr [esp + 8]
// 006fd8b4  56                   push esi
// 006fd8b5  8b742408             mov esi, dword ptr [esp + 8]
// 006fd8b9  6a10                 push 0x10
// 006fd8bb  50                   push eax
// 006fd8bc  8bce                 mov ecx, esi
// 006fd8be  e86738faff           call 0x6a112a
// 006fd8c3  83f810               cmp eax, 0x10
// 006fd8c6  7409                 je 0x6fd8d1
// 006fd8c8  6a00                 push 0
// 006fd8ca  6a03                 push 3
// 006fd8cc  e85338faff           call 0x6a1124
// 006fd8d1  8bc6                 mov eax, esi
// 006fd8d3  5e                   pop esi
// 006fd8d4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
