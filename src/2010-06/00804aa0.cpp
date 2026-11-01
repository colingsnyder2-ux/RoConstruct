// from server: 100% by auto
// roc 2010-06 00804aa0  unit: CXTCaptionButtonTheme  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804aa0
//
// 00804aa0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00804aa4  85c9                 test ecx, ecx
// 00804aa6  7503                 jne 0x804aab
// 00804aa8  33c0                 xor eax, eax
// 00804aaa  c3                   ret 
// 00804aab  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804aaf  8b01                 mov eax, dword ptr [ecx]
// 00804ab1  8b4058               mov eax, dword ptr [eax + 0x58]
// 00804ab4  6a00                 push 0
// 00804ab6  52                   push edx
// 00804ab7  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804abb  6a0b                 push 0xb
// 00804abd  52                   push edx
// 00804abe  ffd0                 call eax
// 00804ac0  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PX_Bool@@YAHPAVCXTPPropExchange@@PBDAAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
