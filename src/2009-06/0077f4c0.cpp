// from server: 100% by auto
// roc 2009-06 0077f4c0  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f4c0
//
// 0077f4c0  6850f47700           push 0x77f450
// 0077f4c5  b91822a500           mov ecx, 0xa52218
// 0077f4ca  e853cf0c00           call 0x84c422
// 0077f4cf  85c0                 test eax, eax
// 0077f4d1  7505                 jne 0x77f4d8
// 0077f4d3  e90c98f9ff           jmp 0x718ce4
// 0077f4d8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
