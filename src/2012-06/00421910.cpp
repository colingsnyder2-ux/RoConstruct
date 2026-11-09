// from server: 100% by auto
// roc 2012-06 00421910  unit: RBX::DS::CVideoStream  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00421910
//
// 00421910  836c240404           sub dword ptr [esp + 4], 4
// 00421915  e9260b0000           jmp 0x422440
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
