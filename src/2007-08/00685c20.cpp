// from server: 100% by auto
// roc 2007-08 00685c20  unit: CInstanceRecord::CNameItem  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00685c20
//
// 00685c20  8b442408             mov eax, dword ptr [esp + 8]
// 00685c24  56                   push esi
// 00685c25  8b742408             mov esi, dword ptr [esp + 8]
// 00685c29  6a10                 push 0x10
// 00685c2b  50                   push eax
// 00685c2c  8bce                 mov ecx, esi
// 00685c2e  e85baafaff           call 0x63068e
// 00685c33  83f810               cmp eax, 0x10
// 00685c36  7409                 je 0x685c41
// 00685c38  6a00                 push 0
// 00685c3a  6a03                 push 3
// 00685c3c  e847aafaff           call 0x630688
// 00685c41  8bc6                 mov eax, esi
// 00685c43  5e                   pop esi
// 00685c44  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
