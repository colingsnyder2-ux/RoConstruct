// from server: 100% by auto
// roc 2010-06 00804bc0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804bc0
//
// 00804bc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804bc4  85c9                 test ecx, ecx
// 00804bc6  7503                 jne 0x804bcb
// 00804bc8  33c0                 xor eax, eax
// 00804bca  c3                   ret 
// 00804bcb  8b01                 mov eax, dword ptr [ecx]
// 00804bcd  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804bd0  8d542410             lea edx, [esp + 0x10]
// 00804bd4  52                   push edx
// 00804bd5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804bd9  52                   push edx
// 00804bda  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804bde  6a65                 push 0x65
// 00804be0  52                   push edx
// 00804be1  ffd0                 call eax
// 00804be3  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Size@@YAHPAVCXTPPropExchange@@PBDAAUtagSIZE@@U2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
