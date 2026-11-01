// from server: 100% by auto
// roc 2011-06 008600d0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008600d0
//
// 008600d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008600d4  85c9                 test ecx, ecx
// 008600d6  7503                 jne 0x8600db
// 008600d8  33c0                 xor eax, eax
// 008600da  c3                   ret 
// 008600db  8b01                 mov eax, dword ptr [ecx]
// 008600dd  8b4058               mov eax, dword ptr [eax + 0x58]
// 008600e0  8d542410             lea edx, [esp + 0x10]
// 008600e4  52                   push edx
// 008600e5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008600e9  52                   push edx
// 008600ea  8b542410             mov edx, dword ptr [esp + 0x10]
// 008600ee  6a64                 push 0x64
// 008600f0  52                   push edx
// 008600f1  ffd0                 call eax
// 008600f3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Rect@@YAHPAVCXTPPropExchange@@PBDAAUtagRECT@@U2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
