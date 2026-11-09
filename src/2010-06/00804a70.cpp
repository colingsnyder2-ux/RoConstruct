// from server: 100% by auto
// roc 2010-06 00804a70  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804a70
//
// 00804a70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804a74  85c9                 test ecx, ecx
// 00804a76  7503                 jne 0x804a7b
// 00804a78  33c0                 xor eax, eax
// 00804a7a  c3                   ret 
// 00804a7b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804a7f  8b01                 mov eax, dword ptr [ecx]
// 00804a81  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804a84  6a00                 push 0
// 00804a86  52                   push edx
// 00804a87  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804a8b  6a03                 push 3
// 00804a8d  52                   push edx
// 00804a8e  ffd0                 call eax
// 00804a90  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Long@@YAHPAVCXTPPropExchange@@PBDAAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
