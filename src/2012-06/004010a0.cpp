// from server: 100% by auto
// roc 2012-06 004010a0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004010a0
//
// 004010a0  c701cc2cb400         mov dword ptr [ecx], 0xb42ccc
// 004010a6  c74174a02cb400       mov dword ptr [ecx + 0x74], 0xb42ca0
// 004010ad  e99effffff           jmp 0x401050
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
