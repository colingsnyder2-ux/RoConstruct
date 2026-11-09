// from server: 100% by auto
// roc 2010-06 004010b0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004010b0
//
// 004010b0  c70144fe9f00         mov dword ptr [ecx], 0x9ffe44
// 004010b6  c7417418fe9f00       mov dword ptr [ecx + 0x74], 0x9ffe18
// 004010bd  e99effffff           jmp 0x401060
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
