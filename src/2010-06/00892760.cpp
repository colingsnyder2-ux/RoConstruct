// from server: 100% by auto
// roc 2010-06 00892760  unit: CXTColorLum  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892760
//
// 00892760  56                   push esi
// 00892761  8bf1                 mov esi, ecx
// 00892763  e80858f1ff           call 0x7a7f70
// 00892768  6a00                 push 0
// 0089276a  c7055466c20000000000 mov dword ptr [0xc26654], 0
// 00892774  8b4620               mov eax, dword ptr [esi + 0x20]
// 00892777  6a00                 push 0
// 00892779  50                   push eax
// 0089277a  ff1578ba9e00         call dword ptr [0x9eba78]
// 00892780  5e                   pop esi
// 00892781  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnKillFocus@CXTColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
