// from server: 100% by auto
// roc 2010-06 00895b10  unit: CXTColorSelectorCtrl  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00895b10
//
// 00895b10  8b01                 mov eax, dword ptr [ecx]
// 00895b12  8b542404             mov edx, dword ptr [esp + 4]
// 00895b16  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 00895b1c  6a00                 push 0
// 00895b1e  52                   push edx
// 00895b1f  ffd0                 call eax
// 00895b21  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorSelectorCtrl.cpp (function ?EndSelection@CXTColorSelectorCtrl@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorSelectorCtrl.cpp
