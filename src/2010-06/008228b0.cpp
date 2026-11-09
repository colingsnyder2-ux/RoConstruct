// from server: 100% by auto
// roc 2010-06 008228b0  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008228b0
//
// 008228b0  6820288200           push 0x822820
// 008228b5  b9fc61c200           mov ecx, 0xc261fc
// 008228ba  e811aa1500           call 0x97d2d0
// 008228bf  85c0                 test eax, eax
// 008228c1  7505                 jne 0x8228c8
// 008228c3  e98453f8ff           jmp 0x7a7c4c
// 008228c8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
