// from server: 100% by auto
// roc 2010-06 00804b90  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804b90
//
// 00804b90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804b94  85c9                 test ecx, ecx
// 00804b96  7503                 jne 0x804b9b
// 00804b98  33c0                 xor eax, eax
// 00804b9a  c3                   ret 
// 00804b9b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804b9f  8b01                 mov eax, dword ptr [ecx]
// 00804ba1  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804ba4  6a00                 push 0
// 00804ba6  52                   push edx
// 00804ba7  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804bab  6a07                 push 7
// 00804bad  52                   push edx
// 00804bae  ffd0                 call eax
// 00804bb0  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_DateTime@@YAHPAVCXTPPropExchange@@PBDAAVCOleDateTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
