// from server: 100% by auto
// roc 2007-03 006671e0  unit: seg_00660000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006671e0
//
// 006671e0  8b442408             mov eax, dword ptr [esp + 8]
// 006671e4  56                   push esi
// 006671e5  8b742408             mov esi, dword ptr [esp + 8]
// 006671e9  6a08                 push 8
// 006671eb  50                   push eax
// 006671ec  8bce                 mov ecx, esi
// 006671ee  e8d57bfbff           call 0x61edc8
// 006671f3  83f808               cmp eax, 8
// 006671f6  7409                 je 0x667201
// 006671f8  6a00                 push 0
// 006671fa  6a03                 push 3
// 006671fc  e8c17bfbff           call 0x61edc2
// 00667201  8bc6                 mov eax, esi
// 00667203  5e                   pop esi
// 00667204  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??5@YGAAVCArchive@@AAV0@AAUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
