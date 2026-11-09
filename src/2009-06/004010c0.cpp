// from server: 100% by auto
// roc 2009-06 004010c0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004010c0
//
// 004010c0  c70144c78a00         mov dword ptr [ecx], 0x8ac744
// 004010c6  c7417418c78a00       mov dword ptr [ecx + 0x74], 0x8ac718
// 004010cd  e99effffff           jmp 0x401070
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
