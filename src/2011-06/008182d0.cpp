// from server: 100% by auto
// roc 2011-06 008182d0  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008182d0
//
// 008182d0  e85923ffff           call 0x80a62e
// 008182d5  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
