// from server: 100% by auto
// roc 2010-06 007abb70  unit: PAVCXTPControlAction::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007abb70
//
// 007abb70  68e0a57a00           push 0x7aa5e0
// 007abb75  b90062c200           mov ecx, 0xc26200
// 007abb7a  e8f9111d00           call 0x97cd78
// 007abb7f  85c0                 test eax, eax
// 007abb81  7505                 jne 0x7abb88
// 007abb83  e9c4c0ffff           jmp 0x7a7c4c
// 007abb88  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
