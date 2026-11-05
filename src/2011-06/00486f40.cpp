// from server: 100% by auto
// roc 2011-06 00486f40  unit: CRobloxWnd::PartDropTarget  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00486f40
//
// 00486f40  e8ebfeffff           call 0x486e30
// 00486f45  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
