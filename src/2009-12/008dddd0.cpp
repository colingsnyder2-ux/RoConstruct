// from server: 100% by auto
// roc 2009-12 008dddd0  unit: CXTColorWnd  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dddd0
//
// 008dddd0  56                   push esi
// 008dddd1  8bf1                 mov esi, ecx
// 008dddd3  e85860f1ff           call 0x7f3e30
// 008dddd8  6a00                 push 0
// 008dddda  c70524bfb90000000000 mov dword ptr [0xb9bf24], 0
// 008ddde4  8b4620               mov eax, dword ptr [esi + 0x20]
// 008ddde7  6a00                 push 0
// 008ddde9  50                   push eax
// 008dddea  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008dddf0  5e                   pop esi
// 008dddf1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnKillFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
