// from server: 100% by auto
// roc 2007-03 006671c0  unit: seg_00660000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006671c0
//
// 006671c0  8b442408             mov eax, dword ptr [esp + 8]
// 006671c4  56                   push esi
// 006671c5  8b742408             mov esi, dword ptr [esp + 8]
// 006671c9  6a10                 push 0x10
// 006671cb  50                   push eax
// 006671cc  8bce                 mov ecx, esi
// 006671ce  e8fb7bfbff           call 0x61edce
// 006671d3  8bc6                 mov eax, esi
// 006671d5  5e                   pop esi
// 006671d6  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@ABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
