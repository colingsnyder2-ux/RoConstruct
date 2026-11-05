// from server: 100% by auto
// roc 2010-06 00804c50  unit: CXTCaptionButtonTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804c50
//
// 00804c50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804c54  85c9                 test ecx, ecx
// 00804c56  7503                 jne 0x804c5b
// 00804c58  33c0                 xor eax, eax
// 00804c5a  c3                   ret 
// 00804c5b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c5f  8b01                 mov eax, dword ptr [ecx]
// 00804c61  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00804c64  52                   push edx
// 00804c65  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c69  52                   push edx
// 00804c6a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804c6e  52                   push edx
// 00804c6f  ffd0                 call eax
// 00804c71  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Blob@@YAHPAVCXTPPropExchange@@PBDAAPAEAAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
