// from server: 100% by auto
// roc 2007-03 004593c0  unit: seg_00450000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004593c0
//
// 004593c0  c701cc2b7900         mov dword ptr [ecx], 0x792bcc
// 004593c6  c74174a02b7900       mov dword ptr [ecx + 0x74], 0x792ba0
// 004593cd  e98e7cfaff           jmp 0x401060
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
