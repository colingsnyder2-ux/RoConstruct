// from server: 100% by auto
// roc 2011-06 0082a9c0  unit: CXTPCommandBarKeyboardTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082a9c0
//
// 0082a9c0  83ec08               sub esp, 8
// 0082a9c3  56                   push esi
// 0082a9c4  8bf1                 mov esi, ecx
// 0082a9c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0082a9ca  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 0082a9d0  85c9                 test ecx, ecx
// 0082a9d2  7423                 je 0x82a9f7
// 0082a9d4  83792000             cmp dword ptr [ecx + 0x20], 0
// 0082a9d8  741d                 je 0x82a9f7
// 0082a9da  8d442404             lea eax, [esp + 4]
// 0082a9de  50                   push eax
// 0082a9df  56                   push esi
// 0082a9e0  6a00                 push 0
// 0082a9e2  68b9880000           push 0x88b9
// 0082a9e7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0082a9ef  e86efefdff           call 0x80a862
// 0082a9f4  894660               mov dword ptr [esi + 0x60], eax
// 0082a9f7  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0082a9fd  e81c1c1a00           call 0x9cc61e
// 0082aa02  2500004000           and eax, 0x400000
// 0082aa07  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 0082aa0d  5e                   pop esi
// 0082aa0e  83c408               add esp, 8
// 0082aa11  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetSite@CXTPCommandBars@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
