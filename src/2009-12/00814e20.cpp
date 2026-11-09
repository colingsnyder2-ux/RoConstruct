// from server: 100% by auto
// roc 2009-12 00814e20  unit: CXTPCommandBarKeyboardTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814e20
//
// 00814e20  83ec08               sub esp, 8
// 00814e23  56                   push esi
// 00814e24  8bf1                 mov esi, ecx
// 00814e26  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00814e2a  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 00814e30  85c9                 test ecx, ecx
// 00814e32  7423                 je 0x814e57
// 00814e34  83792000             cmp dword ptr [ecx + 0x20], 0
// 00814e38  741d                 je 0x814e57
// 00814e3a  8d442404             lea eax, [esp + 4]
// 00814e3e  50                   push eax
// 00814e3f  56                   push esi
// 00814e40  6a00                 push 0
// 00814e42  68b9880000           push 0x88b9
// 00814e47  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00814e4f  e810f2fdff           call 0x7f4064
// 00814e54  894660               mov dword ptr [esi + 0x60], eax
// 00814e57  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00814e5d  e816161100           call 0x926478
// 00814e62  2500004000           and eax, 0x400000
// 00814e67  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 00814e6d  5e                   pop esi
// 00814e6e  83c408               add esp, 8
// 00814e71  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetSite@CXTPCommandBars@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
