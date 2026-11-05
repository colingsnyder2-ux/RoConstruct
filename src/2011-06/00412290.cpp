// from server: 100% by auto
// roc 2011-06 00412290  unit: CNullDoc  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00412290
//
// 00412290  85c9                 test ecx, ecx
// 00412292  7503                 jne 0x412297
// 00412294  33c0                 xor eax, eax
// 00412296  c3                   ret 
// 00412297  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041229a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
