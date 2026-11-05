// from server: 100% by auto
// roc 2010-06 007b5e40  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b5e40
//
// 007b5e40  e82b21ffff           call 0x7a7f70
// 007b5e45  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
