// from server: 100% by auto
// roc 2011-06 006f01e0  unit: RBX::CharacterMesh  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006f01e0
//
// 006f01e0  e88b2afaff           call 0x692c70
// 006f01e5  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkeyassignctrl.cpp (function ?OnKillFocus@CWnd@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkeyassignctrl.cpp
