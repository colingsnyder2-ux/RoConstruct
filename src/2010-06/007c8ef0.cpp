// from server: 100% by auto
// roc 2010-06 007c8ef0  unit: CXTPCommandBarKeyboardTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8ef0
//
// 007c8ef0  83ec08               sub esp, 8
// 007c8ef3  56                   push esi
// 007c8ef4  8bf1                 mov esi, ecx
// 007c8ef6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c8efa  898ea0000000         mov dword ptr [esi + 0xa0], ecx
// 007c8f00  85c9                 test ecx, ecx
// 007c8f02  7423                 je 0x7c8f27
// 007c8f04  83792000             cmp dword ptr [ecx + 0x20], 0
// 007c8f08  741d                 je 0x7c8f27
// 007c8f0a  8d442404             lea eax, [esp + 4]
// 007c8f0e  50                   push eax
// 007c8f0f  56                   push esi
// 007c8f10  6a00                 push 0
// 007c8f12  68b9880000           push 0x88b9
// 007c8f17  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007c8f1f  e880f2fdff           call 0x7a81a4
// 007c8f24  894660               mov dword ptr [esi + 0x60], eax
// 007c8f27  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007c8f2d  e8b23e1b00           call 0x97cde4
// 007c8f32  2500004000           and eax, 0x400000
// 007c8f37  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 007c8f3d  5e                   pop esi
// 007c8f3e  83c408               add esp, 8
// 007c8f41  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetSite@CXTPCommandBars@@QAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
