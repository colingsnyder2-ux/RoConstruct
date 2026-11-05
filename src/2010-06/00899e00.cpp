// from server: 100% by auto
// roc 2010-06 00899e00  unit: CXTColorSelectorCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899e00
//
// 00899e00  8b442404             mov eax, dword ptr [esp + 4]
// 00899e04  56                   push esi
// 00899e05  50                   push eax
// 00899e06  8bf1                 mov esi, ecx
// 00899e08  e8c1e9f0ff           call 0x7a87ce
// 00899e0d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00899e10  6a00                 push 0
// 00899e12  6a00                 push 0
// 00899e14  51                   push ecx
// 00899e15  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899e1b  5e                   pop esi
// 00899e1c  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnSetFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
