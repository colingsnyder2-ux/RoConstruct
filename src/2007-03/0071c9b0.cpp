// from server: 100% by auto
// roc 2007-03 0071c9b0  unit: seg_00710000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071c9b0
//
// 0071c9b0  56                   push esi
// 0071c9b1  8bf1                 mov esi, ecx
// 0071c9b3  e81a1df0ff           call 0x61e6d2
// 0071c9b8  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071c9bb  6a00                 push 0
// 0071c9bd  6a00                 push 0
// 0071c9bf  50                   push eax
// 0071c9c0  ff1554ee7700         call dword ptr [0x77ee54]
// 0071c9c6  5e                   pop esi
// 0071c9c7  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnKillFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
