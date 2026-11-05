// from server: 100% by auto
// roc 2011-06 0080e050  unit: PAVCXTPControlAction::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0080e050
//
// 0080e050  68b0cb8000           push 0x80cbb0
// 0080e055  b9e88ed100           mov ecx, 0xd18ee8
// 0080e05a  e865e51b00           call 0x9cc5c4
// 0080e05f  85c0                 test eax, eax
// 0080e061  7505                 jne 0x80e068
// 0080e063  e9a2c2ffff           jmp 0x80a30a
// 0080e068  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
