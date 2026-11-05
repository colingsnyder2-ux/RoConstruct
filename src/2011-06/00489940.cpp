// from server: 100% by auto
// roc 2011-06 00489940  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00489940
//
// 00489940  c701cc34a700         mov dword ptr [ecx], 0xa734cc
// 00489946  c74174a034a700       mov dword ptr [ecx + 0x74], 0xa734a0
// 0048994d  e90e77f7ff           jmp 0x401060
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
