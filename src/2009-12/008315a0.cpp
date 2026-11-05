// from server: 100% by auto
// roc 2009-12 008315a0  unit: CXTPColorManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008315a0
//
// 008315a0  e82be4ffff           call 0x82f9d0
// 008315a5  8bc8                 mov ecx, eax
// 008315a7  e964f6ffff           jmp 0x830c10
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
