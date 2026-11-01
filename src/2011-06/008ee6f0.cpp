// from server: 100% by auto
// roc 2011-06 008ee6f0  unit: CXTColorSelectorCtrl  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ee6f0
//
// 008ee6f0  8b01                 mov eax, dword ptr [ecx]
// 008ee6f2  8b542404             mov edx, dword ptr [esp + 4]
// 008ee6f6  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 008ee6fc  6a00                 push 0
// 008ee6fe  52                   push edx
// 008ee6ff  ffd0                 call eax
// 008ee701  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Popup\XTPColorSelectorCtrl.cpp (function ?EndSelection@CXTPColorSelectorCtrl@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Popup/XTPColorSelectorCtrl.cpp
