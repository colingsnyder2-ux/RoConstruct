// from server: 100% by auto
// roc 2010-06 0080e510  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e510
//
// 0080e510  68a0e48000           push 0x80e4a0
// 0080e515  b9a05dc200           mov ecx, 0xc25da0
// 0080e51a  e8b1ed1600           call 0x97d2d0
// 0080e51f  85c0                 test eax, eax
// 0080e521  7505                 jne 0x80e528
// 0080e523  e92497f9ff           jmp 0x7a7c4c
// 0080e528  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
