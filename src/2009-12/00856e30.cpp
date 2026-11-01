// from server: 100% by auto
// roc 2009-12 00856e30  unit: CXTPTabClientWnd::CWorkspace  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856e30
//
// 00856e30  68b0647f00           push 0x7f64b0
// 00856e35  b9d0bab900           mov ecx, 0xb9bad0
// 00856e3a  e8fdf50c00           call 0x92643c
// 00856e3f  85c0                 test eax, eax
// 00856e41  7505                 jne 0x856e48
// 00856e43  e9c4ccf9ff           jmp 0x7f3b0c
// 00856e48  6a00                 push 0
// 00856e4a  8bc8                 mov ecx, eax
// 00856e4c  e84f810100           call 0x86efa0
// 00856e51  f7d8                 neg eax
// 00856e53  1bc0                 sbb eax, eax
// 00856e55  f7d8                 neg eax
// 00856e57  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?IsMouseLocked@CWorkspace@CXTPTabClientWnd@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
