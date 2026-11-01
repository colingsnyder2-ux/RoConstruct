// from server: 100% by auto
// roc 2009-06 007b2580  unit: CXTPDockBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2580
//
// 007b2580  8b4154               mov eax, dword ptr [ecx + 0x54]
// 007b2583  a900280000           test eax, 0x2800
// 007b2588  7403                 je 0x7b258d
// 007b258a  33c0                 xor eax, eax
// 007b258c  c3                   ret 
// 007b258d  a900820000           test eax, 0x8200
// 007b2592  7406                 je 0x7b259a
// 007b2594  b801000000           mov eax, 1
// 007b2599  c3                   ret 
// 007b259a  2500140000           and eax, 0x1400
// 007b259f  f7d8                 neg eax
// 007b25a1  1bc0                 sbb eax, eax
// 007b25a3  83c003               add eax, 3
// 007b25a6  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?GetPosition@CXTPDockBar@@QBE?AW4XTPBarPosition@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
