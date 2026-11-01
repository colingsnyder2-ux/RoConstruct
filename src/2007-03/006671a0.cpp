// from server: 100% by auto
// roc 2007-03 006671a0  unit: seg_00660000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006671a0
//
// 006671a0  56                   push esi
// 006671a1  8b742408             mov esi, dword ptr [esp + 8]
// 006671a5  6a08                 push 8
// 006671a7  8d442410             lea eax, [esp + 0x10]
// 006671ab  50                   push eax
// 006671ac  8bce                 mov ecx, esi
// 006671ae  e81b7cfbff           call 0x61edce
// 006671b3  8bc6                 mov eax, esi
// 006671b5  5e                   pop esi
// 006671b6  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
