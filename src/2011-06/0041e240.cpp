// from server: 100% by auto
// roc 2011-06 0041e240  unit: RBX::DS::CVideoStream  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0041e240
//
// 0041e240  836c240404           sub dword ptr [esp + 4], 4
// 0041e245  e9b6ffffff           jmp 0x41e200
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
