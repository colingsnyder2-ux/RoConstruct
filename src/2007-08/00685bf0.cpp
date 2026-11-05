// from server: 100% by auto
// roc 2007-08 00685bf0  unit: CInstanceRecord::CNameItem  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00685bf0
//
// 00685bf0  8b442408             mov eax, dword ptr [esp + 8]
// 00685bf4  56                   push esi
// 00685bf5  8b742408             mov esi, dword ptr [esp + 8]
// 00685bf9  6a08                 push 8
// 00685bfb  50                   push eax
// 00685bfc  8bce                 mov ecx, esi
// 00685bfe  e88baafaff           call 0x63068e
// 00685c03  83f808               cmp eax, 8
// 00685c06  7409                 je 0x685c11
// 00685c08  6a00                 push 0
// 00685c0a  6a03                 push 3
// 00685c0c  e877aafaff           call 0x630688
// 00685c11  8bc6                 mov eax, esi
// 00685c13  5e                   pop esi
// 00685c14  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
