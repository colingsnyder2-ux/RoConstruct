// from server: 100% by auto
// roc 2008-06 0070dcd0  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070dcd0
//
// 0070dcd0  6860dc7000           push 0x70dc60
// 0070dcd5  b92ce99700           mov ecx, 0x97e92c
// 0070dcda  e88fe80a00           call 0x7bc56e
// 0070dcdf  85c0                 test eax, eax
// 0070dce1  7505                 jne 0x70dce8
// 0070dce3  e95c2cf9ff           jmp 0x6a0944
// 0070dce8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
