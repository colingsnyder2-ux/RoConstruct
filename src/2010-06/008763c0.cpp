// from server: 100% by auto
// roc 2010-06 008763c0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008763c0
//
// 008763c0  56                   push esi
// 008763c1  8bf1                 mov esi, ecx
// 008763c3  e8c01ef3ff           call 0x7a8288
// 008763c8  c706fccfa600         mov dword ptr [esi], 0xa6cffc
// 008763ce  c7465400000000       mov dword ptr [esi + 0x54], 0
// 008763d5  8bc6                 mov eax, esi
// 008763d7  5e                   pop esi
// 008763d8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
