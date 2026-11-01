// from server: 100% by auto
// roc 2009-12 00815ee0  unit: CXTPCommandBar  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00815ee0
//
// 00815ee0  85c9                 test ecx, ecx
// 00815ee2  7518                 jne 0x815efc
// 00815ee4  68b0647f00           push 0x7f64b0
// 00815ee9  b9d0bab900           mov ecx, 0xb9bad0
// 00815eee  e849051100           call 0x92643c
// 00815ef3  85c0                 test eax, eax
// 00815ef5  750a                 jne 0x815f01
// 00815ef7  e910dcfdff           jmp 0x7f3b0c
// 00815efc  e86ffcffff           call 0x815b70
// 00815f01  8bc8                 mov ecx, eax
// 00815f03  e918920500           jmp 0x86f120
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ClosePopups@CXTPCommandBars@@QBEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
