// from server: 100% by auto
// roc 2011-06 004010b0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004010b0
//
// 004010b0  c701ecb3a500         mov dword ptr [ecx], 0xa5b3ec
// 004010b6  c74174c0b3a500       mov dword ptr [ecx + 0x74], 0xa5b3c0
// 004010bd  e99effffff           jmp 0x401060
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
