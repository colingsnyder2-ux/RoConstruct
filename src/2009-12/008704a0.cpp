// from server: 100% by auto
// roc 2009-12 008704a0  unit: CXTPNewToolbarDlg  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008704a0
//
// 008704a0  8bc1                 mov eax, ecx
// 008704a2  c700440da000         mov dword ptr [eax], 0xa00d44
// 008704a8  c7400400000000       mov dword ptr [eax + 4], 0
// 008704af  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ??0CGdiObject@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
