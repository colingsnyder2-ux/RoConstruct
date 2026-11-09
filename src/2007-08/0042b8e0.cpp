// from server: 100% by auto
// roc 2007-08 0042b8e0  unit: VCLuaFunction::?$CComObjectNoLock  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042b8e0
//
// 0042b8e0  836c240404           sub dword ptr [esp + 4], 4
// 0042b8e5  e9f6fcffff           jmp 0x42b5e0
// library mfc-8.0/atlmfc\src\mfc\dlgprntx.cpp (function ?AddRef@CPrintDialogEx@@W3AGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgprntx.cpp
