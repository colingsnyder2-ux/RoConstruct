// from server: 100% by auto
// roc 2007-08 006b4990  unit: CXTPControlComboBoxGalleryPopupBar  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b4990
//
// 006b4990  e8cbefffff           call 0x6b3960
// 006b4995  8bc8                 mov ecx, eax
// 006b4997  e904ecffff           jmp 0x6b35a0
// library mfc-8.0/atlmfc\src\mfc\ctlprop.cpp (function ?GetText@COleControl@@QAEPA_WXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlprop.cpp
