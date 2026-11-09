// from server: 100% by auto
// roc 2011-06 008604c0  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008604c0
//
// 008604c0  8b442408             mov eax, dword ptr [esp + 8]
// 008604c4  56                   push esi
// 008604c5  8b742408             mov esi, dword ptr [esp + 8]
// 008604c9  6a10                 push 0x10
// 008604cb  50                   push eax
// 008604cc  8bce                 mov ecx, esi
// 008604ce  e807a7faff           call 0x80abda
// 008604d3  83f810               cmp eax, 0x10
// 008604d6  7409                 je 0x8604e1
// 008604d8  6a00                 push 0
// 008604da  6a03                 push 3
// 008604dc  e8f3a6faff           call 0x80abd4
// 008604e1  8bc6                 mov eax, esi
// 008604e3  5e                   pop esi
// 008604e4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdockablepane.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdockablepane.cpp
