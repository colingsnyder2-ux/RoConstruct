// from server: 100% by auto
// roc 2009-12 00890f50  unit: ATL::CRegObject  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00890f50
//
// 00890f50  8b4154               mov eax, dword ptr [ecx + 0x54]
// 00890f53  a900280000           test eax, 0x2800
// 00890f58  7403                 je 0x890f5d
// 00890f5a  33c0                 xor eax, eax
// 00890f5c  c3                   ret 
// 00890f5d  a900820000           test eax, 0x8200
// 00890f62  7406                 je 0x890f6a
// 00890f64  b801000000           mov eax, 1
// 00890f69  c3                   ret 
// 00890f6a  2500140000           and eax, 0x1400
// 00890f6f  f7d8                 neg eax
// 00890f71  1bc0                 sbb eax, eax
// 00890f73  83c003               add eax, 3
// 00890f76  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?GetPosition@CXTPDockBar@@QBE?AW4XTPBarPosition@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
