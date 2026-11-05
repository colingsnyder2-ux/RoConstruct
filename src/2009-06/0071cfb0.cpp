// from server: 100% by auto
// roc 2009-06 0071cfb0  unit: CXTPControlComboBoxList  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071cfb0
//
// 0071cfb0  e853c0ffff           call 0x719008
// 0071cfb5  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
