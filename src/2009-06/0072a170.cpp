// from server: 100% by auto
// roc 2009-06 0072a170  unit: CXTPCommandBarKeyboardTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072a170
//
// 0072a170  83ec08               sub esp, 8
// 0072a173  56                   push esi
// 0072a174  8bf1                 mov esi, ecx
// 0072a176  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0072a17a  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 0072a180  85c9                 test ecx, ecx
// 0072a182  7423                 je 0x72a1a7
// 0072a184  83792000             cmp dword ptr [ecx + 0x20], 0
// 0072a188  741d                 je 0x72a1a7
// 0072a18a  8d442404             lea eax, [esp + 4]
// 0072a18e  50                   push eax
// 0072a18f  56                   push esi
// 0072a190  6a00                 push 0
// 0072a192  68b9880000           push 0x88b9
// 0072a197  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0072a19f  e898f0feff           call 0x71923c
// 0072a1a4  894660               mov dword ptr [esi + 0x60], eax
// 0072a1a7  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0072a1ad  e8301d1200           call 0x84bee2
// 0072a1b2  2500004000           and eax, 0x400000
// 0072a1b7  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 0072a1bd  5e                   pop esi
// 0072a1be  83c408               add esp, 8
// 0072a1c1  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetSite@CXTPCommandBars@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
