// from server: 100% by auto
// roc 2011-06 0086bcb0  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086bcb0
//
// 0086bcb0  6840bc8600           push 0x86bc40
// 0086bcb5  b9848ad100           mov ecx, 0xd18a84
// 0086bcba  e8ad0c1600           call 0x9cc96c
// 0086bcbf  85c0                 test eax, eax
// 0086bcc1  7505                 jne 0x86bcc8
// 0086bcc3  e942e6f9ff           jmp 0x80a30a
// 0086bcc8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
