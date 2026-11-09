// from server: 100% by auto
// roc 2011-06 00860490  unit: CXTCaptionButtonTheme  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860490
//
// 00860490  8b442408             mov eax, dword ptr [esp + 8]
// 00860494  56                   push esi
// 00860495  8b742408             mov esi, dword ptr [esp + 8]
// 00860499  6a08                 push 8
// 0086049b  50                   push eax
// 0086049c  8bce                 mov ecx, esi
// 0086049e  e837a7faff           call 0x80abda
// 008604a3  83f808               cmp eax, 8
// 008604a6  7409                 je 0x8604b1
// 008604a8  6a00                 push 0
// 008604aa  6a03                 push 3
// 008604ac  e823a7faff           call 0x80abd4
// 008604b1  8bc6                 mov eax, esi
// 008604b3  5e                   pop esi
// 008604b4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmdiclientareawnd.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmdiclientareawnd.cpp
