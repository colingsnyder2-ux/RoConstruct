// from server: 100% by auto
// roc 2007-03 0066f860  unit: seg_00660000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066f860
//
// 0066f860  68300c6200           push 0x620c30
// 0066f865  b910238c00           mov ecx, 0x8c2310
// 0066f86a  e835b20c00           call 0x73aaa4
// 0066f86f  85c0                 test eax, eax
// 0066f871  7505                 jne 0x66f878
// 0066f873  e936ebfaff           jmp 0x61e3ae
// 0066f878  6a00                 push 0
// 0066f87a  8bc8                 mov ecx, eax
// 0066f87c  e8ffd90100           call 0x68d280
// 0066f881  f7d8                 neg eax
// 0066f883  1bc0                 sbb eax, eax
// 0066f885  f7d8                 neg eax
// 0066f887  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?IsMouseLocked@CWorkspace@CXTPTabClientWnd@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
