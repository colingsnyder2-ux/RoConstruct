// from server: 100% by auto
// roc 2010-06 00804bf0  unit: CXTCaptionButtonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804bf0
//
// 00804bf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804bf4  85c9                 test ecx, ecx
// 00804bf6  7503                 jne 0x804bfb
// 00804bf8  33c0                 xor eax, eax
// 00804bfa  c3                   ret 
// 00804bfb  8b01                 mov eax, dword ptr [ecx]
// 00804bfd  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804c00  8d542410             lea edx, [esp + 0x10]
// 00804c04  52                   push edx
// 00804c05  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c09  52                   push edx
// 00804c0a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c0e  6a64                 push 0x64
// 00804c10  52                   push edx
// 00804c11  ffd0                 call eax
// 00804c13  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Rect@@YAHPAVCXTPPropExchange@@PBDAAUtagRECT@@U2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
