// from server: 100% by auto
// roc 2009-12 00850f20  unit: CXTPPropExchangeXMLNode  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850f20
//
// 00850f20  8b442408             mov eax, dword ptr [esp + 8]
// 00850f24  56                   push esi
// 00850f25  8b742408             mov esi, dword ptr [esp + 8]
// 00850f29  6a10                 push 0x10
// 00850f2b  50                   push eax
// 00850f2c  8bce                 mov ecx, esi
// 00850f2e  e8a934faff           call 0x7f43dc
// 00850f33  8bc6                 mov eax, esi
// 00850f35  5e                   pop esi
// 00850f36  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
