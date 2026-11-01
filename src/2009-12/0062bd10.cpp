// from server: 100% by auto
// roc 2009-12 0062bd10  unit: seg_00620000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062bd10
//
// 0062bd10  e80bbb1b00           call 0x7e7820
// 0062bd15  8bc8                 mov ecx, eax
// 0062bd17  e914a21b00           jmp 0x7e5f30
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
