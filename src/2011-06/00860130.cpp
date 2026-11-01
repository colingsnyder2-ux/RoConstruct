// from server: 100% by auto
// roc 2011-06 00860130  unit: CXTCaptionButtonTheme  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00860130
//
// 00860130  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860134  85c9                 test ecx, ecx
// 00860136  7503                 jne 0x86013b
// 00860138  33c0                 xor eax, eax
// 0086013a  c3                   ret 
// 0086013b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086013f  8b01                 mov eax, dword ptr [ecx]
// 00860141  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00860144  52                   push edx
// 00860145  8b542410             mov edx, dword ptr [esp + 0x10]
// 00860149  52                   push edx
// 0086014a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086014e  52                   push edx
// 0086014f  ffd0                 call eax
// 00860151  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Blob@@YAHPAVCXTPPropExchange@@PBDAAPAEAAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
