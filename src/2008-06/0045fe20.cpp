// from server: 100% by auto
// roc 2008-06 0045fe20  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045fe20
//
// 0045fe20  c70164a58100         mov dword ptr [ecx], 0x81a564
// 0045fe26  c7417438a58100       mov dword ptr [ecx + 0x74], 0x81a538
// 0045fe2d  e91e12faff           jmp 0x401050
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
