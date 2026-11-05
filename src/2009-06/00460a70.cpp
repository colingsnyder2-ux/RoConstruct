// from server: 100% by auto
// roc 2009-06 00460a70  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00460a70
//
// 00460a70  c70124af8b00         mov dword ptr [ecx], 0x8baf24
// 00460a76  c74174f8ae8b00       mov dword ptr [ecx + 0x74], 0x8baef8
// 00460a7d  e9ee05faff           jmp 0x401070
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
