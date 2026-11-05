// roc 2009-12 004782ff  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004782ff
//
// 004782ff  b805834700           mov eax, 0x478305
// 00478304  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
