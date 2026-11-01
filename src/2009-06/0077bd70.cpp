// from server: 100% by auto
// roc 2009-06 0077bd70  unit: CXTPTabClientWnd::CWorkspace  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077bd70
//
// 0077bd70  68f0b87100           push 0x71b8f0
// 0077bd75  b99426a500           mov ecx, 0xa52694
// 0077bd7a  e881010d00           call 0x84bf00
// 0077bd7f  85c0                 test eax, eax
// 0077bd81  7505                 jne 0x77bd88
// 0077bd83  e95ccff9ff           jmp 0x718ce4
// 0077bd88  6a00                 push 0
// 0077bd8a  8bc8                 mov ecx, eax
// 0077bd8c  e8af800100           call 0x793e40
// 0077bd91  f7d8                 neg eax
// 0077bd93  1bc0                 sbb eax, eax
// 0077bd95  f7d8                 neg eax
// 0077bd97  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?IsMouseLocked@CWorkspace@CXTPTabClientWnd@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
