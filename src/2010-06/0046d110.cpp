// from server: 100% by auto
// roc 2010-06 0046d110  unit: CRobloxWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046d110
//
// 0046d110  c7014401a100         mov dword ptr [ecx], 0xa10144
// 0046d116  c741741801a100       mov dword ptr [ecx + 0x74], 0xa10118
// 0046d11d  e93e3ff9ff           jmp 0x401060
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1CMultiPageDHtmlDialog@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
