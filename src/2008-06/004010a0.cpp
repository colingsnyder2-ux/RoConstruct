// from server: 100% by auto
// roc 2008-06 004010a0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004010a0
//
// 004010a0  c701c4aa8000         mov dword ptr [ecx], 0x80aac4
// 004010a6  c7417498aa8000       mov dword ptr [ecx + 0x74], 0x80aa98
// 004010ad  e99effffff           jmp 0x401050
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
