// from server: 100% by auto
// roc 2011-06 00466a80  unit: RBX::Tasks::Sequence  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00466a80
//
// 00466a80  e82ba53900           call 0x800fb0
// 00466a85  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
