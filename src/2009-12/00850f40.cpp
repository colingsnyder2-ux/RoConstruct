// from server: 100% by auto
// roc 2009-12 00850f40  unit: CXTPPropExchangeXMLNode  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850f40
//
// 00850f40  8b442408             mov eax, dword ptr [esp + 8]
// 00850f44  56                   push esi
// 00850f45  8b742408             mov esi, dword ptr [esp + 8]
// 00850f49  6a08                 push 8
// 00850f4b  50                   push eax
// 00850f4c  8bce                 mov ecx, esi
// 00850f4e  e88334faff           call 0x7f43d6
// 00850f53  83f808               cmp eax, 8
// 00850f56  7409                 je 0x850f61
// 00850f58  6a00                 push 0
// 00850f5a  6a03                 push 3
// 00850f5c  e86f34faff           call 0x7f43d0
// 00850f61  8bc6                 mov eax, esi
// 00850f63  5e                   pop esi
// 00850f64  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
