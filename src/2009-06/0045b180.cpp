// from server: 100% by auto
// roc 2009-06 0045b180  unit: CRobloxWnd::PartDropTarget  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045b180
//
// 0045b180  e8fbfeffff           call 0x45b080
// 0045b185  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
