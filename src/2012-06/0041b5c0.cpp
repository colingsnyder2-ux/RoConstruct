// from server: 100% by auto
// roc 2012-06 0041b5c0  unit: VCRbxObject::?$CComObjectNoLock  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041b5c0
//
// 0041b5c0  836c240404           sub dword ptr [esp + 4], 4
// 0041b5c5  e966fdffff           jmp 0x41b330
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
