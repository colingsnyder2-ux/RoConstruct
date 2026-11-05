// from server: 100% by auto
// roc 2009-06 0071daa0  unit: CPatchedControlComboBox  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071daa0
//
// 0071daa0  68f0b87100           push 0x71b8f0
// 0071daa5  b99426a500           mov ecx, 0xa52694
// 0071daaa  e851e41200           call 0x84bf00
// 0071daaf  85c0                 test eax, eax
// 0071dab1  7505                 jne 0x71dab8
// 0071dab3  e92cb2ffff           jmp 0x718ce4
// 0071dab8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
