// from server: 100% by auto
// roc 2010-06 006bd130  unit: RBX::CharacterMesh  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006bd130
//
// 006bd130  e82bc7faff           call 0x669860
// 006bd135  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
