// from server: 100% by auto
// roc 2009-12 008e5b00  unit: CXTColorSelectorCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5b00
//
// 008e5b00  56                   push esi
// 008e5b01  8bf1                 mov esi, ecx
// 008e5b03  e828e3f0ff           call 0x7f3e30
// 008e5b08  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e5b0b  6a00                 push 0
// 008e5b0d  6a00                 push 0
// 008e5b0f  50                   push eax
// 008e5b10  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5b16  5e                   pop esi
// 008e5b17  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnKillFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
