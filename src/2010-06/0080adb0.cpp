// from server: 100% by auto
// roc 2010-06 0080adb0  unit: CXTPTabClientWnd::CWorkspace  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080adb0
//
// 0080adb0  68e0a57a00           push 0x7aa5e0
// 0080adb5  b90062c200           mov ecx, 0xc26200
// 0080adba  e8b91f1700           call 0x97cd78
// 0080adbf  85c0                 test eax, eax
// 0080adc1  7505                 jne 0x80adc8
// 0080adc3  e984cef9ff           jmp 0x7a7c4c
// 0080adc8  6a00                 push 0
// 0080adca  8bc8                 mov ecx, eax
// 0080adcc  e8df810100           call 0x822fb0
// 0080add1  f7d8                 neg eax
// 0080add3  1bc0                 sbb eax, eax
// 0080add5  f7d8                 neg eax
// 0080add7  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?IsMouseLocked@CWorkspace@CXTPTabClientWnd@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
