// from server: 100% by auto
// roc 2007-03 006948f0  unit: seg_00690000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006948f0
//
// 006948f0  8b4154               mov eax, dword ptr [ecx + 0x54]
// 006948f3  a900280000           test eax, 0x2800
// 006948f8  7403                 je 0x6948fd
// 006948fa  33c0                 xor eax, eax
// 006948fc  c3                   ret 
// 006948fd  a900820000           test eax, 0x8200
// 00694902  7406                 je 0x69490a
// 00694904  b801000000           mov eax, 1
// 00694909  c3                   ret 
// 0069490a  2500140000           and eax, 0x1400
// 0069490f  f7d8                 neg eax
// 00694911  1bc0                 sbb eax, eax
// 00694913  83c003               add eax, 3
// 00694916  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?GetPosition@CXTPDockBar@@QBE?AW4XTPBarPosition@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
