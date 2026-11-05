// from server: 100% by auto
// roc 2011-06 0087ff40  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087ff40
//
// 0087ff40  68b0fe8700           push 0x87feb0
// 0087ff45  b9e48ed100           mov ecx, 0xd18ee4
// 0087ff4a  e81dca1400           call 0x9cc96c
// 0087ff4f  85c0                 test eax, eax
// 0087ff51  7505                 jne 0x87ff58
// 0087ff53  e9b2a3f8ff           jmp 0x80a30a
// 0087ff58  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
