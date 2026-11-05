// from server: 100% by auto
// roc 2007-08 0066aaa0  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0066aaa0
//
// 0066aaa0  e8cbe4ffff           call 0x668f70
// 0066aaa5  8bc8                 mov ecx, eax
// 0066aaa7  e9b4f6ffff           jmp 0x66a160
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
