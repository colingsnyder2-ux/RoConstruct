// from server: 100% by auto
// roc 2009-12 0084dc20  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084dc20
//
// 0084dc20  e85bfeffff           call 0x84da80
// 0084dc25  8bc8                 mov ecx, eax
// 0084dc27  e914b10100           jmp 0x868d40
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
