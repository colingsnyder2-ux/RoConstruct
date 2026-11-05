// from server: 100% by auto
// roc 2007-08 006920c0  unit: CXTThemeManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006920c0
//
// 006920c0  e87bf8ffff           call 0x691940
// 006920c5  8bc8                 mov ecx, eax
// 006920c7  e974ffffff           jmp 0x692040
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
