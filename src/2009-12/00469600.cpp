// from server: 100% by auto
// roc 2009-12 00469600  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00469600
//
// 00469600  c701ccf49a00         mov dword ptr [ecx], 0x9af4cc
// 00469606  c74174a0f49a00       mov dword ptr [ecx + 0x74], 0x9af4a0
// 0046960d  e94e7af9ff           jmp 0x401060
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
