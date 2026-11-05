// from server: 100% by auto
// roc 2009-12 00850f00  unit: CXTPPropExchangeXMLNode  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850f00
//
// 00850f00  56                   push esi
// 00850f01  8b742408             mov esi, dword ptr [esp + 8]
// 00850f05  6a08                 push 8
// 00850f07  8d442410             lea eax, [esp + 0x10]
// 00850f0b  50                   push eax
// 00850f0c  8bce                 mov ecx, esi
// 00850f0e  e8c934faff           call 0x7f43dc
// 00850f13  8bc6                 mov eax, esi
// 00850f15  5e                   pop esi
// 00850f16  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
