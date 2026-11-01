// from server: 100% by auto
// roc 2007-03 0062d420  unit: seg_00620000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062d420
//
// 0062d420  85c9                 test ecx, ecx
// 0062d422  7518                 jne 0x62d43c
// 0062d424  68300c6200           push 0x620c30
// 0062d429  b910238c00           mov ecx, 0x8c2310
// 0062d42e  e871d61000           call 0x73aaa4
// 0062d433  85c0                 test eax, eax
// 0062d435  750a                 jne 0x62d441
// 0062d437  e9720fffff           jmp 0x61e3ae
// 0062d43c  e86ffcffff           call 0x62d0b0
// 0062d441  8bc8                 mov ecx, eax
// 0062d443  e968ff0500           jmp 0x68d3b0
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?ClosePopups@CXTPCommandBars@@QBEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
