// from server: 100% by auto
// roc 2008-06 0076efd0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076efd0
//
// 0076efd0  56                   push esi
// 0076efd1  8bf1                 mov esi, ecx
// 0076efd3  e8b81ef3ff           call 0x6a0e90
// 0076efd8  c70674788600         mov dword ptr [esi], 0x867874
// 0076efde  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0076efe5  8bc6                 mov eax, esi
// 0076efe7  5e                   pop esi
// 0076efe8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
