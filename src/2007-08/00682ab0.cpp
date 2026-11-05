// from server: 100% by auto
// roc 2007-08 00682ab0  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00682ab0
//
// 00682ab0  e86bffffff           call 0x682a20
// 00682ab5  8bc8                 mov ecx, eax
// 00682ab7  e9b4930100           jmp 0x69be70
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
