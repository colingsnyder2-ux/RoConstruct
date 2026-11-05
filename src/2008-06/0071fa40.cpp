// from server: 100% by auto
// roc 2008-06 0071fa40  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071fa40
//
// 0071fa40  68b0f97100           push 0x71f9b0
// 0071fa45  b9aced9700           mov ecx, 0x97edac
// 0071fa4a  e81fcb0900           call 0x7bc56e
// 0071fa4f  85c0                 test eax, eax
// 0071fa51  7505                 jne 0x71fa58
// 0071fa53  e9ec0ef8ff           jmp 0x6a0944
// 0071fa58  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
