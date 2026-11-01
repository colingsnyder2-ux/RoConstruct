// from server: 100% by auto
// roc 2011-06 00860100  unit: CXTCaptionButtonTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860100
//
// 00860100  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860104  85c9                 test ecx, ecx
// 00860106  7503                 jne 0x86010b
// 00860108  33c0                 xor eax, eax
// 0086010a  c3                   ret 
// 0086010b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086010f  8b01                 mov eax, dword ptr [ecx]
// 00860111  8b4060               mov eax, dword ptr [eax + 0x60]
// 00860114  52                   push edx
// 00860115  8b542410             mov edx, dword ptr [esp + 0x10]
// 00860119  52                   push edx
// 0086011a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086011e  52                   push edx
// 0086011f  ffd0                 call eax
// 00860121  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_RuntimeClass@@YAHPAVCXTPPropExchange@@PBDAAPAUCRuntimeClass@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
