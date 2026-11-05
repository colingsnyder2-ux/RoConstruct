// from server: 100% by auto
// roc 2010-06 007c9fb0  unit: CXTPCommandBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c9fb0
//
// 007c9fb0  85c9                 test ecx, ecx
// 007c9fb2  7518                 jne 0x7c9fcc
// 007c9fb4  68e0a57a00           push 0x7aa5e0
// 007c9fb9  b90062c200           mov ecx, 0xc26200
// 007c9fbe  e8b52d1b00           call 0x97cd78
// 007c9fc3  85c0                 test eax, eax
// 007c9fc5  750a                 jne 0x7c9fd1
// 007c9fc7  e980dcfdff           jmp 0x7a7c4c
// 007c9fcc  e86ffcffff           call 0x7c9c40
// 007c9fd1  8bc8                 mov ecx, eax
// 007c9fd3  e958910500           jmp 0x823130
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ClosePopups@CXTPCommandBars@@QBEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
