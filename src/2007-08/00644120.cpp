// from server: 100% by auto
// roc 2007-08 00644120  unit: CXTPCommandBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00644120
//
// 00644120  8389e400000002       or dword ptr [ecx + 0xe4], 2
// 00644127  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\olecli2.cpp (function ?DelayUpdateFrameTitle@CFrameWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olecli2.cpp
