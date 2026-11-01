// from server: 100% by auto
// roc 2011-06 0085ffb0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085ffb0
//
// 0085ffb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085ffb4  85c9                 test ecx, ecx
// 0085ffb6  7503                 jne 0x85ffbb
// 0085ffb8  33c0                 xor eax, eax
// 0085ffba  c3                   ret 
// 0085ffbb  8b01                 mov eax, dword ptr [ecx]
// 0085ffbd  8b4058               mov eax, dword ptr [eax + 0x58]
// 0085ffc0  8d542410             lea edx, [esp + 0x10]
// 0085ffc4  52                   push edx
// 0085ffc5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ffc9  52                   push edx
// 0085ffca  8b542410             mov edx, dword ptr [esp + 0x10]
// 0085ffce  6a0b                 push 0xb
// 0085ffd0  52                   push edx
// 0085ffd1  ffd0                 call eax
// 0085ffd3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Bool@@YAHPAVCXTPPropExchange@@PBDAAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
