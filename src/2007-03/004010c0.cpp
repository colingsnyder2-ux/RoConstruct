// from server: 100% by auto
// roc 2007-03 004010c0  unit: seg_00400000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004010c0
//
// 004010c0  c70174377800         mov dword ptr [ecx], 0x783774
// 004010c6  c7417448377800       mov dword ptr [ecx + 0x74], 0x783748
// 004010cd  e98effffff           jmp 0x401060
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
