// from server: 100% by auto
// roc 2010-06 00845140  unit: CXTPDockBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845140
//
// 00845140  8b4154               mov eax, dword ptr [ecx + 0x54]
// 00845143  a900280000           test eax, 0x2800
// 00845148  7403                 je 0x84514d
// 0084514a  33c0                 xor eax, eax
// 0084514c  c3                   ret 
// 0084514d  a900820000           test eax, 0x8200
// 00845152  7406                 je 0x84515a
// 00845154  b801000000           mov eax, 1
// 00845159  c3                   ret 
// 0084515a  2500140000           and eax, 0x1400
// 0084515f  f7d8                 neg eax
// 00845161  1bc0                 sbb eax, eax
// 00845163  83c003               add eax, 3
// 00845166  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?GetPosition@CXTPDockBar@@QBE?AW4XTPBarPosition@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
