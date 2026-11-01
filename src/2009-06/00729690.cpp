// from server: 100% by auto
// roc 2009-06 00729690  unit: CXTPCommandBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729690
//
// 00729690  56                   push esi
// 00729691  8bf1                 mov esi, ecx
// 00729693  e8f83c0000           call 0x72d390
// 00729698  85c0                 test eax, eax
// 0072969a  740c                 je 0x7296a8
// 0072969c  397040               cmp dword ptr [eax + 0x40], esi
// 0072969f  7507                 jne 0x7296a8
// 007296a1  8b4044               mov eax, dword ptr [eax + 0x44]
// 007296a4  85c0                 test eax, eax
// 007296a6  7f02                 jg 0x7296aa
// 007296a8  33c0                 xor eax, eax
// 007296aa  5e                   pop esi
// 007296ab  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardTipsVisible@CXTPCommandBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
