// from server: 100% by auto
// roc 2008-06 006a3b40  unit: MyXTPCommandBars  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a3b40
//
// 006a3b40  6810306a00           push 0x6a3010
// 006a3b45  b99ced9700           mov ecx, 0x97ed9c
// 006a3b4a  e88b841100           call 0x7bbfda
// 006a3b4f  85c0                 test eax, eax
// 006a3b51  7505                 jne 0x6a3b58
// 006a3b53  e9eccdffff           jmp 0x6a0944
// 006a3b58  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
