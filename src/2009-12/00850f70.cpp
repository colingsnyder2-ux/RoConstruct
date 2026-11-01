// from server: 100% by auto
// roc 2009-12 00850f70  unit: CXTPPropExchangeXMLNode  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850f70
//
// 00850f70  8b442408             mov eax, dword ptr [esp + 8]
// 00850f74  56                   push esi
// 00850f75  8b742408             mov esi, dword ptr [esp + 8]
// 00850f79  6a10                 push 0x10
// 00850f7b  50                   push eax
// 00850f7c  8bce                 mov ecx, esi
// 00850f7e  e85334faff           call 0x7f43d6
// 00850f83  83f810               cmp eax, 0x10
// 00850f86  7409                 je 0x850f91
// 00850f88  6a00                 push 0
// 00850f8a  6a03                 push 3
// 00850f8c  e83f34faff           call 0x7f43d0
// 00850f91  8bc6                 mov eax, esi
// 00850f93  5e                   pop esi
// 00850f94  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
