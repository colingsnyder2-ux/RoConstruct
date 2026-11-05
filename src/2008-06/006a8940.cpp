// from server: 100% by auto
// roc 2008-06 006a8940  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a8940
//
// 006a8940  e82383ffff           call 0x6a0c68
// 006a8945  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
