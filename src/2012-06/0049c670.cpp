// from server: 100% by auto
// roc 2012-06 0049c670  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049c670
//
// 0049c670  c70174fab500         mov dword ptr [ecx], 0xb5fa74
// 0049c676  c7417448fab500       mov dword ptr [ecx + 0x74], 0xb5fa48
// 0049c67d  e9ce49f6ff           jmp 0x401050
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
