// from server: 100% by auto
// roc 2010-06 008049e0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008049e0
//
// 008049e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008049e4  85c9                 test ecx, ecx
// 008049e6  7503                 jne 0x8049eb
// 008049e8  33c0                 xor eax, eax
// 008049ea  c3                   ret 
// 008049eb  8b01                 mov eax, dword ptr [ecx]
// 008049ed  8b4058               mov eax, dword ptr [eax + 0x58]
// 008049f0  8d542410             lea edx, [esp + 0x10]
// 008049f4  52                   push edx
// 008049f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008049f9  52                   push edx
// 008049fa  8b542410             mov edx, dword ptr [esp + 0x10]
// 008049fe  6a11                 push 0x11
// 00804a00  52                   push edx
// 00804a01  ffd0                 call eax
// 00804a03  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Byte@@YAHPAVCXTPPropExchange@@PBDAAEE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
