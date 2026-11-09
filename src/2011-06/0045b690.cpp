// from server: 100% by auto
// roc 2011-06 0045b690  unit: VCRoblox3D::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045b690
//
// 0045b690  836c240404           sub dword ptr [esp + 4], 4
// 0045b695  e956feffff           jmp 0x45b4f0
// library mfc-9.0/atlmfc\src\mfc\dlgprntx.cpp (function ?Release@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgprntx.cpp
