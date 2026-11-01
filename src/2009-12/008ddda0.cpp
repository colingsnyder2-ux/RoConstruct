// from server: 100% by auto
// roc 2009-12 008ddda0  unit: CXTColorWnd  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ddda0
//
// 008ddda0  8b442404             mov eax, dword ptr [esp + 4]
// 008ddda4  56                   push esi
// 008ddda5  50                   push eax
// 008ddda6  8bf1                 mov esi, ecx
// 008ddda8  e8e168f1ff           call 0x7f468e
// 008dddad  6a00                 push 0
// 008dddaf  c70524bfb90001000000 mov dword ptr [0xb9bf24], 1
// 008dddb9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008dddbc  6a00                 push 0
// 008dddbe  51                   push ecx
// 008dddbf  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008dddc5  5e                   pop esi
// 008dddc6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
