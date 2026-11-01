// from server: 100% by auto
// roc 2007-03 0069f260  unit: seg_00690000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069f260
//
// 0069f260  68e0f16900           push 0x69f1e0
// 0069f265  b934238c00           mov ecx, 0x8c2334
// 0069f26a  e8b9be0900           call 0x73b128
// 0069f26f  85c0                 test eax, eax
// 0069f271  7505                 jne 0x69f278
// 0069f273  e936f1f7ff           jmp 0x61e3ae
// 0069f278  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
