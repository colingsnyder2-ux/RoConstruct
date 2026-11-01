// from server: 100% by auto
// roc 2011-06 008600a0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008600a0
//
// 008600a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008600a4  85c9                 test ecx, ecx
// 008600a6  7503                 jne 0x8600ab
// 008600a8  33c0                 xor eax, eax
// 008600aa  c3                   ret 
// 008600ab  8b01                 mov eax, dword ptr [ecx]
// 008600ad  8b4058               mov eax, dword ptr [eax + 0x58]
// 008600b0  8d542410             lea edx, [esp + 0x10]
// 008600b4  52                   push edx
// 008600b5  8b542410             mov edx, dword ptr [esp + 0x10]
// 008600b9  52                   push edx
// 008600ba  8b542410             mov edx, dword ptr [esp + 0x10]
// 008600be  6a65                 push 0x65
// 008600c0  52                   push edx
// 008600c1  ffd0                 call eax
// 008600c3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Size@@YAHPAVCXTPPropExchange@@PBDAAUtagSIZE@@U2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
