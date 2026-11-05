// from server: 100% by auto
// roc 2009-12 00878e70  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00878e70
//
// 00878e70  e81bebffff           call 0x877990
// 00878e75  8bc8                 mov ecx, eax
// 00878e77  e974e5ffff           jmp 0x8773f0
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
