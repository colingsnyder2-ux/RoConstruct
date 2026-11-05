// from server: 100% by auto
// roc 2007-08 00685bb0  unit: CInstanceRecord::CNameItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00685bb0
//
// 00685bb0  56                   push esi
// 00685bb1  8b742408             mov esi, dword ptr [esp + 8]
// 00685bb5  6a08                 push 8
// 00685bb7  8d442410             lea eax, [esp + 0x10]
// 00685bbb  50                   push eax
// 00685bbc  8bce                 mov ecx, esi
// 00685bbe  e8d1aafaff           call 0x630694
// 00685bc3  8bc6                 mov eax, esi
// 00685bc5  5e                   pop esi
// 00685bc6  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dockstat.cpp (function ??6@YGAAVCArchive@@AAV0@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dockstat.cpp
