// from server: 100% by auto
// roc 2007-03 006f0490  unit: seg_006f0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f0490
//
// 006f0490  56                   push esi
// 006f0491  8bf1                 mov esi, ecx
// 006f0493  e83ae2f2ff           call 0x61e6d2
// 006f0498  6a00                 push 0
// 006f049a  c70544278c0000000000 mov dword ptr [0x8c2744], 0
// 006f04a4  8b4620               mov eax, dword ptr [esi + 0x20]
// 006f04a7  6a00                 push 0
// 006f04a9  50                   push eax
// 006f04aa  ff1554ee7700         call dword ptr [0x77ee54]
// 006f04b0  5e                   pop esi
// 006f04b1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnKillFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
