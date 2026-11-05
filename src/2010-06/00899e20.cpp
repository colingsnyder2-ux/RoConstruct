// from server: 100% by auto
// roc 2010-06 00899e20  unit: CXTColorSelectorCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899e20
//
// 00899e20  56                   push esi
// 00899e21  8bf1                 mov esi, ecx
// 00899e23  e848e1f0ff           call 0x7a7f70
// 00899e28  8b4620               mov eax, dword ptr [esi + 0x20]
// 00899e2b  6a00                 push 0
// 00899e2d  6a00                 push 0
// 00899e2f  50                   push eax
// 00899e30  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899e36  5e                   pop esi
// 00899e37  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?OnEnable@CXTPCommandBarScrollBarCtrl@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
