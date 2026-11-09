// from server: 100% by auto
// roc 2011-06 0047dd00  unit: VCRbxObject::?$CComObjectNoLock  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0047dd00
//
// 0047dd00  836c240404           sub dword ptr [esp + 4], 4
// 0047dd05  e986a1f9ff           jmp 0x417e90
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
