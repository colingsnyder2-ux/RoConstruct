// from server: 100% by auto
// roc 2007-03 00667210  unit: seg_00660000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00667210
//
// 00667210  8b442408             mov eax, dword ptr [esp + 8]
// 00667214  56                   push esi
// 00667215  8b742408             mov esi, dword ptr [esp + 8]
// 00667219  6a10                 push 0x10
// 0066721b  50                   push eax
// 0066721c  8bce                 mov ecx, esi
// 0066721e  e8a57bfbff           call 0x61edc8
// 00667223  83f810               cmp eax, 0x10
// 00667226  7409                 je 0x667231
// 00667228  6a00                 push 0
// 0066722a  6a03                 push 3
// 0066722c  e8917bfbff           call 0x61edc2
// 00667231  8bc6                 mov eax, esi
// 00667233  5e                   pop esi
// 00667234  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
