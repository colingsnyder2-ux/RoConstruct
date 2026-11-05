// from server: 100% by auto
// roc 2009-12 008c21a0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c21a0
//
// 008c21a0  56                   push esi
// 008c21a1  8bf1                 mov esi, ecx
// 008c21a3  e8a01ff3ff           call 0x7f4148
// 008c21a8  c706148da000         mov dword ptr [esi], 0xa08d14
// 008c21ae  c7465400000000       mov dword ptr [esi + 0x54], 0
// 008c21b5  8bc6                 mov eax, esi
// 008c21b7  5e                   pop esi
// 008c21b8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
