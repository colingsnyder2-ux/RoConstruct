// from server: 100% by auto
// roc 2009-12 004010b0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004010b0
//
// 004010b0  c701a4f29900         mov dword ptr [ecx], 0x99f2a4
// 004010b6  c7417478f29900       mov dword ptr [ecx + 0x74], 0x99f278
// 004010bd  e99effffff           jmp 0x401060
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
