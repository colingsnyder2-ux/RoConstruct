// from server: 100% by auto
// roc 2007-08 0045bc30  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045bc30
//
// 0045bc30  c701443e7900         mov dword ptr [ecx], 0x793e44
// 0045bc36  c74174183e7900       mov dword ptr [ecx + 0x74], 0x793e18
// 0045bc3d  e9fe53faff           jmp 0x401040
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
