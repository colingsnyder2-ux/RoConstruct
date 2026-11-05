// from server: 100% by auto
// roc 2007-08 004010a0  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004010a0
//
// 004010a0  c70174477800         mov dword ptr [ecx], 0x784774
// 004010a6  c7417448477800       mov dword ptr [ecx + 0x74], 0x784748
// 004010ad  e98effffff           jmp 0x401040
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
